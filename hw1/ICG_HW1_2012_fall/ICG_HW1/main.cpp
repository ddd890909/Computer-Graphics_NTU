/* 
NTU CSIE ICG2012
R01944040 Liu Chengyin
*/

#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
#include "TRIModel.h"

#include "utils.h"
#include "scene.h"

using namespace std;

#define TRANSLATION_MODE 1
#define ROTATION_MODE 2
#define SCALING_MODE 3
#define SHEAR_MODE 4
#define CAMERA_TRANSLATION_ZOOM_MODE 5
#define CAMERA_ROTATION_MODE 6
#define CAMERA_REVOLUTION_MODE 7
#define TOGGLE_CLIPPING 8
#define TOGGLE_USING_WORLD_COORD 9
#define RESET 0

Camera camera;
TRIModel model;
int mode;
bool useWorldCoordinate;
Matrix4x4 mModelView;
int windowWidth; 
int	windowHeight;

bool doClipping;
int xMin, xMax, yMin, yMax, zMin, zMax;
Matrix4x4 mProjection;

void initClipping() 
{
	doClipping = true;
	printf("Enable clipping\n");
	xMin = -300, xMax = 300, yMin = -250, yMax = 250, zMin = -400, zMax = 400;
}

void loadModel()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	model.loadFromFile("models/teapot.tri");
	mode = 1;//translation
	printf("Current mode: translation\n");
	useWorldCoordinate = true;
	printf("Using world coordinate\n");

	initClipping();
	model.initTransform();
	camera.initTransform();
}

bool clipping(int axis, float max, float min, Vector &p1, Vector &p2, bool *intersectP1, bool *intersectP2) 
{
	if((p1[axis] < min && p2[axis] < min) || (p1[axis] > max && p2[axis] > max)) 
	{
		// dont draw
		return false;
	}
	else {
		Vector pt;
		// check for intersection
		if(p1[axis] > max || p2[axis] > max) 
		{
			float t = (max - p1[axis]) / (p2[axis] - p1[axis]);
			pt = p1 * (1.0 - t) + p2 * t;
			if(p2[axis] > p1[axis]) {
				*intersectP2 = true;
				p2 = pt;
			}
			else {
				*intersectP1 = true;
				p1 = pt;
			}
		}
		if(p1[axis] < min || p2[axis] < min) {
			float t = (min - p1[axis]) / (p2[axis] - p1[axis]);
			pt = p1 * (1.0 - t) + p2 * t;
			if(p2[axis] < p1[axis]) {
				*intersectP2 = true;
				p2 = pt;
			}
			else {
				*intersectP1 = true;
				p1 = pt;
			}
		}
	}
	return true;
}

void drawModelClipping() 
{
	Matrix4x4 invModelView;
	Matrix4x4 invProjection; 
	Matrix4x4 invPM;
	invModelView = mModelView.invert();
	invProjection = mProjection.invert();
	invPM = invModelView.mul(invProjection);  // (P * M)^-1 = M^-1 * P^-1
	
	vector<Vector> intersect;
	glBegin(GL_LINES);
	for(unsigned int i = 0; i < model.triangleList.size(); i++) 
	{
		Triangle tri = model.triangleList[i];
		// set color
		glColor3fv(tri.frontColor.vec());
		// draw the model using lines
		for(int j = 0; j < 3; j++) {			
			Vector p1, p2;
			bool intersectP1 = false, intersectP2 = false;
			
			//clipZ
			p1 = mModelView.mul(tri.vertex[j]);
			p2 = mModelView.mul(tri.vertex[(j + 1) % 3]);
			p1.z += camera.lookAtDist;
			p2.z += camera.lookAtDist;
			if(!clipping(2, zMax, zMin, p1, p2, &intersectP1, &intersectP2))
				continue;
			p1.z -= camera.lookAtDist;
			p2.z -= camera.lookAtDist;
			
			// clipX & Y
			p1 = mProjection.mul(p1);
			p2 = mProjection.mul(p2);				
			if(!clipping(0, 2.0 * xMax / windowWidth, 2.0 * xMin / windowWidth, p1, p2, &intersectP1, &intersectP2))
				continue;
			if(!clipping(1, 2.0 * yMax / windowHeight, 2.0 * yMin / windowHeight, p1, p2, &intersectP1, &intersectP2))
				continue;
			
			p1 = invPM.mul(p1);
			p2 = invPM.mul(p2);
			// save intersections
			if(intersectP1)
				intersect.push_back(p1);
			if(intersectP2) 
				intersect.push_back(p2);

			glVertex3fv(p1.vec());
			glVertex3fv(p2.vec());
		}
	}
	glEnd();
	
	// hightlight intersections
	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glPointSize(4);
	glBegin(GL_POINTS);
	for(unsigned int i = 0; i < intersect.size(); i++) 
		glVertex3fv(intersect[i].vec());
	glEnd();
	glPopMatrix();
}

