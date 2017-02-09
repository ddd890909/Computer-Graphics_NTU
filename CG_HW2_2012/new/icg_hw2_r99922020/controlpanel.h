/*
 * NTUCSIE ICG2010
 * R99922020 Yu-Hsiang Huang
 */

#ifndef CONTROLPANEL_H
#define CONTROLPANEL_H

#include <QTabWidget>
#include "glwidget.h"

namespace Ui {
    class ControlPanel;
}

class ControlPanel : public QTabWidget
{
    Q_OBJECT

public:
    ControlPanel(QWidget *parent = 0);
    ~ControlPanel();
    void setGLWidget(GLWidget *glw);

signals:
    void lightChanged();
    void modelChanged();
    void cameraChanged();

private slots:
    void updateLightColorControl(bool checked);
    void updateLightControl(int index);
    void updateModelControl();
    void updateCameraControl();
    void setLight(int /*no use*/);
    void setModel(int /*no use*/);
    void setCamera(int /*no use*/);
    void on_lightEnabled_stateChanged(int state);
    void on_lightQuadAttSlider_valueChanged(int value);
    void on_lightLinearAttSlider_valueChanged(int value);
    void on_lightConstAttSlider_valueChanged(int value);

private:
    Ui::ControlPanel *ui;
    GLWidget *glWidget;
    int currentLightIdx;
    bool initialized;
};

#endif // CONTROLPANEL_H
