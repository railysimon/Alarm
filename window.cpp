#include "window.h"

Window::Window(QWidget *parent): QDialog(parent)
{

    QPalette pal;
    pal.setColor(this->backgroundRole(), QColor(37, 37, 37));
    this->setPalette(pal);

    time = QTime::currentTime();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(slot()));
    timer->start(1000);

    for(int i=45; i<105; i++)
    {
        float angle = 2 * 3.14 * i/60;
        QPoint temp;
        temp.setX((int)(cos(angle) * 110 + width()/2));
        temp.setY((int)(sin(angle) * 110 + height()/2));
        points.push_back(temp);
    }

}

Window::~Window()
{

}

void Window::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    for(int i=0; i<60; i++) // points
    {
        painter.setPen(QPen(Qt::green, 2, Qt::SolidLine));
        if(!(i % 5)) painter.setPen(QPen(Qt::red, 3, Qt::SolidLine));
        if(!(i % 15)) painter.setPen(QPen(Qt::blue, 5, Qt::SolidLine));

        painter.drawEllipse(points[i].x(), points[i].y(), 2, 2);
    }

    painter.setPen(QPen(Qt::white, 2, Qt::SolidLine)); // second-line
    painter.drawLine(width()/2, height()/2, points[time.second()].x(), points[time.second()].y());

    painter.setPen(QPen(Qt::white, 3, Qt::SolidLine)); // minue-line
    painter.drawLine(width()/2, height()/2, points[time.minute()].x(), points[time.minute()].y());

    int temp; // hour-line
    if(time.hour() > 12) temp = (time.hour()-12)*5;
    else temp = time.hour()*5;

    painter.setPen(QPen(Qt::white, 4, Qt::SolidLine));
    painter.drawLine(width()/2, height()/2, points[temp].x(), points[temp].y());

    painter.setPen(QPen(Qt::red, 3, Qt::SolidLine)); // center
    painter.drawEllipse(width()/2, height()/2, 3, 3);

    painter.setPen(QPen(Qt::white, 3, Qt::SolidLine));
    painter.drawText(width()/2 - 25, 30, QTime::currentTime().toString("hh:mm:ss"));

    Q_UNUSED(event);
}

void Window::slot()
{
    time = QTime::currentTime();
    this->update();
}
