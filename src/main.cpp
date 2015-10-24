#include <QApplication>

#include "scene_window.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    SceneWindow w;
    w.show();

    return app.exec();
}

