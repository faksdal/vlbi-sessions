/*
 * processInput.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */

#include <iostream>

#include "vlbi_sessions.h"


////////////////////////////////////////////////////////////////////////////////
//
// Process the input buffer, making a dynamic <vector> list of all sessions
// The list is defined in vlbi_sessions.h; std::vector<SessionList>	sessionList
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::processInput(void)
{
	// print input buffer to screen, for debug purposes
	// TODO: to be deleted on release
	std::cout << "processInput: \n\r" <<  fo_inputBuffer << std::endl;



}
