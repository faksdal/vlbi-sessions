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
	int 	c;
	char	htmlLine[MAXINPUTLINELENGTH];
	bool	quit = false;
	string	parsedLine;

	//
	//	reset counters
	//
	c = 0;

	//
	//	Read through the file, put every line into a buffer, until we reach
	//	end-of-file.
	//
	while(!quit){

		htmlLine[c] = inputFile.get();

		//
		//	If we encounter end-of-line, we must terminate the string.
		//	Next, we scan the string for html-tags.
		//
		if(htmlLine[c] == '\n'){
			htmlLine[c+1] = '\0';

			//
			//	Get rid of any initial whitepace, and pass the
			//	string to the html parser routine
			//
			char* ptr = htmlLine;
			//cout << "ptr before removing whitespace: " << ptr;
			while(*ptr++ == ' ');
			*ptr--;
			//cout << " ptr after removing whitespace: " << ptr;

			//cout << "String upon return to parse(): " << scanForHtml(ptr, counter, "<li>", "</li>") << endl;
			//cout << retPtr;

			//scanForHtml(ptr, c, "<li ", "</li>");
			parsedLine = scanForHtml(ptr, c, "<title>", "</title>");
			if(parsedLine.length() > 0)
				cout << parsedLine << endl;

			parsedLine = scanForHtml(ptr, c, "<li>", "</li>");
			if(parsedLine.length() > 0)
				cout << parsedLine << endl;
			//
			//	Reset the counter
			//
			c = -1;
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
		if(c >= MAXINPUTLINELENGTH)
			quit = true;


		c++;
		//cout << "c: " << c << endl;

	} //	while(!quit)

	//cout << "Total number of closing brackets: " << closingBracketCounter << endl;
}




