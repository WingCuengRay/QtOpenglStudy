#ifndef NEHEWIDGET_H
#define NEHEWIDGET_H
#include <QtOpenGL/QGLWidget>
#include <QtGui>

const GLuint num = 50;

typedef struct
{
    int r, g, b;
    GLfloat dist;   //星星句距中心的距离
    GLfloat angle;  //星星的角度
}stars;


class NeHeWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit NeHeWidget(QWidget *parent = 0);
    NeHeWidget(QWidget *parent,bool fs);
    ~NeHeWidget();

protected:
    //设置渲染环境
    void initializeGL();
    //绘制窗口
    void paintGL();
    //响应窗口的大小变化
    void resizeGL( int width, int height );
    void LoadGLTextures();
    void keyPressEvent(QKeyEvent *e);
    void timerEvent(QTimerEvent *);

    bool fullscreen;
    bool light;
    GLfloat xRot, yRot, zRot;
    GLfloat zoom;
    GLfloat tilt;       //星星的倾角
    GLfloat spin;
    GLuint loop;
    GLuint texture[1];

    bool twinkle;		//是否闪烁
    stars star[num];
};
#endif // NEHEWIDGET_H
