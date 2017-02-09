/*
 * NTUCSIE ICG2010
 * R99922020 Yu-Hsiang Huang
 */

#include "controlpanel.h"
#include "ui_controlpanel.h"
#include "scene.h"

ControlPanel::ControlPanel(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::ControlPanel)
{
    ui->setupUi(this);

    // light list
    connect(ui->lightList, SIGNAL(currentIndexChanged(int)), this, SLOT(updateLightControl(int)));
    connect(ui->lightEnabled, SIGNAL(stateChanged(int)), this, SLOT(setLight(int)));
    // light position
    connect(ui->lightDistPosSlider, SIGNAL(valueChanged(int)), ui->lightDistPosValue, SLOT(display(int)));
    connect(ui->lightXPosSlider, SIGNAL(valueChanged(int)), ui->lightXPosValue, SLOT(display(int)));
    connect(ui->lightYPosSlider, SIGNAL(valueChanged(int)), ui->lightYPosValue, SLOT(display(int)));
    connect(ui->lightDistPosSlider, SIGNAL(valueChanged(int)), this, SLOT(setLight(int)));
    connect(ui->lightXPosSlider, SIGNAL(valueChanged(int)), this, SLOT(setLight(int)));
    connect(ui->lightYPosSlider, SIGNAL(valueChanged(int)), this, SLOT(setLight(int)));
    // light attenuation
    connect(ui->lightConstAttSlider, SIGNAL(valueChanged(int)), this, SLOT(setLight(int)));
    connect(ui->lightLinearAttSlider, SIGNAL(valueChanged(int)), this, SLOT(setLight(int)));
    connect(ui->lightQuadAttSlider, SIGNAL(valueChanged(int)), this, SLOT(setLight(int)));
    // light color
    connect(ui->lightSpecular, SIGNAL(clicked(bool)), this, SLOT(updateLightColorControl(bool)));
    connect(ui->lightDiffuse, SIGNAL(clicked(bool)), this, SLOT(updateLightColorControl(bool)));
    connect(ui->lightAmbient, SIGNAL(clicked(bool)), this, SLOT(updateLightColorControl(bool)));
    connect(ui->lightRedSlider, SIGNAL(valueChanged(int)), ui->lightRedValue, SLOT(display(int)));
    connect(ui->lightGreenSlider, SIGNAL(valueChanged(int)), ui->lightGreenValue, SLOT(display(int)));
    connect(ui->lightBlueSlider, SIGNAL(valueChanged(int)), ui->lightBlueValue, SLOT(display(int)));
    connect(ui->lightRedSlider, SIGNAL(valueChanged(int)), this, SLOT(setLight(int)));
    connect(ui->lightGreenSlider, SIGNAL(valueChanged(int)), this, SLOT(setLight(int)));
    connect(ui->lightBlueSlider, SIGNAL(valueChanged(int)), this, SLOT(setLight(int)));
    // model & material
    connect(ui->modelXPosSlider, SIGNAL(valueChanged(int)), ui->modelXPosValue, SLOT(display(int)));
    connect(ui->modelYPosSlider, SIGNAL(valueChanged(int)), ui->modelYPosValue, SLOT(display(int)));
    connect(ui->modelZPosSlider, SIGNAL(valueChanged(int)), ui->modelZPosValue, SLOT(display(int)));
    connect(ui->materialShininessSlider, SIGNAL(valueChanged(int)), ui->materialShininessValue, SLOT(display(int)));
    connect(ui->modelXPosSlider, SIGNAL(valueChanged(int)), this, SLOT(setModel(int)));
    connect(ui->modelYPosSlider, SIGNAL(valueChanged(int)), this, SLOT(setModel(int)));
    connect(ui->modelZPosSlider, SIGNAL(valueChanged(int)), this, SLOT(setModel(int)));
    connect(ui->materialShininessSlider, SIGNAL(valueChanged(int)), this, SLOT(setModel(int)));
    // camera
    connect(ui->cameraDistPosSlider, SIGNAL(valueChanged(int)), ui->cameraDistPosValue, SLOT(display(int)));
    connect(ui->cameraXPosSlider, SIGNAL(valueChanged(int)), ui->cameraXPosValue, SLOT(display(int)));
    connect(ui->cameraYPosSlider, SIGNAL(valueChanged(int)), ui->cameraYPosValue, SLOT(display(int)));
    connect(ui->cameraDistPosSlider, SIGNAL(valueChanged(int)), this, SLOT(setCamera(int)));
    connect(ui->cameraXPosSlider, SIGNAL(valueChanged(int)), this, SLOT(setCamera(int)));
    connect(ui->cameraYPosSlider, SIGNAL(valueChanged(int)), this, SLOT(setCamera(int)));
}

