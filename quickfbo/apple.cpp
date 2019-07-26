#include "apple.h"
#include <QDebug>

Apple::Apple()
{
    initializeOpenGLFunctions();
}

void Apple::initData()
{
    float vertex[] = {
        -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
        1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
    };

    buffer.create();
    buffer.bind();
    buffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    buffer.allocate(vertex, sizeof(float)*20);
    buffer.release();

    QImage image(":/apple.svg");
    qDebug() << image.width() << image.height();
    m_pTexture = new QOpenGLTexture(image);
    m_pTexture->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    m_pTexture->setMagnificationFilter(QOpenGLTexture::Linear);

    m_pShader = new QOpenGLShaderProgram;
    m_pShader->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/ver.vert");
    m_pShader->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/fra.frag");
    m_pShader->link();
    m_pShader->bindAttributeLocation("qt_Vertex", 0);
    m_pShader->bindAttributeLocation("qt_MultiTexCoord0", 1);
}

void Apple::render()
{
    glClearColor(0.0f, 1.0f, 1.0f, 0.2f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    buffer.bind();
    m_pShader->bind();

    QMatrix4x4 model;
    model.setToIdentity();
    QMatrix4x4 view;
    view.setToIdentity();
    view.lookAt(QVector3D(0.0f, 0.0f, cameraPosZ),
                QVector3D(0.0f, 0.0f, 0.0f),
                QVector3D(0.0f, 1.0f, 0.0f));

    QMatrix4x4 pro;
    pro.setToIdentity();
    // 宽高比 依据item / view 大小
    pro.perspective(90.0f, viewW/viewH, 0.1f, 1000.0f);


    static int rota =  0;
    if(turn){
        rota += 1;
    }
    int ret = rota%360;
    model.rotate(ret, QVector3D(0.0f, 1.0f, 0.0f));

    QMatrix4x4 mvp = pro * view * model;

    m_pShader->setUniformValue("qt_ModelViewProjectionMatrix", mvp);
    m_pShader->setUniformValue("qt_Texture0", 0);
    m_pShader->enableAttributeArray(0);
    m_pShader->enableAttributeArray(1);
    m_pShader->setAttributeBuffer(0, GL_FLOAT, 0, 3, sizeof(float)*5);
    m_pShader->setAttributeBuffer(1, GL_FLOAT, sizeof(float)*3, 2, sizeof(float)*5);

    m_pTexture->bind();

    glDrawArrays(GL_QUADS, 0, 4);

    m_pTexture->release();

    m_pShader->release();
    buffer.release();
}

void Apple::setCameraPosZ(float posZ)
{
    cameraPosZ = posZ;
}

void Apple::setTurn(bool t)
{
    turn = t;
}

void Apple::setViewWH(float w, float h)
{
    viewW = w;
    viewH = h;
}
