/*
 * NTUCSIE ICG2010
 * R99922020 Yu-Hsiang Huang
 */

#include <QtOpenGL>
#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
    QGLWidget(parent)
{
    ctrlPressed = false;
    model = NULL;
    camera = NULL;
    lights = NULL;
}

GLWidget::~GLWidget()
{
    delete model;
    delete camera;
    for(int i = 0; i < 8; i++)
        delete lights[i];
    delete [] lights;
    delete phongShader;
    delete blinnPhongShader;
}

QSize GLWidget::minimumSizeHint() const
{
    return sizeHint();
}

QSize GLWidget::sizeHint() const
{
    return QSize(800, 800);
}

Model *GLWidget::getModel() const
{
    return model;
}

Camera *GLWidget::getCamera() const
{
    return camera;
}
Light **GLWidget::getLights() const
{
    return lights;
}

bool GLWidget::loadModel(const QString &filename)
{
    char tmp[100] = {0};
    for(int i = 0; i < filename.size(); i++)
        tmp[i] = filename[i].toAscii();
    return model->loadFromFile(tmp);
}

void GLWidget::changeShader(int mode)
{
    switch(mode) {
        default:
        case FLAT_SHADING:
            phongShader->release();
            blinnPhongShader->release();
            glShadeModel(GL_FLAT);
            break;
        case GOURAUD_SHADING:
            phongShader->release();
            blinnPhongShader->release();
            glShadeModel(GL_SMOOTH);
            break;
        case PHONG_SHADING:
            glShadeModel(GL_SMOOTH);  // dummy
            phongShader->bind();
            break;
        case BLINN_PHONG_SHADING:
            glShadeModel(GL_SMOOTH);  // dummy
            blinnPhongShader->bind();
            break;
    }
    shadingMode = (ShadingMode)mode;

    // refresh glwidget
    updateGL();
}

void GLWidget::initPhongShader()
{
    QGLShader *vshader = new QGLShader(QGLShader::Vertex);
    vshader->compileSourceFile("shaders/phong.vs");
    QGLShader *fshader = new QGLShader(QGLShader::Fragment);
    fshader->compileSourceFile("shaders/phong.fs");

    phongShader = new QGLShaderProgram;
    phongShader->addShader(vshader);
    phongShader->addShader(fshader);
    phongShader->link();
}

void GLWidget::initBlinnPhongShader()
{
    QGLShader *vshader = new QGLShader(QGLShader::Vertex);
    vshader->compileSourceFile("shaders/blinnPhong.vs");
    QGLShader *fshader = new QGLShader(QGLShader::Fragment);
    fshader->compileSourceFile("shaders/blinnPhong.fs");

    blinnPhongShader = new QGLShaderProgram;
    blinnPhongShader->addShader(vshader);
    blinnPhongShader->addShader(fshader);
    blinnPhongShader->link();
}

void GLWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);

    // model & material
    model = new Model;
    model->loadFromFile("models/balls.tri");
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    emit modelInitialized();

    // camera
    camera = new Camera;
    emit cameraInitialized();

    // lights
    glEnable(GL_LIGHTING);
    lights = new Light *[8];
    for(int i = 0; i < 8; i++)
        lights[i] = new Light(GL_LIGHT0 + i);
    emit lightInitialized(0);

    // shaders
    initPhongShader();
    initBlinnPhongShader();
    shadingMode = FLAT_SHADING;
    glShadeModel(GL_FLAT);
}

void GLWidget::resizeGL(int width, int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0,  width, height);
    gluPerspective(60.0, 1.0 * width / height, 0.1, 10000.0);

    glMatrixMode(GL_MODELVIEW);
}

void GLWidget::paintGL()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // setup the camera
    gluLookAt(camera->position.x, camera->position.y, camera->position.z,
              camera->lookAt.x,   camera->lookAt.y,   camera->lookAt.z,
              camera->up.x,       camera->up.y,       camera->up.z);

    // setup the lights
    char tmps[15];
    for(int i = 0; i < 8; i++) {
        if(lights[i]->isOn) {
            lights[i]->updatePosition();
            lights[i]->updateColor();
            lights[i]->updateAttenuation();
            glEnable(GL_LIGHT0 + i);
            if(shadingMode == PHONG_SHADING || shadingMode == BLINN_PHONG_SHADING) {
                sprintf(tmps, "lightIsOn[%d]", i);
                if(shadingMode == PHONG_SHADING)
                    phongShader->setUniformValue(tmps, 1);
                else
                    blinnPhongShader->setUniformValue(tmps, 1);
            }
        }
        else {
            glDisable(GL_LIGHT0 + i);
            if(shadingMode == PHONG_SHADING || shadingMode == BLINN_PHONG_SHADING) {
                sprintf(tmps, "lightIsOn[%d]", i);
                if(shadingMode == PHONG_SHADING)
                     phongShader->setUniformValue(tmps, 0);
                else
                     blinnPhongShader->setUniformValue(tmps, 0);
            }
        }
    }

    // setup model
    glMultMatrixf(model->rotate.m);
    model->updateMaterial();
    model->drawModel(1);
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if(event->buttons() & Qt::LeftButton) {
        if(ctrlPressed) {
            model->updateRotation(dx, 1.0, 0.0, 0.0);
            model->updateRotation(dy, 0.0, 1.0, 0.0);
            model->rotAngle.x += dx;
            model->rotAngle.y += dy;
            updateGL();
            emit modelInitialized();
        }
        else {
            camera->updateRevolution(camera->revAngle.x - 0.5 * dx, 1, 0, 0);
            camera->updateRevolution(camera->revAngle.y + 0.5 * dy, 0, 1, 0);
            updateGL();
            emit cameraInitialized();
        }
    }
    else if(event->buttons() & Qt::RightButton) {
        if(ctrlPressed) {
            model->updateRotation(dy, 0.0, 1.0, 0.0);
            model->updateRotation(dx, 0.0, 0.0, 1.0);
            model->rotAngle.y += dy;
            model->rotAngle.z += dx;
            updateGL();
            emit modelInitialized();
        }
        else {
            camera->lookAtDist += dy;
            if(camera->lookAtDist < 0)
                camera->lookAtDist = 0;
            else if(camera->lookAtDist > 1500)
                camera->lookAtDist = 1500;
            camera->updateRevolution(0, 0, 0, 0);
            updateGL();
            emit cameraInitialized();
        }
    }

    lastPos = event->pos();
}

void GLWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Control)
        ctrlPressed = true;
}

void GLWidget::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Control)
        ctrlPressed = false;
}
