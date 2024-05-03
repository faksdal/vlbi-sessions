/*
 * htmlparse.h; Created by Jon Leithe based on https://www.geeksforgeeks.org/html-parser-in-c-cpp/
 *
 *  Created on: May 3, 2024
 *      Author: Jon Leithe
 *
 */

#ifndef __HTMLPARSE_H__
#define __HTMLPARSE_H__

/*
 *
 */
class htmlparse {

	int		startPos, endPos;

	char	*fileName;

	FILE	*fp;

public:
	htmlparse(char *_fileName);
	virtual ~htmlparse();
};

#endif /* __HTMLPARSE_H__ */
