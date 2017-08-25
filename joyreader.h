#ifndef JOYREADER_H
#define JOYREADER_H

class JoyReader
{
public:
    bool joy_init(char *joy_path);

    enum directions{
        joy_left,
        joy_right,
        joy_down,
        joy_up,
        joy_select,
        joy_start,
        joy_a,
        joy_b,
        joy_ta,
        joy_tb,
        joy_sl,
        joy_sr,
        joy_none
    };

    directions get_buttons(void);


};

#endif // JOYREADER_H