void display()
{
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);

	/** Todo: Create your own affine transformation matrix here*/
	glLoadIdentity();
	// rotation 
	glMultMatrixf(camera.rotate.m);
	gluLookAt(camera.position.x, camera.position.y, camera.position.z, 
			  camera.lookAt.x,   camera.lookAt.y,   camera.lookAt.z, 
			  camera.up.x,       camera.up.y,       camera.up.z);
	
	// world coordinate
	glPushMatrix();	
	
	glBegin(GL_LINES);	
	    // x axis
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(500.0, 0.0, 0.0);
		// y axis
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 500.0, 0.0);
		// z axis
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 500.0);	
	glEnd();

	glPopMatrix();

	/** Todo: Draw Model (clipping and non-clipping version)*/

	glPushMatrix();
	//glScalef(model.scale.x, model.scale.y, model.scale.z);
	//glTranslatef(model.translate.x, model.translate.y, model.translate.z);
	
	glMultMatrixf(model.scale.m);
	glMultMatrixf(model.translate.m);

	glMultMatrixf(model.shear.m);
	glMultMatrixf(model.rotate.m);
	glGetFloatv(GL_MODELVIEW_MATRIX, mModelView.m);
	model.drawAxes();
	model.drawBox();
	
	if(doClipping) 
		drawModelClipping();
	else
		model.drawModel();
	
	glPopMatrix();
    
	// clipping field
	if(doClipping)
	{
		glPushMatrix(); 
		glLoadIdentity(); 
		glMatrixMode(GL_PROJECTION); 
		glPushMatrix(); 
		glLoadIdentity();
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_QUADS); 
			glVertex3f(2.0 * xMin / windowWidth, 2.0 * yMin / windowHeight, -1.0); 
			glVertex3f(2.0 * xMax / windowWidth, 2.0 * yMin / windowHeight, -1.0); 
			glVertex3f(2.0 * xMax / windowWidth, 2.0 * yMax / windowHeight, -1.0); 
			glVertex3f(2.0 * xMin / windowWidth, 2.0 * yMax / windowHeight, -1.0); 
		glEnd();
		glPopMatrix(); 
		glMatrixMode(GL_MODELVIEW); 
		glPopMatrix(); 
	}

	glutSwapBuffers();
}

void myKeyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		/** Optional: implement some keyboard function here */
		case 27:
		  exit(0);
		  break;

		  // change mode
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
			mode = (int)(key - '0');
			printf("Current mode: %d\n", mode);
			break;
		case '8':
			mode = 8;
			doClipping = (!doClipping) ? true : false;
			printf("%s\n", (doClipping) ? "Enable clipping" : "Disable clipping");
			break;
		case '9':
			useWorldCoordinate = (!useWorldCoordinate) ? true : false;
			printf("%s\n", (useWorldCoordinate) ? "Using world coordinates" : "Not using world coordinates");
			model.initTransform();
			camera.initTransform();
			//initObjTransform();
			//initCamTransform();
			break;
		case '0':
			printf("RESET!!!\n");
			loadModel();
			break;
		// transformation
		case 'd':
			if(mode == 1)
				//model.translate.x += 10;
			    model.updateTranslate(10, 0, 0); 
			else if(mode == 2)
				model.updateRotationy(3.0, 1.0, 0.0, 0.0);
			else if(mode == 3)
				//model.scale.x += 0.1;
				model.updateScale(1.1, 1, 1); 
			else if(mode == 5) 
			{
				camera.position.x += 5;
				camera.lookAt.x += 5;
			}
			else if(mode == 6)
				camera.updateRotationy(-3.0, 1.0, 0.0, 0.0);
			break;
		case 'q':
			if(mode == 1)
				//model.translate.y += 10;
				model.updateTranslate(0, 10, 0);
			else if(mode == 2)
				model.updateRotationz(3.0, 0.0, 1.0, 0.0);
			else if(mode == 3)
				//model.scale.y += 0.1;
				model.updateScale(1, 1.1, 1); 
			else if(mode == 5) 
			{
				camera.position.y += 5;
				camera.lookAt.y += 5;
			}
			else if(mode == 6)
				camera.updateRotationz(-3.0, 0.0, 1.0, 0.0);
			break;
		case 's':
			if(mode == 1)
				//model.translate.z += 10;
				model.updateTranslate(0, 0, 10);
			else if(mode == 2)
				model.updateRotationx(3.0, 0.0, 0.0, 1.0);
			else if(mode == 3)
				//model.scale.z += 0.1;
				model.updateScale(1, 1, 1.1); 
			else if(mode == 5) 
			{
				camera.position.z += 5;
				camera.lookAt.z += 5;
			}
			else if(mode == 6)
				camera.updateRotationx(-3.0, 0.0, 0.0, 1.0);
			break;
		case 'a':
			if(mode == 1)
				//model.translate.x -= 10;
				model.updateTranslate(-10, 0, 0);
			else if(mode == 2)
				model.updateRotationy(-3.0, 1.0, 0.0, 0.0);
			else if(mode == 3)
				//model.scale.x -= 0.1;
				model.updateScale(0.9, 1, 1); 
			else if(mode == 5) 
			{
				camera.position.x -= 5;
				camera.lookAt.x -= 5;
			}
			else if(mode == 6)
				camera.updateRotationy(3.0, 1.0, 0.0, 0.0);
			break;
		case 'e':
			if(mode == 1)
				//model.translate.y -= 10;
				model.updateTranslate(0, -10, 0);
			else if(mode == 2)
				model.updateRotationz(-3.0, 0.0, 1.0, 0.0);
			else if(mode == 3)
				//model.scale.y -= 0.1;
				model.updateScale(1, 0.9, 1); 
			else if(mode == 5) 
			{
				camera.position.y -= 5;
				camera.lookAt.y -= 5;
			}
			else if(mode == 6)
				camera.updateRotationz(3.0, 0.0, 1.0, 0.0);
			break;
		case 'w':
			if(mode == 1)
				//model.translate.z -= 10;
				model.updateTranslate(0, 0, -10);
			else if(mode == 2)
				model.updateRotationx(-3.0, 0.0, 0.0, 1.0);
			else if(mode == 3)
				//model.scale.z -= 0.1;
				model.updateScale(1, 1, 0.9); 
			else if(mode == 5)
			{
				camera.position.z -= 5;
				camera.lookAt.z -= 5;
			}
			else if(mode == 6)
				camera.updateRotationx(3.0, 0.0, 0.0, 1.0);
			break;
		// zoom in/out
		case 'z':
			if(mode == 5)
				camera.lookAtDist -= 5;
			camera.updateRevolution(0, 0, 0, 0);
			break;
		case 'x':
			if(mode == 5)
				camera.lookAtDist += 5;
			camera.updateRevolution(0, 0, 0, 0);
			break;
		// shear / camera rotation around VRP
		case 't':
			if(mode == 4)
				model.updateShear(1.0, 0, 1);
			else if(mode == 7) 
				camera.updateRevolution(((int)camera.revAngle[0] + 3) % 360, 1, 0, 0);
			else if(mode == 8 && doClipping)
				xMin += 10;
			break;
		case 'y':
			if(mode == 4)
				model.updateShear(-1.0, 0, 1);
			else if(mode == 7) 
				camera.updateRevolution(((int)camera.revAngle[0] - 3) % 360, 1, 0, 0);
			else if(mode == 8 && doClipping)
				xMin -= 10;
			break;
		case 'T':
			if(mode == 4)
				model.updateShear(1.0, 0, 2);
			else if(mode == 8 && doClipping)
				xMax += 10;
			break;
		case 'Y':
			if(mode == 4)
				model.updateShear(-1.0, 0, 2);
			else if(mode == 8 && doClipping)
				xMax -= 10;
			break;
		case 'g':
			if(mode == 4)
				model.updateShear(1.0, 1, 0);
			else if(mode == 7) 
				camera.updateRevolution(((int)camera.revAngle[1] + 3) % 360, 0, 1, 0);
			else if(mode == 8 && doClipping)
				yMin += 10;
			break;
		case 'h':
			if(mode == 4)
				model.updateShear(-1.0, 1, 0);
			else if(mode == 7) 
				camera.updateRevolution(((int)camera.revAngle[1] - 3) % 360, 0, 1, 0);
			else if(mode == 8 && doClipping)
				yMin -= 10;
			break;
		case 'G':
			if(mode == 4)
				model.updateShear(1.0, 1, 2);
			else if(mode == 8 && doClipping)
				yMax += 10;
			break;
		case 'H':
			if(mode == 4)
				model.updateShear(-1.0, 1, 2);
			else if(mode == 8 && doClipping)
				yMax -= 10;
			break;
		case 'b':
			if(mode == 4)
				model.updateShear(1.0, 2, 0);
			else if(mode == 7) 
				camera.updateRevolution(((int)camera.revAngle[2] + 3) % 360, 0, 0, 1);
			else if(mode == 8 && doClipping)
				zMin += 10;
			break;
		case 'n':
			if(mode == 4)
				model.updateShear(-1.0, 2, 0);
			else if(mode == 7) 
				camera.updateRevolution(((int)camera.revAngle[2] - 3) % 360, 0, 0, 1);
			else if(mode == 8 && doClipping)
				zMin -= 10;
			break;
		case 'B':
			if(mode == 4)
				model.updateShear(1.0, 2, 1);
			else if(mode == 8 && doClipping)
				zMax += 10;
			break;
		case 'N':
			if(mode == 4)
				model.updateShear(-1.0, 2, 1);
			else if(mode == 8 && doClipping)
				zMax -= 10;
			break;
		// change model
		case ',':
			model.loadFromFile("models/Gym.tri");
			break;
		case '.':
			model.loadFromFile("models/Fighter.tri");
			break;
		case '/':
			model.loadFromFile("models/Csie.tri");
			break;
		case ';':
			model.loadFromFile("models/Easter.tri");
			break;
		case '\'':
			model.loadFromFile("models/Car_road.tri");
			break;
	}	
}

