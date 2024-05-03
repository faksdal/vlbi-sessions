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



/*
// Function to parse the HTML code 
void parser(char* S) 
{ 
    // Store the length of the 
    // input string 
    int n = strlen(S); 
    int start = 0, end = 0; 
    int i, j; 
  
    // Traverse the string 
    for (i = 0; i < n; i++) { 
        // If S[i] is '>', update 
        // start to i+1 and break 
        if (S[i] == '>') { 
            start = i + 1; 
            break; 
        } 
    } 
  
    // Remove the blank spaces 
    while (S[start] == ' ') { 
        start++; 
    } 
  
    // Traverse the string 
    for (i = start; i < n; i++) { 
        // If S[i] is '<', update 
        // end to i-1 and break 
        if (S[i] == '<') { 
            end = i - 1; 
            break; 
        } 
    } 
  
    // Print the characters in the 
    // range [start, end] 
    for (j = start; j <= end; j++) { 
        printf("%c", S[j]); 
    } 
  
    printf("\n"); 
} 
*/
  
// Driver Code 
int main(int argc, char **argv)
{
	if(argc < 2){
		cout << "Specify input file!" << endl;
		cout << "Usage: " << argv[0] << " <input-file.html>" << endl;
		exit(-1);
	}
    htmlparse	parse(argv[1]);
  
    return 0; 
}

