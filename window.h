#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QPainter>
#include <QPaintEvent>
#include <QTime>
#include <QVector>
#include <QTimer>

class Window : public QDialog
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    ~Window();

protected:
            virtual void paintEvent(QPaintEvent *event);
private:
        QVector<QPoint> points;
        QTime time;
        QTimer *timer;

private slots:
                void slot();


};

#endif // WINDOW_H
