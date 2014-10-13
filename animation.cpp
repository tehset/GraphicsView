#include "animation.h"
#include "ui_animation.h"
#include <QTimer>
#include <QDebug>

Animation::Animation(QStringList paths, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Animation),
    picturesCount(paths.count())
{
    ui->setupUi(this);

    i = 0;

    stop = true;

    pause = true;

    //QGraphicsScene *scene = new QGraphicsScene(QRectF(0,0,362,267));

    //QGraphicsScene *scene = new QGraphicsScene();

    scene = new QGraphicsScene();

    for (int i = 0; i < picturesCount; i++)
    {
        pixList.append(scene->addPixmap(paths[i]));
    }

    foreach (QGraphicsPixmapItem *item, pixList)
    {
        item->setVisible(false);
    }

    this->ui->graphicsView->setScene(scene);

    start_timer();
}

Animation::~Animation()
{
    pixList.clear();
    delete ui;
}

void Animation::start_timer()
{
    timer = new QTimer(this);
    //QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
    timer->start(100);
}

void Animation::changePicture(int value)
{
    //static int i = 0;
    //static bool stop = true;
    //static bool pause = true;

    if(value == 0 && (stop || pause))
    {
        return;
    }
    if(value == 1)
    {
        stop = false;
        pause = false;
    }
    if(value == 2)
    {
        pause = true;
        return;
    }
    if(value == 3)
    {
        stop = true;
        i = 0;
    }

    foreach (QGraphicsPixmapItem *item, pixList)
    {
        item->setVisible(false);
    }

    pixList[i]->setVisible(true);
    if(!stop)
    {
        (i >= 0 && i < picturesCount-1) ? i++ : i = 0;
    }
    qDebug() << i;
}

bool Animation::eventFilter(QObject *object, QEvent *event)
{
    if(object == ui->graphicsView && event->type() == QEvent::Resize)
    {
        ui->graphicsView->ensureVisible(scene->sceneRect());
        ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);

        //ui->graphicsView->fitInView(0,0, ui->graphicsView->width(), ui->graphicsView->height(), Qt::KeepAspectRatio);
    }
    return QWidget::eventFilter(object, event);
}

void Animation::onTimeout()
{
    changePicture(0);
}

void Animation::on_animationPlay_clicked()//play
{
    changePicture(1);
}

void Animation::on_animationPause_clicked()//pause
{
    changePicture(2);
}

void Animation::on_animationStop_clicked()//stop
{
    changePicture(3);
}

void Animation::on_animationClose_clicked()//exit
{
    return;
}

void Animation::on_pushButton_clicked()
{

}
