#include "nxt.h"
#include <iostream>

int main(int argc, char** argv) {
	SetOutputState cmd (0x01, MOTOR_A, PWR_FULL_BW, MOTORON|REGULATED, REGULATION_MODE_IDLE, 100,  MOTOR_RUN_STATE_RUNNING, 0);
	std::cout << cmd.payload() << std::endl;
	return 0;
}
