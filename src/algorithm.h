#ifndef ALGORITHM_H_DL9ZLEXO
#define ALGORITHM_H_DL9ZLEXO

#include "data.h"

class Algorithm {
public:
    Algorithm( Data& data );

    void run();

    void stop();

protected:
    Data& data;

    bool running;

};

#endif /* end of include guard: ALGORITHM_H_DL9ZLEXO */

