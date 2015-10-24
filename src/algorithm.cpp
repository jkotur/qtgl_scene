#include "algorithm.h"

#include <chrono>
#include <thread>
#include <cmath>

Algorithm::Algorithm( Data& data )
    : data(data)
    , running(true)
{
}

void Algorithm::stop()
{
    running = false;
}

void Algorithm::run()
{
    Lines& lines = data.lines;

    for( float x = 0 ; x<10.1 ; x+=0.1 )
    {
        lines.add( x, std::sin(x) ).c.rgb( 1, 1, 1 );
    }

    int i = 0;

    while( running )
    {
        data.mutex.lock();
        lines.at( i ).c.rgb( 1, 0, 0 );
        data.mutex.unlock();

        std::this_thread::sleep_for( std::chrono::milliseconds(50) );

        data.mutex.lock();
        lines.at( i ).c.rgb( 1, 1, 1 );
        data.mutex.unlock();

        i = (i+1) % lines.size();
    }
}

