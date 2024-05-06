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
	int retval				= 1;
	string	stringToScan	=_stringToScan;
	//string	startTag		= "<title>";
	//string	endTag			= "</title>";
	string	startTag		= "<th>";
	string	endTag			= "</th>";



	if(int firstOccurence = stringToScan.find(startTag) != string::npos){
		int lastOccurence = stringToScan.find(endTag);

		cout << "First occurence: " << firstOccurence << " Last occurence: " << lastOccurence << endl;
		cout << "String, character by character: ";
		for(int i = firstOccurence; i <= lastOccurence; i++){
			cout << _stringToScan[i] << endl;
		}
		cout << endl;

		//cout << "String before scan: " << _stringToScan << "Character at firstOccurence-1: " << _stringToScan[firstOccurence-1] << endl;
		cout << "String before scan: " << _stringToScan;
		_stringToScan[lastOccurence] = '\0';
		_stringToScan += (firstOccurence-1) + startTag.length();
		cout << " String after scan: " << _stringToScan << endl << endl;
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
	return(retval);
}
