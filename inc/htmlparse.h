/*
 * htmlparse.h; Created by Jon Leithe based on https://www.geeksforgeeks.org/html-parser-in-c-cpp/
 *
 *  Created on: May 3, 2024
 *      Author: Jon Leithe
 *
 */

#ifndef __HTMLPARSE_H__
#define __HTMLPARSE_H__

#include <string>
#include <fstream>
#include <iostream>


using namespace std;



class htmlparse {

	//int			startPos, endPos;
	int			MAXINPUTLINELENGTH;
	long		fileSize;

	char		*fileName;

	ifstream	inputFile;

	void	parse(void);
	string	scanForHtml(char *_stringToScan, int _strLength, string _startTag, string _endTag);

public:
	htmlparse(char *_fileName);
	virtual ~htmlparse();

};

#endif /* __HTMLPARSE_H__ */
