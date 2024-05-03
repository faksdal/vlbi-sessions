/*
 * htmlparse.h; Created by Jon Leithe based on https://www.geeksforgeeks.org/html-parser-in-c-cpp/
 *
 *  Created on: May 3, 2024
 *      Author: Jon Leithe
 *
 */

#ifndef __HTMLPARSE_H__
#define __HTMLPARSE_H__

#include <fstream>
#include <iostream>


using namespace std;



class htmlparse {

	int			startPos, endPos;
	long		fileSize;

	char		*fileName;

	ifstream	inputFile;
	//ifstream	fin;

	void	parse(void);

public:
	htmlparse(char *_fileName);
	virtual ~htmlparse();

};

#endif /* __HTMLPARSE_H__ */