ControlPanel::~ControlPanel()
{
    delete ui;
}

void ControlPanel::setGLWidget(GLWidget *glw)
{
    glWidget = glw;
    // light
    connect(glw, SIGNAL(lightInitialized(int)), this, SLOT(updateLightControl(int)));
    connect(this, SIGNAL(lightChanged()), glw, SLOT(updateGL()));
    // model
    connect(glw, SIGNAL(modelInitialized()), this, SLOT(updateModelControl()));
    connect(this, SIGNAL(modelChanged()), glw, SLOT(updateGL()));
    // camera
    connect(glw, SIGNAL(cameraInitialized()), this, SLOT(updateCameraControl()));
    connect(this, SIGNAL(cameraChanged()), glw, SLOT(updateGL()));
    // shader
    connect(ui->shaderList, SIGNAL(currentIndexChanged(int)), glw, SLOT(changeShader(int)));
}

void ControlPanel::updateLightColorControl(bool checked)
{
    initialized = false;

    if(!checked)  return;

    Light **lights = glWidget->getLights();
    Light *light = lights[currentLightIdx];
    if(ui->lightSpecular->isChecked()) {
        ui->lightRedSlider->setValue(light->specular.r * 255);
        ui->lightGreenSlider->setValue(light->specular.g * 255);
        ui->lightBlueSlider->setValue(light->specular.b * 255);
    }
    else if(ui->lightDiffuse->isChecked()) {
        ui->lightRedSlider->setValue(light->diffuse.r * 255);
        ui->lightGreenSlider->setValue(light->diffuse.g * 255);
        ui->lightBlueSlider->setValue(light->diffuse.b * 255);
    }
    else {
        ui->lightRedSlider->setValue(light->ambient.r * 255);
        ui->lightGreenSlider->setValue(light->ambient.g * 255);
        ui->lightBlueSlider->setValue(light->ambient.b * 255);
    }

    initialized = true;
}

void ControlPanel::updateLightControl(int index)
{
    initialized = false;

    Light **lights = glWidget->getLights();
    Light *light = lights[index];
    currentLightIdx = index;
    // on or off
    if(light->isOn)
        ui->lightEnabled->setCheckState(Qt::Checked);
    else
        ui->lightEnabled->setCheckState(Qt::Unchecked);
    // position
    ui->lightDistPosSlider->setValue(light->dist);
    ui->lightXPosSlider->setValue(light->revAngle.x);
    ui->lightYPosSlider->setValue(light->revAngle.y);
    // attenuation
    ui->lightConstAttSlider->setValue(light->constAtt * 10);
    ui->lightLinearAttSlider->setValue(light->linearAtt * 1000);
    ui->lightQuadAttSlider->setValue(light->quadAtt * 1000000);
    // color
    updateLightColorControl(true);

    initialized = true;
}

void ControlPanel::updateModelControl()
{
    initialized = false;

    Model *model = glWidget->getModel();
    ui->modelXPosSlider->setValue(model->rotAngle.x);
    ui->modelYPosSlider->setValue(model->rotAngle.y);
    ui->modelZPosSlider->setValue(model->rotAngle.z);
    ui->materialShininessSlider->setValue(model->shininess);

    initialized = true;
}


