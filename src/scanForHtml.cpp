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

#include <string>		//	For C++ string operations



int htmlparse::scanForHtml(char *_stringToScan, int _strLength)
{
	int		retClosingBracketCounter = 0;//, i = 0;
	string	stringToScan =_stringToScan;
	string	searchString1 = "<title>";



	if(size_t firstOccurence = stringToScan.find(searchString1) != string::npos){
		size_t lastOccurence = stringToScan.find("</title>");
		cout << _stringToScan << endl;
		cout << stringToScan << endl;
		cout << "Length of searchString1: " << searchString1.length() << endl;
		_stringToScan[lastOccurence] = '\0';
		_stringToScan += firstOccurence + searchString1.length();
		cout << _stringToScan << endl;
	}


	/*
	while(i <= _strLength){



		//while(_stringToScan[i] == ' ')
		//	i++;



		if(_stringToScan[i] == '<'){
			while(_stringToScan[i] == ' ')
							i++;
			while(_stringToScan[i] != '>')
				i++;
			while(_stringToScan[i] == ' ')
				i++;
		}
		else{
			cout << _stringToScan[i];

		}
		i++;

	}
	*/
	return(retClosingBracketCounter);
}
