#ifndef ANIMATION_H
#define ANIMATION_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>


namespace Ui {
class Animation;
}

class Animation : public QWidget
{
    Q_OBJECT

private:

    Ui::Animation *ui;

    const int picturesCount;

    int i;

    bool stop;

    bool pause;

    QGraphicsScene *scene;

    QTimer *timer;

public:

    explicit Animation(QStringList paths, QWidget *parent = 0);

    ~Animation();

    QList<QGraphicsPixmapItem*> pixList;

    void start_timer();

    void changePicture(int value);

private slots:

    void onTimeout();

    void on_animationPlay_clicked();

    void on_animationPause_clicked();

    void on_animationStop_clicked();

    void on_animationClose_clicked();

    void on_pushButton_clicked();

protected:

    bool eventFilter(QObject *object, QEvent *event);

};

#endif // ANIMATION_H
