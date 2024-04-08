#include <zmq.hpp>
#include <string>
#include <iostream>
#include <thread>

using namespace std;
using namespace zmq;

int main()
{
    context_t zmq_context = context_t();
    socket_t zmq_send_socket = socket_t(zmq_context, ZMQ_PUSH);
    zmq_send_socket.bind("tcp://localhost:5001");

    string msg = "Hello";
    for (int i = 0; i < 3; i++)
    {
        message_t send_message(msg);
        cout << "Now sending -> " << send_message << endl;
        zmq_send_socket.send(send_message, send_flags::none);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    zmq_ctx_destroy(&zmq_context);
}