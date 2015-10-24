#ifndef DATA_H_YCLFWDS9
#define DATA_H_YCLFWDS9

#include <mutex>

#include "lines.h"

class Data {
public:
    Lines lines;

    mutable std::mutex mutex;
};

#endif /* end of include guard: DATA_H_YCLFWDS9 */

