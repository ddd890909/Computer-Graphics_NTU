#define PI 3.1415926536
#define toRad(x) ((x)*2*PI/360)

#include <iostream>
#include <windows.h>
#define GLUT_DISABLE_ATEXIT_HACK
#include "GL/glew.h"
#include "GL/glut.h"
#include <vector>
#include <math.h>
#include "textfile.h"
#include "TRIModel.h"

using namespace std;

void changeShader(int s);
GLuint vShader,fShader,prog;

TRIModel ballModel;
TRIModel *TRIobj;
int currentModel=1,currentShader=1;
double thita=0,phi=20,omega=1;
double viewA=0,viewB=0,dis=1000;
double ratio;
float tX=0,tY=0,tZ=0;
bool autoRot=1,disLight=1;

int ww,wh;

int timeNow,timeOld,frames=0;
float fps=0;
float LightPos[4];

class Shader
{
public:
	GLuint vShader,fShader,prog;
	int uniformLoc[4];
	Shader()
	{
	}
	~Shader()
	{
		glDetachShader(prog,vShader);
		glDetachShader(prog,fShader);
		glDeleteShader(vShader);
		glDeleteShader(fShader);
		glDeleteProgram(prog);
	}
	void load(char *vspath,char *fspath)
	{
		char *vsSource,*fsSource;
		vsSource=textFileRead(vspath);
		fsSource=textFileRead(fspath);
		vShader=glCreateShader(GL_VERTEX_SHADER);
		fShader=glCreateShader(GL_FRAGMENT_SHADER);
		const char* vsSc=vsSource;
		const char* fsSc=fsSource;
		glShaderSource(vShader,1,&vsSc,NULL);
		glShaderSource(fShader,1,&fsSc,NULL);
		free(vsSource);
		free(fsSource);
		glCompileShader(vShader);
		glCompileShader(fShader);
		prog=glCreateProgram();
		glAttachShader(prog,vShader);
		glAttachShader(prog,fShader);
		glLinkProgram(prog);
	}
	void useProgram()
	{
		glUseProgram(prog);
	}

};

Shader testS;

void printBitmapString(void *font,char *str)
{
	char *strPos=str;
	while(*strPos!=0)
	{
		glutBitmapCharacter(font,*strPos);
		strPos++;
	}
}

void reshape(int w,int h)
{
	ww=w;wh=h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(h<100)h=101;
	if(w<100)w=101;
	ratio=1.0*(w-100)/(h-100);
	glViewport(50,50,w-100,h-100);
	gluPerspective(50,ratio,1,100000);

	glMatrixMode(GL_MODELVIEW);
}

void idle()
{
	if(autoRot)
	{
		thita+=omega;
		if(thita>=360*100)thita=0;
	}
	glutPostRedisplay();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(dis*cos(toRad(viewB))*sin(toRad(viewA)),dis*sin(toRad(viewB)),dis*cos(toRad(viewB))*cos(toRad(viewA)),
		0.0,0.0,0.0,
		cos(toRad(viewB+90))*sin(toRad(viewA)),dis*sin(toRad(viewB+90)),dis*cos(toRad(viewB+90))*cos(toRad(viewA)));

	/*if(currentShader==3)
	{
		float mat[16];
		glGetFloatv(GL_MODELVIEW_MATRIX,mat);
		for(int i=0;i<4;i++)
		{
			float lpos[4]={0};
			for(int j=0;j<3;j++)
                lpos[j]=LightPos[0]*mat[0+j]+LightPos[1]*mat[4+j]+LightPos[2]*mat[8+j]+LightPos[3]*mat[12+j];

			glUniform4fv(testS.uniformLoc[i],4,lpos);
		}
	}*/

	glPushMatrix();
	glTranslatef(tX,tY,tZ);
	glRotated(phi,1,0,0);
	glRotated(thita,0,1,0);

	glBegin(GL_TRIANGLES);
	for(int i=0;i<TRIobj->triangleList.size();i++)
	{
		glColor3fv(TRIobj->triangleList[i].color);
		for(int j=0;j<3;j++)
		{
			glNormal3dv(TRIobj->triangleList[i].normal[j]);
			glVertex3dv(TRIobj->triangleList[i].vertex[j]);
		}
	}
	glEnd();
	glPopMatrix();

	frames++;
	timeNow=glutGet(GLUT_ELAPSED_TIME);
	if((timeNow-timeOld)>1000)
	{
		fps=1000.0*frames/(timeNow-timeOld);
		timeOld=timeNow;
		frames=0;
	}

	glShadeModel(GL_FLAT);
	glUseProgram(0);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glViewport(0,0,ww,wh);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0,ww,0,wh);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	if(fps<50)glColor3f(1.0,0,0);
	else glColor3f(0,1.0,0);
	char tmps[100];
	sprintf(tmps,"FPS : %.1f",fps);
	glRasterPos2i(20,wh-30);
	printBitmapString(GLUT_BITMAP_HELVETICA_18,tmps);

	glColor3f(0.8,0.9,0.9);
	sprintf(tmps,"model #%d, %d triangles",currentModel,TRIobj->triangleList.size());
	glRasterPos2i(ww/2-120,wh-40);
	printBitmapString(GLUT_BITMAP_9_BY_15,tmps);
	sprintf(tmps,"%s shading",currentShader==1?"  Flat":currentShader==2?"Gouraud":currentShader==3?" Phong":"Unknown");
	glRasterPos2i(ww/2-84,wh-23);
	printBitmapString(GLUT_BITMAP_9_BY_15,tmps);

	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glViewport(50,50,ww-100,wh-100);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	changeShader(currentShader);

	glutSwapBuffers();
}

