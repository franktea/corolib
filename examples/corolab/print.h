/**
 *  Filename: print.h
 *  Description:
 *
 *  Tested with Visual Studio 2019.
 *
 *  Author: Johan Vanslembrouck (johan.vanslembrouck@capgemini.com, johan.vanslembrouck@gmail.com)/
 */

#pragma once

using namespace std;

#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string>
#include <thread>

/**
 * A tailored print function that first prints a logical thread id (0, 1, 2, ...)
 * before printing the original message.
 *
 */

const int PRI1 = 0x01;
const int PRI2 = 0x02;
const int PRI3 = 0x04;
const int PRI4 = 0x08;

uint64_t threadids[128];

int get_thread_number(uint64_t id)
{
    for (int i = 0; i < 128; i++)
    {
        if (threadids[i] == id)
            return i;
        if (threadids[i] == 0) {
            threadids[i] = id;
            return i;
        }
    }
    return -1;
}

int get_thread_number64(uint64_t id)
{
    for (int i = 0; i < 128; i++)
    {
        if (threadids[i] == id)
            return i;
        if (threadids[i] == 0) {
            threadids[i] = id;
            return i;
        }
    }
    return -1;
}

int get_thread_number32(uint32_t id)
{
    for (int i = 0; i < 128; i++)
    {
        if (threadids[i] == id)
            return i;
        if (threadids[i] == 0) {
            threadids[i] = id;
            return i;
        }
    }
    return -1;
}

uint64_t get_thread_id()
{
    auto id = std::this_thread::get_id();
    uint64_t* ptr = (uint64_t*)&id;
    return (uint64_t)(*ptr);
}

void print()
{
    fprintf(stderr, "\n");
}

void print(int pri, const char* fmt, ...)
{
    va_list arg;
    if (priority & pri)
    {
        char msg[512];

        va_start(arg, fmt);
#if defined(_WIN32)
        int n = vsprintf_s(msg, fmt, arg);
#else
        int n = vsprintf(msg, fmt, arg);
#endif
        va_end(arg);

        (void)n;
        int threadid = (sizeof(std::thread::id) == sizeof(uint32_t)) ?
            get_thread_number32((uint32_t)get_thread_id()) :
            get_thread_number64(get_thread_id());
        fprintf(stderr, "%02d: %s", threadid, msg);
    }
}
