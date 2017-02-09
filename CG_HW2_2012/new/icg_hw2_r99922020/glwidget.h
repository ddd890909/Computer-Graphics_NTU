/*
 * NTUCSIE ICG2010
 * R99922020 Yu-Hsiang Huang
 */

#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QGLShaderProgram>
#include "scene.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    Model *getModel() const;
    Camera *getCamera() const;
    Light **getLights() const;
    bool loadModel(const QString &filename);

    enum ShadingMode {
        FLAT_SHADING = 0,
        GOURAUD_SHADING,
        PHONG_SHADING,
        BLINN_PHONG_SHADING
    } shadingMode;

signals:
    void lightInitialized(int index);
    void modelInitialized();
    void cameraInitialized();

public slots:
    void changeShader(int mode);

protected:
    void initPhongShader();
    void initBlinnPhongShader();
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QPoint lastPos;
    bool ctrlPressed;
    Model *model;
    Camera *camera;
    Light **lights;
    QGLShaderProgram *phongShader;
    QGLShaderProgram *blinnPhongShader;
};

#endif // GLWIDGET_H
