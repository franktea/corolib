/**
 * @file p1400.cpp
 * @brief
 * Example with 5 coroutines.
 * coroutineI (I = 1..4) co_awaits coroutineI+1.
 * coroutine3 calls coroutine4 twice.
 * coroutine5 starts an asynchronous operation and awaits its completion.
 *
 * @author Johan Vanslembrouck (johan.vanslembrouck@capgemini.com, johan.vanslembrouck@gmail.com)
 */

#include <corolib/print.h>
#include <corolib/async_task.h>
#include <corolib/async_operation.h>

using namespace corolib;

/**
 * @brief start_operation_impl is implemented in 
 * p1400-async_operation.cpp,
 * p1402-async_operation-eventqueue.cpp,
 * p1404-async_operation-thread.cpp and
 * p1406-async_operation-immediate.cpp.
 */
void start_operation_impl(async_operation<int>* op);

async_task<int> coroutine5()
{
	print(PRI1, "coroutine5(): async_operation<int> op;\n");
    async_operation<int> op;
    print(PRI1, "coroutine5(): start_operation_impl(&op);\n");
    start_operation_impl(&op);
    print(PRI1, "coroutine5(): int v = co_await op;\n");
    int v = co_await op;
    print(PRI1, "coroutine5(): co_return v+1 = %d;\n", v + 1);
    co_return v + 1;
}

async_task<int> coroutine4()
{
    print(PRI1, "coroutine4(): async_task<int> a = coroutine5();\n");
    async_task<int> a = coroutine5();
    print(PRI1, "coroutine4(): int v = co_await a;\n");
    int v = co_await a;
    print(PRI1, "coroutine4(): co_return v+1 = %d;\n", v + 1);
    co_return v + 1;
}

async_task<int> coroutine3()
{
    print(PRI1, "coroutine3(): async_task<int> a1 = coroutine4();\n");
    async_task<int> a1 = coroutine4();
    print(PRI1, "coroutine3(): int v1 = co_await a1;\n");
    int v1 = co_await a1;

    print();
    print(PRI1, "coroutine3(): async_task<int> a2 = coroutine4();\n");
    async_task<int> a2 = coroutine4();
    print(PRI1, "coroutine3(): int v2 = co_await a2;\n");
    int v2 = co_await a2;

    print();
    print(PRI1, "coroutine3(): co_return v1+v2+1 = %d;\n", v1 + v2 + 1);
    co_return v1 + v2 + 1;
}

async_task<int> coroutine2()
{
    print(PRI1, "coroutine2(): async_task<int> a = coroutine3();\n");
    async_task<int> a = coroutine3();
    print(PRI1, "coroutine2(): int v = co_await a;\n");
    int v = co_await a;
    print(PRI1, "coroutine2(): co_return v+1 = %d;\n", v + 1);
    co_return v + 1;
}

async_task<int> coroutine1()
{
    print(PRI1, "coroutine1(): async_task<int> a = coroutine2();\n");
    async_task<int> a = coroutine2();
    print(PRI1, "coroutine1(): int v = co_await a;\n");
    int v = co_await a;
    print(PRI1, "coroutine1(): co_return v+1 = %d;\n", v + 1);
    co_return v + 1;
}