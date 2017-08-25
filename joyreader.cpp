#include "joyreader.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <linux/joystick.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <QDebug>

int fp;

bool JoyReader::joy_init(char *joy_path)
{
    fp = open(joy_path, O_RDONLY);
    if (fp < 0) {
        return false;
    }
    else {
        fcntl( fp, F_SETFL, O_NONBLOCK );
        return true;
    }
}

JoyReader::directions JoyReader::get_buttons(void)
{
    struct js_event jse;
    int16_t nbytes;

    nbytes = read(fp, &jse, sizeof(jse));
    if(nbytes > 0) {
        switch (jse.type) {
        case JS_EVENT_AXIS:
            if((jse.value == 32767) && (jse.number == 1)) {
                return joy_down;
            }
            if((jse.value == 32767) && (jse.number == 0)) {
                return joy_right;
            }
            if((jse.value == -32767) && (jse.number == 0)) {
                return joy_left;
            }
            if((jse.value == -32767) && (jse.number == 1)) {
                return joy_up;
            }
            break;
        case JS_EVENT_BUTTON:
            qDebug() << "buttons";
            break;
        default:
            break;
        }
    }
    return joy_none;
}