void ControlPanel::updateCameraControl()
{
    initialized = false;

    Camera *camera = glWidget->getCamera();
    ui->cameraDistPosSlider->setValue(camera->lookAtDist);
    ui->cameraXPosSlider->setValue(camera->revAngle.x);
    ui->cameraYPosSlider->setValue(camera->revAngle.y);

    initialized = true;
}

void ControlPanel::setLight(int /*no use*/)
{
    if(!initialized)    return;

    Light **lights = glWidget->getLights();
    Light *light = lights[currentLightIdx];
    if(ui->lightEnabled->checkState() == Qt::Checked) {
        light->isOn = true;
        // position
        light->dist = ui->lightDistPosSlider->value();
        light->updateRevolution(ui->lightXPosSlider->value(), 1, 0, 0);
        light->updateRevolution(ui->lightYPosSlider->value(), 0, 1, 0);
        // attentuation
        light->constAtt = ui->lightConstAttSlider->value() * 0.1;
        light->linearAtt = ui->lightLinearAttSlider->value() * 0.0001;
        light->quadAtt = ui->lightQuadAttSlider->value() * 0.0000001;
        // color
        if(ui->lightSpecular->isChecked()) {
            light->specular.r = (float)ui->lightRedSlider->value() / 255;
            light->specular.g = (float)ui->lightGreenSlider->value() / 255;
            light->specular.b = (float)ui->lightBlueSlider->value() / 255;
        }
        else if(ui->lightDiffuse->isChecked()) {
            light->diffuse.r = (float)ui->lightRedSlider->value() / 255;
            light->diffuse.g = (float)ui->lightGreenSlider->value() / 255;
            light->diffuse.b = (float)ui->lightBlueSlider->value() / 255;
        }
        else {
            light->ambient.r = (float)ui->lightRedSlider->value() / 255;
            light->ambient.g = (float)ui->lightGreenSlider->value() / 255;
            light->ambient.b = (float)ui->lightBlueSlider->value() / 255;
        }
    }
    else
        light->isOn = false;

    emit lightChanged();
}

void ControlPanel::setModel(int /*no use*/)
{
    if(!initialized)    return;
    Model *model = glWidget->getModel();
    model->updateRotation(ui->modelXPosSlider->value() - model->rotAngle.x, 1.0, 0.0, 0.0);
    model->updateRotation(ui->modelYPosSlider->value() - model->rotAngle.y, 0.0, 1.0, 0.0);
    model->updateRotation(ui->modelZPosSlider->value() - model->rotAngle.z, 0.0, 0.0, 1.0);
    model->rotAngle.x = ui->modelXPosSlider->value();
    model->rotAngle.y = ui->modelYPosSlider->value();
    model->rotAngle.z = ui->modelZPosSlider->value();
    model->shininess = ui->materialShininessSlider->value();
    emit modelChanged();
}

void ControlPanel::setCamera(int /*no use*/)
{
    if(!initialized)    return;
    Camera *camera = glWidget->getCamera();
    camera->lookAtDist = ui->cameraDistPosSlider->value();
    camera->updateRevolution(ui->cameraXPosSlider->value(), 1, 0, 0);
    camera->updateRevolution(ui->cameraYPosSlider->value(), 0, 1, 0);
    emit cameraChanged();
}

void ControlPanel::on_lightConstAttSlider_valueChanged(int value)
{
    ui->lightConstAttValue->display(0.1 * value);
}

void ControlPanel::on_lightLinearAttSlider_valueChanged(int value)
{
    ui->lightLinearAttValue->display(0.0001 * value);
}

void ControlPanel::on_lightQuadAttSlider_valueChanged(int value)
{
    ui->lightQuadAttValue->display(0.0000001 * value);
}

void ControlPanel::on_lightEnabled_stateChanged(int state)
{
    if(state == Qt::Unchecked) {
        ui->posGroup->setDisabled(true);
        ui->attGroup->setDisabled(true);
        ui->colorGroup->setDisabled(true);
    }
    else {
        ui->posGroup->setEnabled(true);
        ui->attGroup->setEnabled(true);
        ui->colorGroup->setEnabled(true);
    }
}