void shaderInit()
{
	testS.load("phong.vs","phong.fs");
	//testS.uniformLoc[0]=glGetUniformLocation(testS.prog,"lightPos[0]");
	//testS.uniformLoc[1]=glGetUniformLocation(testS.prog,"lightPos[1]");
	//testS.uniformLoc[2]=glGetUniformLocation(testS.prog,"lightPos[2]");
	//testS.uniformLoc[3]=glGetUniformLocation(testS.prog,"lightPos[3]");
}

void changeShader(int s)
{
	switch(s)
	{
	case 3:
		testS.useProgram();
		break;
	case 2:
        // put your gouraud shading code here
		break;
	case 1:
		glShadeModel(GL_FLAT);
		glUseProgram(0);
		break;
	}
	currentShader=s;
}

float matA[]={0.15,0.15,0.15,1};
float matD[]={0.6,0.6,0.6,1};
float matS[]={1,1,1,1};

void materialInit()
{
	glEnable(GL_NORMALIZE);

	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,30);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,matA);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,matD);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,matS);

	glColorMaterial(GL_FRONT_AND_BACK,GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
}

void lightInit()
{
	int i = 0;
	float ambient[4],diffuse[4],specular[4];
	float cAtt,lAtt,qAtt;
	float r,alpha,beta;

	glEnable(GL_LIGHTING);

	for(int j=0;j<3;j++)
		ambient[j]=diffuse[j]=specular[j]=1;
	ambient[3]=diffuse[3]=specular[3]=1;

	r=700;
	cAtt=1;lAtt=0.0000000001;qAtt=0.0000000000001;
	alpha = 0;
	beta = 0;

	LightPos[0]=r*cos(toRad(alpha))*cos(toRad(beta));
	LightPos[1]=r*cos(toRad(alpha))*sin(toRad(beta));
	LightPos[2]=r*sin(toRad(alpha));
	LightPos[3]=1;

	glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
	glLightfv(GL_LIGHT0,GL_POSITION,LightPos);

	glLightf(GL_LIGHT0,GL_CONSTANT_ATTENUATION,cAtt);
	glLightf(GL_LIGHT0,GL_LINEAR_ATTENUATION,lAtt);
	glLightf(GL_LIGHT0,GL_QUADRATIC_ATTENUATION,qAtt);

	glEnable(GL_LIGHT0);

}

void myInit()
{
	ballModel.loadFromFile("models/balls.tri");
    TRIobj=&ballModel;

	glEnable(GL_DEPTH_TEST);
	glClearColor(0,0,0,1.0);
	glewInit();
	if(glewIsSupported("GL_VERSION_2_0"))
		printf("Ready for OpenGL 2.0\n");
	else
	{
		printf("GLSL not supported\n");
		exit(1);
	}
	//typedef bool (*PFNWGLSWAPINTERVALFARPROC)(int);
	//PFNWGLSWAPINTERVALFARPROC wglSwapIntervalEXT = 0;
	//wglSwapIntervalEXT = (PFNWGLSWAPINTERVALFARPROC)wglGetProcAddress("wglSwapIntervalEXT");
	//wglSwapIntervalEXT(1);
	shaderInit();
	changeShader(currentShader);

	materialInit();
	lightInit();

	timeNow=timeOld=glutGet(GLUT_ELAPSED_TIME);
}

void keyboard(unsigned char key,int x,int y)
{
	switch(key)
	{
	case 27:
		exit(0);
		break;
	case 's':
		changeShader((currentShader)%3+1);
		break;
	case 'a':
		autoRot^=1;
		break;
	}
}

void mouse(int button,int state,int x,int y)
{
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(60,50);
	glutInitWindowSize(900,700);
	glutCreateWindow("ICG 2010 HW2");

	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	myInit();
	glutMainLoop();

	return 0;
}
