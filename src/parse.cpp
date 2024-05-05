/*
 * parse.cpp
 *
 *  Created on: 3 May 2024
 *      Author: jole
 *
 *	This function does the actual parsing of the input file.
 */


#include "htmlparse.h"



void htmlparse::parse(void)
{
	int 	counter, closingBracketCounter;
	char	htmlLine[MAXINPUTLINELENGTH];
	bool	quit = false;

	//
	//	reset counters
	//
	counter = closingBracketCounter = 0;

	//
	//	Read through the file, put every line into a buffer, until we reach
	//	end-of-file.
	//
	while(!quit){

		htmlLine[counter] = inputFile.get();

		//
		//	If we encounter end-of-line, we must terminate the string.
		//	Next, we scan the string for html-tags.
		//
		if(htmlLine[counter] == '\n'){
			htmlLine[counter+1] = '\0';

			//
			//	Scan the string
			//
			//cout << htmlLine;
			closingBracketCounter += scanForHtml(htmlLine, counter);
			//cout << "Number of closing brackets so far: " << closingBracketCounter << endl;

			//
			//	Reset the counter
			//
			counter = -1;
		}

		//
		//	Break out of the while-loop when we reach end-of-file
		//
		if(inputFile.eof()){
			quit = true;
		}

		//
		//	Break out of the while-loop if we reach maximum buffer size
		//
		if(counter >= MAXINPUTLINELENGTH)
			quit = true;

		counter++;

	} //	while(!quit)

	//cout << "Total number of closing brackets: " << closingBracketCounter << endl;
}




