#include "nehewidget.h"
#include "QtOpenGL/qgl.h"
#include <QtOpenGL/QGLWidget>
#include <GL/glu.h>

NeHeWidget::NeHeWidget(QWidget *parent) :
    QGLWidget(parent)
{
}

NeHeWidget::~NeHeWidget()
{}


void NeHeWidget::initializeGL()
{
     // 启用阴影平滑
    glShadeModel( GL_SMOOTH );
    // 黑色背景
    glClearColor( 0.0, 0.0, 0.0, 0.0 );
    // 设置深度缓存
    glClearDepth( 1.0 );
     // 启用深度测试
    glEnable( GL_DEPTH_TEST );
    // 所作深度测试的类型
    glDepthFunc( GL_LEQUAL );
    // 告诉系统对透视进行修正
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
}



void NeHeWidget::paintGL()
{
    //缺少了GL_DEPTH_BUFFER_BIT则不能正常显示
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
                                      //原本的绘制点是在屏幕中心(0,0)处的
    glTranslatef(-1.5, 0.0, -6.0);    //将绘制点向屏幕左偏移1.5个单位，向屏幕深处移入6个单位
    glBegin(GL_TRIANGLES);
//    glVertex3f(0.0, 1.0, 0.0);
//    glVertex3f(-1.0, -1.0, 0.0);
//    glVertex3f(1.0, -1.0, 0.0);
    glVertex3f(0.0, 0.0, 0);
    glVertex3f(1.0, 0.0, 0);
    glVertex3f(1.0, 1.0, 0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-1.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glVertex3f(-1.0, -1.0, 0.0);
    glEnd();

}
 // 重置OpenGL窗口大小
void NeHeWidget::resizeGL(int width, int height)
{
        // 防止窗口大小变为0
    if ( height == 0 )
    {
        height = 1;
    }
    // 重置当前的视口
    glViewport( 0, 0, (GLint)width, (GLint)height );
    // 选择投影矩阵
    glMatrixMode( GL_PROJECTION );
        // 重置投影矩阵
    glLoadIdentity();
    // 设置视口的大小
    gluPerspective( 45.0, (GLfloat)width/(GLfloat)height, 0.1, 100.0 );
    // 选择模型观察矩阵
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}
