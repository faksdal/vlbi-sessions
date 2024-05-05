/******************************************************************************
 *
 * htmlparser.c; Created by Jon Leithe based on https://www.geeksforgeeks.org/html-parser-in-c-cpp/
 * Date: 3/5-2024
 *
 * First I edited this to accept an input file, instead of a buffer
 * 
 * 
******************************************************************************/
  

#include <stdio.h> 
#include <string.h>
#include <stdbool.h>

#include "htmlparse.h"



//
// Driver code
//
int main(int argc, char **argv)
{
	if(argc < 2){
		cout << "Specify input file!" << endl;
		cout << "Usage: " << argv[0] << " <input-file.html>" << endl;
		exit(-1);
	}
    htmlparse parse(argv[1]);
  
    return 0; 
}

