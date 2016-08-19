#if defined(HAVE_QT5)
#include <QtWidgets>
#else
#include <QtGui>
#endif
#include "cscene2dn.h"
#include <QFont>
#include <QPainter>
#include <cmath>


Cscene2dn::Cscene2dn(QWidget* parent) : QGLWidget(parent)
{
    //startTimer(100);
    masX1.clear();
    masX2.clear();
    masY.clear();
    masY1.clear();
    min_x = min_y = max_x = max_y = 0;
    num_ticks_x = num_ticks_y = 0;
}

void Cscene2dn::timerEvent(QTimerEvent *event) // событие таймера
{
    updateGL(); // обновление изображения
}

void Cscene2dn::initializeGL()
{
    qglClearColor(Qt::white);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
    glEnable(GL_CULL_FACE);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
}

void Cscene2dn::resizeGL(int nWidth, int nHeight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-0.07, 1.05, -0.08, 1.05, -10.0, 1.0);

    glViewport(0, 0,(GLint)nWidth, (GLint)nHeight);
}

void Cscene2dn::paintGL()
{
    QPainter painter(this);

    if(!this->parentWidget()->isHidden())
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //glMatrixMode(GL_MODELVIEW);
        //glLoadIdentity();

        if(masX1.empty()) return;

        // координатная сетка
        glColor3f(0.7f,0.7f,0.7f);
        glLineWidth(1.0f);


        for (int i = 0; i <= num_ticks_x; ++i)
        {
            float x = (float)i / (float)num_ticks_x;
            glBegin(GL_LINES);
            glVertex2f(x, -0.01f);
            glVertex2f(x, 1.0f);
            glEnd();
        }
        for (int i = 0; i <= num_ticks_y; ++i)
        {
            float y = (float)i / (float)num_ticks_y;
            glBegin(GL_LINES);
            glVertex2f(-0.01f, y);
            glVertex2f(1.0f, y);
            glEnd();
        }

        // отрисовка шкалы
        glColor3f(0.0f,0.0f,0.0f);
        glLineWidth(2.0f);
        QFont font("Courier", 8);
        for (int i = 0; i < num_ticks_x; ++i)
        {
            float x = (float)i / (float)num_ticks_x;
            float x_real = (float)(floor((x * size_x + min_x) * 1000.0 + 0.5)) / 1000.0;
            QString st = QString::number(x_real);
           painter.beginNativePainting();
           renderText(x - 0.01f, -0.06f, 0.001f, st, font);
            painter.endNativePainting();
        }
        for (int i = 0; i < num_ticks_y; ++i)
        {
            float y = (float)i / (float)num_ticks_y;
            float y_real = (float)(floor((y * size_y + min_y) * 1000.0 + 0.5)) / 1000.0;
            QString st = QString("%1").arg(y_real, 5, 'g', -1, ' ');
           // renderText(-0.1f, y - 0.01f, 0.001f, st, font);
       }

       //renderText(5.0f,num_ticks_y+5.0f,axisY,font);
      //renderText(1.01f,-0.049f, 0.001f, axisX, font);

        //отрисовка графиков
        if(NumGraph == 2 && NumberGraph == 2)
        {
            unsigned int maslength(masX2.size());

            glColor3f(1.0f,0.0f,0.0f);
            glPointSize(6);
            glBegin(GL_POINTS);
            for(unsigned int i = 0; i < maslength; i++)
            {
                glVertex3d((masX2[i]-min_x)/size_x, (masY[i]-min_y)/size_y, 0.0002);//иксы и игрек оцененный
            }
            glEnd();

            glColor3f(0.0f,0.0f,0.0f);
            glPointSize(6);
            glBegin(GL_POINTS);
            for(unsigned int i = 0; i < maslength; i++)
            {
               glVertex3d((masX2[i]-min_x)/size_x, (masY1[i]-min_y)/size_y, 0.0001);//иксы и игрек истинный
            }
            glEnd();
        }
        else
        {
            unsigned int maslength(masX1.size());

            glColor3f(1.0f,0.0f,0.0f);
            glPointSize(6);
            glBegin(GL_POINTS);
            for(unsigned int i = 0; i < maslength; i++)
            {
                glVertex3d((masX1[i]-min_x)/size_x, (masY[i]-min_y)/size_y, 0.0002);//иксы и игрек оцененный
            }
            glEnd();

            glColor3f(0.0f,0.0f,0.0f);
            glPointSize(6);
            glBegin(GL_POINTS);
            for(unsigned int i = 0; i < maslength; i++)
            {
                glVertex3d((masX1[i]-min_x)/size_x, (masY1[i]-min_y)/size_y, 0.0001);//иксы и игрек истинный
            }
            glEnd();
        }
    }
}

void Cscene2dn::adjustAxis(float & min, float & max, int & numTicks)
{
    const int MinTicks = 4;
    double grossStep = (max - min) / MinTicks;
    double step = pow(10, floor(log10(grossStep)));

    if (5 * step < grossStep)
        step *= 5;
    else if (2 * step < grossStep)
        step *= 2;

    numTicks = (int)(ceil(max / step) - floor(min / step));
    min = floor(min / step) * step;
    max = ceil(max / step) * step;
}

void Cscene2dn::precond()
{
        // Поправляем значения мин / макс чтобы влазило в сетку
        adjustAxis(min_x, max_x, num_ticks_x);
        adjustAxis(min_y, max_y, num_ticks_y);
        size_x = max_x - min_x;
        size_y = max_y - min_y;
}

