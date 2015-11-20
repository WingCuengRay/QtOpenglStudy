#include "nehewidget.h"
#include "QtOpenGL/qgl.h"
#include <QtOpenGL/QGLWidget>
#include <GL/glu.h>

NeHeWidget::NeHeWidget(QWidget *parent,bool fs) :
    QGLWidget(parent)
{
    rTri = 0.0;
    rQuad = 0.0;
    fullscreen = fs;
    setGeometry(0, 0, 640, 480);    //从左上角(0,0)开始，到右下角(640,480)

    if(fullscreen)
        showFullScreen();
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

    glTranslatef(-1.5, 0.0, -6.0);    //将绘制点向屏幕左偏移1.5个单位，向屏幕深处移入6个单位
//    glRotatef(90, 0.0, 1.0, 0.0);
    glRotatef(rTri, 0.0, 1.0, 0.0);
//  glRotatef( Angle, Xvector, Yvector, Zvector )
//  后三个参数确定一个向量，此为旋转的中心。 Angle确定旋转的角度，0~360
                                      //原本的绘制点是在屏幕中心(0,0)处的
    glBegin(GL_TRIANGLES);

    glColor3f(1.0, 0.0, 0.0);   //三个参数分别代表红，绿，蓝
                                //1最亮， 0最暗
    glVertex3f(0.0, 1.0, 0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, 1);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, -1.0, 1);

    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(1.0, -1.0, -1.0);

    glColor3f( 1.0, 0.0, 0.0 );
    glVertex3f(  0.0,  1.0,  0.0 );
    glColor3f( 0.0, 1.0, 0.0 );
    glVertex3f(  1.0, -1.0, -1.0 );
    glColor3f( 0.0, 0.0, 1.0 );
    glVertex3f( -1.0, -1.0, -1.0 );

    glColor3f( 1.0, 0.0, 0.0 );
     glVertex3f(  0.0,  1.0,  0.0 );
     glColor3f( 0.0, 0.0, 1.0 );
     glVertex3f( -1.0, -1.0, -1.0 );
     glColor3f( 0.0, 1.0, 0.0 );
     glVertex3f( -1.0, -1.0,  1.0 );

    glEnd();
    //每个顶点都有不同的颜色，因此看起来颜色是从每个角喷出来的

    glLoadIdentity();         //如果没有此函数充值观察模型，会出现意料之外的情况
    glTranslatef(1.5, 0.0, -6.0);
    glRotatef(rQuad, 1.0, 0.0, 0.0);

    //前面最后设置为了蓝色，所以下面的正方形会是纯蓝色的
    glBegin(GL_QUADS);
    //注意4个顶点的顺序要按照逆时针的顺序。

    //顶面
    glColor3f(0, 1.0, 0);
    glVertex3f(  1.0,   1.0,    -1.0);
    glVertex3f( -1.0,   1.0,    -1.0);
    glVertex3f( -1.0,   1.0,     1.0);
    glVertex3f(  1.0,   1.0,     1.0);

    //底面
    glColor3f(1.0, 0.5, 0.0);
    glVertex3f(1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);

    //前面
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, -1.0, 1.0);
    glVertex3f(1.0, -1.0, 1.0);

    //后面
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f(1.0, 1.0, -1.0);
    glVertex3f(1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, 1.0, -1.0);

    //左面
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-1.0, 1.0, 1.0);
    glVertex3f(-1.0, 1.0, -1.0);
    glVertex3f(-1.0, -1.0, -1.0);
    glVertex3f(-1.0, -1.0, 1.0);

    //右面
    glColor3f( 1.0, 0.0, 1.0 );
    glVertex3f(  1.0,  1.0, -1.0 );
    glVertex3f(  1.0,  1.0,  1.0 );
    glVertex3f(  1.0, -1.0,  1.0 );
    glVertex3f(  1.0, -1.0, -1.0 );


    glEnd();

    rTri += 0.2;
    rQuad -= 0.15;
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
