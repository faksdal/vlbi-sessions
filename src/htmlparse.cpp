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
		//fileSize = inputFile.tellg();

		inputFile.seekg (0, inputFile.beg);
	}

	parse();

}



htmlparse::~htmlparse()
{
	//cout << "Destructor called" << endl;

	inputFile.close();

}
