#ifndef ROBO_PROTO_H
#define ROBO_PROTO_H

#include <stdint.h>

class Robo_proto
{
    public:
        enum directions{
            move_left,
            move_right,
            move_down,
            move_up
        };
    public:
        void move_camera(enum directions, uint8_t *send_buf);
    private:
        typedef struct
        {
            uint16_t cmd;
            uint16_t data;
        }packet_t;
};

#endif
