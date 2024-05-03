/*
 * parse.cpp
 *
 *  Created on: 3 May 2024
 *      Author: jole
 */


#include "htmlparse.h"




void htmlparse::parse(void)
{
	int 	start = 0, end = 0, LINESIZE = 256;
	int 	i; //, j;
	char	htmlLine[LINESIZE];
	//char	c;
	bool	quit = false;

	// while not end-of-file
	while(!quit){

		for(i = 0; i < LINESIZE; i++){

			htmlLine[i] = inputFile.get();

			if(inputFile.eof()){
				quit = true;
				break;
			} // if(inputFile.eof())

			// When we've read the whole line,
			// we must parse it, looking for html formatting.
			// An easy way to do that, is to look for a closing bracket, '>'.
			// Every character after a closing bracket, up until the first opening bracket,
			// is a character we wanna keep.
			if(htmlLine[i] == '\n'){
				htmlLine[i+1] = '\0';
				cout << htmlLine;

				start = 0, end = i;
				while(start++ < end){
					if(htmlLine[start] == '>'){
						cout << "Found a closing bracket" << endl;
					} // if(htmlLine[start] == '>')
				} // while(start++ < end)

				break;
			} // if(htmlLine[i] == '\n')

		} // for(i = 0; i < LINESIZE; i++)

	} // while-loop
}
