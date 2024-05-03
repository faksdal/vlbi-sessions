/*
 * htmlparse.cpp
 *
 *  Created on: May 3, 2024
 *      Author: leijon
 */

#include <stdio.h>
#include <iostream>

#include "htmlparse.h"

using namespace std;



htmlparse::htmlparse(char *_fileName) {

	fileName = _fileName;

	fp = fopen(fileName, "r");

	if(fp){
		cout << "File opened!" << endl;
	}

}



htmlparse::~htmlparse() {

}

