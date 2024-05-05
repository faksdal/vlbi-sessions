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
	//
	// Open input file with the ois:ate, which puts the file pointer at the end of the file.
	// This makes it possible to read the size of the file by calling the tellg()-function,
	// I'm not quite sure I need it though...
	//
	fileName = _fileName;
	inputFile.open(_fileName, ios::ate);
	if(inputFile.is_open()){
		fileSize = inputFile.tellg();

		//
		// After getting the filesize, set file pointer at beginning of file.
		//
		inputFile.seekg(0, inputFile.beg);
	}

	//
	// Call parse() to, well, parse the input file...
	//
	parse();

}



htmlparse::~htmlparse()
{
	//
	// Close file upon exiting
	//
	inputFile.close();

}
