/**
 * @file p1200co.cpp
 * @brief
 *
 * @author Johan Vanslembrouck (johan.vanslembrouck@capgemini.com, johan.vanslembrouck@gmail.com)
 */
 
#include "p1200co.h"

void RemoteObject1Co::start_op1_impl(const int idx, int in1, int in2)
{
    print(PRI1, "%p: RemoteObject1Co::start_op1_impl(%d)\n", this, idx);

    m_remoteObject.sendc_op1(in1, in2, 
        [this, idx](int out1, int out2, int ret1)
        {
            print(PRI1, "%p: RemoteObject1Co::start_op1_impl(%d) - handler\n", this, idx);

            async_operation_base* om_async_operation = m_async_operations[idx];
            async_operation<op1_ret_t>* om_async_operation_t =
                static_cast<async_operation<op1_ret_t>*>(om_async_operation);

            if (om_async_operation_t)
            {
                print(PRI1, "%p: RemoteObject1Co::start_op1_impl(%d) - handler: om_async_operation_t->set_result()\n", this, idx);
                op1_ret_t op1_ret = { out1, out2, ret1 };
                om_async_operation_t->set_result(op1_ret);
                om_async_operation_t->completed();
            }
            else
            {
                // This can occur when the async_operation_base has gone out of scope.
                print(PRI1, "%p: RemoteObject1Co::start_op1_impl(%d) - handler: Warning: om_async_operation_t == nullptr\n", this, idx);
            }
         });
}

void RemoteObject1Co::start_op2_impl(const int idx, int in1, int in2)
{
    print(PRI1, "%p: RemoteObject1Co::start_op2_impl(%d)\n", this, idx);

    m_remoteObject.sendc_op2(in1, in2, 
        [this, idx](int out1, int ret1)
        {
            print(PRI1, "%p: RemoteObject1Co::start_op2_impl(%d) - handler\n", this, idx);

            async_operation_base* om_async_operation = m_async_operations[idx];
            async_operation<op2_ret_t>* om_async_operation_t =
                static_cast<async_operation<op2_ret_t>*>(om_async_operation);

            if (om_async_operation_t)
            {
                print(PRI1, "%p: RemoteObject1Co::start_op2_impl(%d) - handler: om_async_operation_t->set_result()\n", this, idx);
                op2_ret_t op2_ret = { out1, ret1 };
                om_async_operation_t->set_result(op2_ret);
                om_async_operation_t->completed();
            }
            else
            {
                // This can occur when the async_operation_base has gone out of scope.
                print(PRI1, "%p: RemoteObject1Co::start_op2_impl(%d) - handler: Warning: om_async_operation_t == nullptr\n", this, idx);
            }
        });
}

void RemoteObject1Co::start_op3_impl(const int idx, int in1)
{
    print(PRI1, "%p: RemoteObject1Co::start_op3_impl(%d)\n", this, idx);

    m_remoteObject.sendc_op3(in1, 
        [this, idx](int out1, int out2, int ret1)
        {
            print(PRI1, "%p: RemoteObject1Co::start_op3_impl(%d) - handler\n", this, idx);

            async_operation_base* om_async_operation = m_async_operations[idx];
            async_operation<op1_ret_t>* om_async_operation_t =
                static_cast<async_operation<op1_ret_t>*>(om_async_operation);

            if (om_async_operation_t)
            {
                print(PRI1, "%p: RemoteObject1Co::start_op3_impl(%d) - handler: om_async_operation_t->set_result()\n", this, idx);
                op1_ret_t op1_ret = { out1, out2, ret1 };
                om_async_operation_t->set_result(op1_ret);
                om_async_operation_t->completed();
            }
            else
            {
                // This can occur when the async_operation_base has gone out of scope.
                print(PRI1, "%p: RemoteObject1Co::start_op3_impl(%d) - handler: Warning: om_async_operation_t == nullptr\n", this, idx);
            }
        });
}
