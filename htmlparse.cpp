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
	cout << "Constructor called" << endl;

	fileName = _fileName;
	inputFile.open(_fileName, ios::ate);
	if(inputFile.is_open()){
		cout << "File opened! " << fileName << endl;
		fileSize = inputFile.tellg();

		inputFile.seekg (0, inputFile.beg);
	}

	parse();

}



htmlparse::~htmlparse()
{
	cout << "Destructor called" << endl;

	inputFile.close();

}



void htmlparse::parse(void)
{
	cout << "Inside the parser!" << endl;
	cout << "File size: " << fileSize << endl;


	int 	start = 0, end = 0;
	int 	i, j;
	char	c;

	while(!inputFile.eof()){
		inputFile.get(c);
		cout << c;
	}

	// Store the length of the input file


	    /*
	    // Traverse the string
	    for (i = 0; i < n; i++) {
	        // If S[i] is '>', update
	        // start to i+1 and break
	        if (inputFile.get() == '>') {
	            start = i + 1;
	            break;
	        }
	    }

	    // Remove the blank spaces
	    while (inputFile.get() == ' ') {
	        start++;
	    }

	    // Traverse the string
	    for (i = start; i < n; i++) {
	        // If S[i] is '<', update
	        // end to i-1 and break
	        if (inputFile.get() == '<') {
	            end = i - 1;
	            break;
	        }
	    }

	    // Print the characters in the
	    // range [start, end]
	    for (j = start; j <= end; j++) {
	        printf("%c", inputFile.get());
	    }
	    */

	    printf("\n");

}
