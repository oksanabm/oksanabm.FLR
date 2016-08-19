#ifndef CSCENE2DN_H
#define CSCENE2DN_H

#include <QGLWidget>
#include <QString>
#include <QtOpenGL>
#include <vector>

using namespace std;

class Cscene2dn : public QGLWidget
{
    Q_OBJECT

protected:
    void timerEvent(QTimerEvent *event);
public:
    int NumGraph;
    int NumberGraph;
    QString axisX, axisY;
    vector<GLfloat> masX1, masX2, masY, masY1;
    float min_x, min_y, min_y_oc, max_x, max_y, max_y_oc;
    int num_ticks_x, num_ticks_y;
    float size_x, size_y, size_y1;
    void initializeGL();
    void resizeGL(int nWidth, int nHeight);
    void paintGL();
    void adjustAxis(float & min, float & max, int & numTicks);
     void adjustAxis_y(float & min1, float & min2, float & max1, float & max2, int & numTicks1, int & numTicks2);
    void precond();
    void clear();
    Cscene2dn(QWidget* parent = 0);
};

#endif // CSCENE2DN_H

