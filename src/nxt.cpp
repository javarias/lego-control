/*
 * nxt.cpp
 *
 *  Created on: Dec 26, 2019
 *      Author: javarias
 */
#include "nxt.h"
#include <sstream>
#include <iostream>
#include <iomanip>

header::header(uint16_t len, uint8_t cmd_type, uint8_t cmd):
len(len), cmd_type(cmd_type), cmd(cmd)
{
}

header::~header()
{
}

payload_printer::~payload_printer()
{
}

SetOutputState::SetOutputState(uint8_t cmd_type, uint8_t motor, int8_t power_set_point, uint8_t mode,
		uint8_t regulation, int8_t turn_ratio, uint8_t run_state, uint8_t tacho_limit):
header(12, cmd_type, 0x01), motor(motor), power_set_point(power_set_point), mode(mode),
regulation(regulation), turn_ratio(turn_ratio), run_state(run_state), tacho_limit(tacho_limit)
{
}

SetOutputState::~SetOutputState()
{
}

std::string SetOutputState::payload()
{
	std::ostringstream buf;
	buf.fill('0');
	buf	<< "0x" << std::hex << std::setw(2) << std::uppercase << (unsigned int)(len & 0xFF) << std::setw(2); //length in LE
	buf << "0x" << std::hex << std::setw(2) << std::uppercase << (unsigned int)(len >> 8 & 0xFF) << std::setw(2); //length in LE
	buf << "0x" << std::hex << std::setw(2) << std::uppercase << (unsigned int)cmd_type << std::setw(2);
	buf << "0x" << std::hex << std::setw(2) << std::uppercase << (unsigned int)cmd << std::setw(2);
	buf << "0x" << std::hex << std::setw(2) << std::uppercase << (unsigned int)motor << std::setw(2);
	buf << "0x" << std::hex << std::setw(2) << std::uppercase << (unsigned int)(power_set_point & 0xFF) << std::setw(2);
	buf << "0x" << std::hex << std::setw(2) << std::uppercase << (unsigned int)mode << std::setw(2);
	buf << "0x" << std::hex << std::setw(2) << std::uppercase << (unsigned int)regulation << std::setw(2);
	buf << "0x" << std::hex << std::setw(2) << std::uppercase << (unsigned int)(turn_ratio & 0xFF) << std::setw(2);
	buf << "0x" << std::hex << std::setw(2) << std::uppercase << (unsigned int)run_state << std::setw(2);
	buf	<< "0x" << std::hex << std::setw(2) << std::uppercase << (unsigned int)(tacho_limit & 0xFF) << std::setw(2); //tacho_limit in LE
	buf << "0x" << std::hex << std::setw(2) << std::uppercase << (unsigned int)(tacho_limit >> 8 & 0xFF) << std::setw(2);//tacho_limit in LE
	buf << "0x" << std::hex << std::setw(2) << std::uppercase << (unsigned int)(tacho_limit >> 16 & 0xFF) << std::setw(2);//tacho_limit in LE
	buf << "0x" << std::hex << std::setw(2) << std::uppercase << (unsigned int)(tacho_limit >> 24 & 0xFF) << std::setw(2);//tacho_limit in LE
	std::flush(buf);
	return buf.str();
}

