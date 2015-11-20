#ifndef NEHEWIDGET_H
#define NEHEWIDGET_H
#include <QtOpenGL/QGLWidget>
#include <QtGui>


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

    bool fullscreen;
    bool light;
    GLfloat xRot, yRot, zRot,zoom;
    GLfloat xSpeed, ySpeed;
    GLuint texture[10];
};
#endif // NEHEWIDGET_H
