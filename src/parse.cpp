/*
 * parse.cpp
 *
 *  Created on: 3 May 2024
 *      Author: jole
 */


#include "htmlparse.h"



void htmlparse::parse(void)
{
	int 	/*start = 0, end = 0,*/ LINESIZE = 256;
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

			if(htmlLine[i] == '\n'){
				htmlLine[i+1] = '\0';
				cout << htmlLine;
				break;
			} // if(htmlLine[i] == '\n')

		} // for(i = 0; i < LINESIZE; i++)

	} // while-loop
}
