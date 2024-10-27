/*
 * printSessionList.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: jole
 */

#include <iostream>

#include "vlbi_sessions.h"



////////////////////////////////////////////////////////////////////////////////
//
//
//
////////////////////////////////////////////////////////////////////////////////
void ivsSessions::printSessionList(void)
{
	int i = 19;

	std::cout	<< sessionList[i].sessionType
				<< sessionList[i].date
				<< sessionList[i].sessionCode
				<< sessionList[i].doy
				<< sessionList[i].time
				<< sessionList[i].dur
				<< sessionList[i].includedStations
				<< sessionList[i].excludedStations
				<< sessionList[i].sked
				<< sessionList[i].corr
				<< sessionList[i].status
				<< sessionList[i].dbcCode
				<< sessionList[i].subm
				<< sessionList[i].del;
}
