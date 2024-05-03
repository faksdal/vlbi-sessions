/*
 * htmlparse.cpp
 *
 *  Created on: May 3, 2024
 *      Author: leijon
 */

#include <stdio.h>
#include <iostream>



#include "htmlparse.h"





htmlparse::htmlparse(char *_fileName)
{
	//cout << "Constructor called" << endl;

	fileName = _fileName;
	inputFile.open(_fileName, ios::ate);
	if(inputFile.is_open()){
		//cout << "File opened! " << fileName << endl;
		fileSize = inputFile.tellg();

		inputFile.seekg (0, inputFile.beg);
	}

	parse();

}



htmlparse::~htmlparse()
{
	//cout << "Destructor called" << endl;

	inputFile.close();

}



void htmlparse::parse(void)
{
	int 	start = 0, end = 0, LINESIZE = 256;
	int 	i, j;
	char	htmlLine[LINESIZE];
	char	c;
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
