#ifndef APPLE_H
#define APPLE_H

#include <QOpenGLFunctions>
#include <QVector3D>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>
#include <QOpenGLBuffer>
#include <QImage>

class Apple: public QOpenGLFunctions
{
public:
    Apple();

    void initData();
    void render();

    void setCameraPosZ(float posZ);
    void setTurn(bool t);
    void setViewWH(float w, float h);

private:
    QOpenGLShaderProgram *m_pShader;
    QOpenGLTexture *m_pTexture;
    QOpenGLBuffer buffer;

    float cameraPosZ = 0.0f;
    bool turn = true;
    float viewW;
    float viewH;
};

#endif // APPLE_H
