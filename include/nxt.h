/*
 * nxt.h
 *
 *  Created on: Dec 26, 2019
 *      Author: javarias
 */

#ifndef NXT_H_
#define NXT_H_

#include <stdint.h>
#include <string>
#include "bt-conn.h"

/*
 * LEGO NXT uses little endian
 */

// see http://www.robotappstore.com/Knowledge-Base/-How-to-Control-Lego-NXT-Motors/81.html

struct header {
    const uint16_t len;
    const uint8_t  cmd_type;
    const uint8_t  cmd;

    header(uint16_t len, uint8_t cmd_type, uint8_t cmd);
    virtual ~header();
};

class payload_printer {
    public:
        uint8_t* payload();
        void write(bt::conn c);

        payload(size_t cmd_len);
        virtual ~payload_printer();

    protected:
        size_t cmd_len;
        uint8_t* buff;

        std::string cmd_hex();
};

/*
 * Motor enums
 */

// Mode
#define    MOTORON     0x01
#define    BRAKE       0x02
#define    REGULATED   0x04

//Regulation Mode
#define    REGULATION_MODE_IDLE        0x00
#define    REGULATION_MODE_MOTOR_SPEED 0x01
#define    REGULATION_MODE_MOTOR_SYNC  0x02

//RunState
#define    MOTOR_RUN_STATE_IDLE		0x00
#define    MOTOR_RUN_STATE_RAMPUP   0x10
#define    MOTOR_RUN_STATE_RUNNING  0x20
#define    MOTOR_RUN_STATE_RAMPDOWN 0x40

//Motor
#define    MOTOR_A   0
#define    MOTOR_B   1
#define    MOTOR_C   2
#define    MOYOR_ALL 0xFF

//Turn ratio
#define    PWR_FULL_FW 		0x64
#define    PWR_34_FW		0x4B
#define	   PWR_HALF_FW		0x32
#define	   PWR_14_FW		0x19
#define	   PWR_STOP			0x00
#define    PWR_FULL_BW 		0x9C
#define    PWR_34_BW 		0xB5
#define	   PWR_HALF_BW		0xCE
#define	   PWR_14_BW		0xE7

struct SetOutputState: public header, payload_printer {
    const uint8_t	motor;
    const int8_t 	power_set_point; //percentage -100 to 100
    const uint8_t 	mode;
    const uint8_t 	regulation;
    const int8_t 	turn_ratio; //-100 to 100
    const uint8_t 	run_state;
    const uint32_t 	tacho_limit; //0 run indefinitely

    SetOutputState(uint8_t cmd_type, //0x00 or 0x80
            uint8_t motor, //MOTORON, BRAKE or REGULATED
            int8_t power_set_point, //PWR_FULL_FW, PWR_34_FW, PWR_HALF_FW, etc
            uint8_t mode,
            uint8_t regulation,
            int8_t turn_ratio,
            uint8_t run_state,
            uint8_t tacho_limit
            );
    ~SetOutputState();
};

struct BeepCommand: public header, payload_printer {
    const uint8_t	tone;
    const uint16_t	frequency;
    const uint16_t	duration;

    BeepCommand();
};





#endif /* NXT_H_ */
