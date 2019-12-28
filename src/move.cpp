#include "nxt.h"
#include "bt-conn.h"
#include <iostream>
#include <unistd.h>

int main(int argc, char** argv) {
    bt::conn nxt("00:16:53:13:05:B2");
    {
        SetOutputState start_cmd (MOTOR_C, 33, MOTORON|BRAKE|REGULATED, REGULATION_MODE_IDLE, 0,  MOTOR_RUN_STATE_RUNNING, 0);
        nxt.write(start_cmd.payload(), 14);
    }
    int count = 0;
    GetOutputState read_cmd(MOTOR_C);
    do {
        count = read_cmd.get_response(nxt)->tacho_count;
    } while (count < 1700);
    {
        SetOutputState cmd (MOTOR_C, 0, MOTORON|BRAKE|REGULATED, REGULATION_MODE_IDLE, 0,  MOTOR_RUN_STATE_RUNNING, 0);
        nxt.write(cmd.payload(), 14);
    }
    sleep(1);
    return 0;
}
