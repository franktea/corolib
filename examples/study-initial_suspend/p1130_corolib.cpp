/**
 * @file p1130_corolib.cpp
 * @brief
 *
 * @author Johan Vanslembrouck (johan.vanslembrouck@gmail.com)
 */

#include <iostream>

#include "corolib/async_task.h"
using namespace corolib;

async_ltask<void> completes_synchronously() {
    co_return;
}

async_ltask<void> loop_synchronously(int count) {
    std::cout << "loop_synchronously(" << count << ")" << std::endl;
    for (int i = 0; i < count; ++i) {
        co_await completes_synchronously();
    }
    std::cout << "loop_synchronously(" << count << ") returning" << std::endl;
}

int main() {
    loop_synchronously(100).start();
    loop_synchronously(1000).start();
#if 0
    loop_synchronously(10'000).start();
    loop_synchronously(100'000).start();
    loop_synchronously(1'000'000).start();
#endif
    return 0;
}