void myMouse(int button, int state, int x, int y)
{
		/** optional: implement some mouse function here */
}

void idle()
{
	glutPostRedisplay();
}

void myPerspective(float fovy, float aspect, float zNear, float zFar) 
{
	float f = 1.0 / tanf(DegToRad(fovy) / 2);
	mProjection.setIdentity();
	mProjection[0] = f / aspect;
	mProjection[5] = f;
	mProjection[10] = -(zFar + zNear) / (zFar - zNear);
	mProjection[14] = -2.0 * zFar * zNear / (zFar - zNear);
	mProjection[11] = -1.0;
	glMultMatrixf(mProjection.m);
}

void reshape(int w, int h)
{
	float ratio = (float)w/(float)h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	/** todo: Create projection matrix here*/	

	glLoadIdentity();
	myPerspective(60.0, ratio, 1, 5000.0);

}

void main(int argc, char** argv)
{
	/** Todo: Load models */

	glutInit(&argc, argv);
	windowWidth=800; 
    windowHeight=600;
	glutInitWindowSize(windowHeight, windowWidth);
	glutInitWindowPosition(500, 500);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutCreateWindow("ICG HW1¡X¡Xddd");
	
	loadModel();
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(myKeyboard);
	glutMouseFunc(myMouse);
	glutReshapeFunc(reshape);
	glutMainLoop();
}
