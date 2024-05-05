/*
 * scanForHtml.cpp
 *
 *  Created on: 5 May 2024
 *      Author: jole
 *
 *	This function scans the input string for html-tags, and act upon them accordingly
 *
 */


#include "htmlparse.h"



int htmlparse::scanForHtml(char *_stringToScan, int _strLength)
{
	int retClosingBracketCounter = 0, i = 0;
	//bool	writeCharacter = false;

	//cout << "String length: " << _strLength << " - " << _stringToScan << endl;

	while(i <= _strLength){

		/*
		while(_stringToScan[i] == ' ')
			i++;
		*/

		if(_stringToScan[i] == '<'){
			while(_stringToScan[i] != '>')
				i++;
		}
		else
			cout << _stringToScan[i];
		i++;

	}
	return(retClosingBracketCounter);
}
