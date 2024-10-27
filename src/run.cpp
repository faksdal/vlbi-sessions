/*
 * run.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */


#include "vlbi_sessions.h"


////////////////////////////////////////////////////////////////////////////////
//
// The main part of the program, run() runs until the user exits the program.
// It is responsible for calling readfile(), which reads the content of the
// input file and stores it in memory.
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::run(void)
{
	readfile();
	processInput();

	printHeaders();
	printSessionList();
}

