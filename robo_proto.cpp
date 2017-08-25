#include "robo_proto.h"
#include <QByteArray>

void Robo_proto::move_camera(directions cam_directions, uint8_t *send_buf)
{
    packet_t *packet;

    packet = (packet_t *)&send_buf[1];

    send_buf[0] = '*';

    //cmd
    switch (cam_directions) {

    case move_left:
        packet->cmd = 0x4;
        break;
    case move_right:
        packet->cmd = 0x3;
        break;
    case move_down:
        packet->cmd = 0x2;
        break;
    case move_up:
        packet->cmd = 0x1;
        break;
    default:
        break;
    }

    //speed
    packet->data = 100;

    send_buf[5] = '#';
}
