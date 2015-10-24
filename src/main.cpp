#include <thread>

#include <QApplication>

#include "scene_window.h"

#include "data.h"
#include "algorithm.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Data data;

    Algorithm a( data );

    std::thread thread_alg( std::bind( &Algorithm::run, &a ) );

    SceneWindow w( data );
    w.show();

    auto ret = app.exec();

    a.stop();

    thread_alg.join();

    return ret;
}

