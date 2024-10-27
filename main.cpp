/*******************************************************************************
 *
 * ivs-vlbi.cpp; Created by Jon Leithe
 * Date: 21/8-2024
 *
 * 
 *
*******************************************************************************/
//#pragma GCC diagnostic ignored "-Wunused-variable" ivs


#include <string>
#include <iostream>

#include <getopt.h>

#include "fileexists.h"
#include "vlbi_sessions.h"

//#include <stdio.h> 
//#include <string.h>
//#include <stdbool.h>

//#include "fileoperations.h"
//#include "ivsSessions.h"



// driver code
int main(int argc, char **argv)
{
	// getopt()-variables
	int		c, optionIndex;

	char	*shortOptions = (char*)"i:h";
	struct option	longOptions[] = {
		{"input-file",	required_argument,	NULL,	'i'},
		{"help",		no_argument,		NULL,	'h'},
		{0, 0, 0, 0}
	}; //end of getopt()-variables

	// filename variables
	std::string	inputFileName;
	bool		inputFileNameSet;



	// getopt() switch statement
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
		switch(c){
			case 'i':	{
							// if file don't exists, give a message and exit
							if(!fileexists(optarg)){
								std::cout << "[ERROR] main(): Input file " << optarg << " does not exist!" << std::endl;
								std::cout << "[ERROR] main(): Exiting..." << std::endl;

								exit(1);
							}

							// otherwise, store filename for later use
							inputFileName		= optarg;
							inputFileNameSet	= true;
							break;
						}

			case 'h':	{
							std::cout << "main(): Provide some useful help to the user!" << std::endl;
							exit(1);
						}
			default:	{
							std::cout << "main: Switch default\n" << std::endl;
							break;
						}
				} //end of getopt() switch statement
	} // end of while-loop


	if(inputFileNameSet){

		ivsSessions *s = new ivsSessions(inputFileName);

		if(!s){
			std::cerr << "Memory allocation failed! " << std::endl;
			std::cerr << "[ERROR] main(): failed to create object: ivsSessions(), exiting..." << std::endl;
			exit(-1);
		}

		s->run();
		delete s;
	}
	else{
		std::cout << "No input filename given, nothing to do..." << std::endl;
	}




	/*

	// reset searchArrayIndex, use to keep track of how many search terms we have
	searchTermsIndex = 0;

	//	If all necessities are in place, we can continue to
	//	create an object-instance and initiate the search...
	fileoperations	*fo;

	if(inputFileNameSet){
		if(verbose)
			std::cout << "[OK]    main(): We have valid filenames!" << std::endl;

		fo = new fileoperations(inputFileName, outputFileName, verbose);
		if(!fo){
			std::cerr << "[ERROR] main(): failed to create object: fo = new fileoperations(inputFileName, outputFileName, verbose), exiting..." << std::endl;
			exit(-1);
		}
	} // if(inputFileNameSet && outputFileNameSet)


	// store file contents in memory, before deleting the fo-object
	std::string str = fo->fo_getInputBuffer();
	unsigned long size = str.size();

	bool intensives  = false;
	if(str.find("INTENSIVES") != std::string::npos)
		intensives  = true;

	delete fo;

	// instantiate the session list, passing a pointer to the input file content to the constructor
	ivsSessions* ivs = new ivsSessions(str.c_str(), size, intensives);

	ivs->run();

*/

	//*************************************************************************

    return(0);
}

