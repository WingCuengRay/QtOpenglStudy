#include "nehewidget.h"
#include "QtOpenGL/qgl.h"
#include <QtOpenGL/QGLWidget>
#include <GL/glu.h>
#include <stdio.h>

//半亮(0.5)白色环境光
GLfloat lightAmbient[4] = {0.5, 0.5, 0.5, 1.0};
//最亮漫射光
GLfloat lightDiffuse[4] = {1.0, 1.0, 1.0, 1.0};
//光源的位置，前三个为x,y,z坐标
GLfloat lightPosition[4] = {0.0, 0.0, 2.0, 0.0};


NeHeWidget::NeHeWidget(QWidget *parent,bool fs) :
    QGLWidget(parent)
{
    xRot = yRot = zRot = 0;
    zoom = -15;
    spin = 0.0;
    loop = 0;
    twinkle = false;

    setGeometry(0, 0, 640, 480);    //从左上角(0,0)开始，到右下角(640,480)
    setWindowTitle("Ray's here");

    fullscreen = fs;
    if(fullscreen)
        showFullScreen();

    //增加定时器，实现动画功能
    startTimer(5);
}

NeHeWidget::~NeHeWidget()
{}


void NeHeWidget::initializeGL()
{
    LoadGLTextures();
    glEnable(GL_TEXTURE_2D);

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

    // 光源设置
    glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
    glEnable(GL_LIGHT1);

    for(loop=0; loop<num; loop++)
    {
        star[loop].angle = 0.0;
        star[loop].dist = (float(loop)/num) * 5.0;
        star[loop].r = rand() % 256;
        star[loop].g = rand() % 256;
        star[loop].b = rand() % 256;
    }
}


void NeHeWidget::paintGL()
{
    //缺少了GL_DEPTH_BUFFER_BIT则不能正常显示
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D, texture[0]);

    for(loop=0; loop<num; loop++)
    {
        glLoadIdentity();
        glTranslatef(0.0, 0.0, zoom);
        glRotatef(tilt, 1.0, 0.0, 0.0);
        glRotatef(star[loop].angle, 0.0, 1.0, 0.0);
        glTranslatef(star[loop].dist, 0.0, 0.0);

        glRotatef(-star[loop].angle, 0.0, 1.0, 0.0);
        glRotatef(-tilt, 1.0, 0.0, 0.0);
        if(twinkle)
        {
            glColor4ub(star[num-loop-1].r, star[num-loop-1].g, star[num-loop-1].b, 255);
            glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0);     glVertex3f(-1.0, -1.0, 0.0);
            glTexCoord2f(1.0, 0.0);     glVertex3f(1.0, -1.0, 0.0);
            glTexCoord2f( 1.0, 1.0 );   glVertex3f( 1.0, 1.0, 0.0 );
            glTexCoord2f( 0.0, 1.0 );   glVertex3f( -1.0, 1.0, 0.0 );
            glEnd();
        }
        glRotatef( spin, 0.0, 0.0, 1.0 );
        glColor4ub( star[loop].r, star[loop].g, star[loop].b, 255 );
        glBegin( GL_QUADS );
          glTexCoord2f( 0.0, 0.0 ); glVertex3f( -1.0, -1.0, 0.0 );
          glTexCoord2f( 1.0, 0.0 ); glVertex3f( 1.0, -1.0, 0.0 );
          glTexCoord2f( 1.0, 1.0 ); glVertex3f( 1.0, 1.0, 0.0 );
          glTexCoord2f( 0.0, 1.0 ); glVertex3f( -1.0, 1.0, 0.0 );
        glEnd();
        spin += 0.01;
        star[loop].angle += float(loop)/num;
        star[loop].dist -= 0.01;
        if ( star[loop].dist < 0.0 )
        {
            star[loop].dist += 5.0;
            star[loop].r = rand() % 256;
            star[loop].g = rand() % 256;
            star[loop].b = rand() % 256;
        }
    }

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


void NeHeWidget::LoadGLTextures()
{
    QImage tex, buf;

    if(!buf.load("/home/ray/work/qt5/opengl/first_opengl/Star.bmp"))
    {
        qWarning("Could not read image file, using single-color instead.");
        QImage dummy(128, 128, QImage::Format_RGB32);
        dummy.fill(Qt::green);
        buf = dummy;
    }
    tex = QGLWidget::convertToGLFormat(buf);

    glGenTextures(1, texture);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, tex.width(), tex.height(), 0,
                 GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());

    return;
}



void NeHeWidget::keyPressEvent(QKeyEvent *e)
{
    switch ( e->key() )
    {
    case Qt::Key_L:
        light = !light;
        if(!light)
            glDisable(GL_LIGHTING);
        else
            glEnable(GL_LIGHTING);
        updateGL();
        break;

    case Qt::Key_PageUp:
        zoom += 0.2;
        updateGL();
        break;

    case Qt::Key_PageDown:
        zoom -= 0.2;
        updateGL();
        break;


    case Qt::Key_F2:
        fullscreen = !fullscreen;
        if ( fullscreen )
            showFullScreen();
        else
            showNormal();
        updateGL();
        break;

    case Qt::Key_Escape:
        close();
        break;

    case Qt::Key_T:
        twinkle = !twinkle;
        updateGL();
        break;

    }
}


void NeHeWidget::timerEvent(QTimerEvent *)
{
    updateGL();
}
