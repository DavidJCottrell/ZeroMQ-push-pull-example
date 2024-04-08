#include <zmq.hpp>
#include <string>
#include <iostream>
#include <thread>

using namespace std;
using namespace zmq;

int main()
{
    context_t zmq_context = context_t();
    socket_t zmq_recv_socket = socket_t(zmq_context, ZMQ_PULL);
    zmq_recv_socket.connect("tcp://localhost:5001");

    cout << "Waiting for messages..." << endl;
    message_t received_message;
    while (1)
    {
        auto result = zmq_recv_socket.recv(received_message, recv_flags::none);
        if (result.has_value())
            cout << received_message << endl;
    }

    zmq_ctx_destroy(&zmq_context);
}
