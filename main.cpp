#include <QApplication>
#include "animation.h"
#include "ui_animation.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList pictureList;
    pictureList << ":/pump_1" << ":/pump_2" << ":/pump_3" << ":/pump_4";

    Animation w(pictureList);
    w.show();

    QStringList pictureList2;
    pictureList2 << ":/gear_1" << ":/gear_2" << ":/gear_3" << ":/gear_4" << ":/gear_5" << ":/gear_6" << ":/gear_7" << ":/gear_8" << ":/gear_9" << ":/gear_10";

    Animation w2(pictureList2);
    w2.show();

    return a.exec();
}


