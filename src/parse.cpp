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
	int 	start = 0, end = 0, LINESIZE = 256;
	int 	i; //, j;
	char	htmlLine[LINESIZE];
	//char	c;
	bool	quit = false;

	//
	// While not end-of-file, keep reading lines from input file
	//
	while(!quit){

		for(i = 0; i < LINESIZE; i++){
			htmlLine[i] = inputFile.get();

			//
			// If we reach end-of-file we must quit reading
			//
			if(inputFile.eof()){
				quit = true;
				break;
			} // if(inputFile.eof())

			//
			// Scan for the newline character, '\n', this marks the end of a line.
			// Terminate the particular line with '\0'.
			//
			if(htmlLine[i] == '\n'){
				htmlLine[i+1] = '\0';
				//cout << htmlLine;
			} // if(htmlLine[i] == '\n')

			// When we've read the whole line,
			// we must parse it, looking for html formatting.
			// An easy way to do that, is to look for a closing bracket, '>'.
			// Every character after a closing bracket, up until the first opening bracket,
			// is a character we wanna keep.
			//
			start = 0, end = i;
			//cout << "i = " << i << endl;
			while(start++ < end){
				if(htmlLine[start] == '>'){
					cout << "Found a closing bracket" << endl;
					//break;
				} // if(htmlLine[start] == '>')
			} // while(start++ < end)

		} // for(i = 0; i < LINESIZE; i++)

	} // while-loop
}
