/*
 * ivsSessions.cpp
 *
 *  Created on: Aug 29, 2024
 *      Author: leijon
 */
//#pragma GCC diagnostic ignored "-Wunused-value" *_ptr

//#include <cstdlib>
//#include <vector>
//

//#include <ctype.h>
//#include <errno.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
//#include <sys/ioctl.h>

#include <string>
#include <iostream>

#include "vlbi_sessions.h"



ivsSessions::ivsSessions(std::string _inputFileName)
{
	fo_inputFileName	= _inputFileName;

	fo_inputBufferIndex	= 0;

	intensiveFlag		= false;
	_visible			= false;
	_highlighted		= false;
}



ivsSessions::~ivsSessions()
{
	std::cout << "Thank you for using sessions!\n\r";
	//disableRawMode();
}


/*
void ivsSessions::die(const char *s)
{
	perror(s);
	exit(1);
}



void ivsSessions::disableRawMode(void)
{
	//tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
	if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
		die("tcsetattr");

}



// Function to disable buffered input and echoing
void ivsSessions::enableRawMode(void)
{
	//tcgetattr(STDIN_FILENO, &orig_termios);
	if(tcgetattr(STDIN_FILENO, &orig_termios) == -1)
		die("tcgetattr");

	// diable rawmode upon exit, as a courtesy to the user
	//atexit(disableRawMode);


	struct termios raw = orig_termios;

	raw.c_iflag		&= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag		&= ~(OPOST);
	raw.c_cflag		|= (CS8);
	raw.c_lflag		&= ~(ECHO | ICANON | IEXTEN | ISIG);
	//raw.c_cc[VMIN]	= 0;
	//raw.c_cc[VTIME]	= 1;

	//tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
	if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
		die("tcsetattr");

}



void ivsSessions::moveCursor(int _x, int _y)
{
	std::cout << "\033[" << _y << ";" << _x << "H" << std::flush;
}



char ivsSessions::readKey(void)
{
	int nread;
	char ch;

	while ((nread = read(STDIN_FILENO, &ch, 1)) != 1) {
		if (nread == -1 && errno != EAGAIN)
			die("read");
	}
	return ch;
}



void ivsSessions::processKeypress(void)
{
	char c = readKey();

	switch (c) {
		case CTRL_KEY('q'):		disableRawMode();
								exit(0);
								break;
	}
}



void ivsSessions::run(void)
{
	//bool	quit = false;
	//char	c;
	//char	seq[2];

	enableRawMode();
	clearScreen();
	terminalSize();

	//printHeaders();
	//setupSearchFields();
	//printSearchFields();
	//printItemList(0);

	// position the cursor in the first search field
	moveCursor(2, 3);

	textColor = "\033[31;47m";

	// Loop to catch and display keystrokes
	while (1){

		refreshScreen();
		processKeypress();
	}


	//clearScreen();
	//moveCursor(1, listEndRow + 1);
	disableRawMode();
	std::cout << "\033[0m" << std::endl;
}



void ivsSessions::clearAllBuffers(void)
{
	buffer.clear();
	_sessionType.clear();
	_date.clear();
	_sessionCode.clear();
	_doy.clear();
	_time.clear();
	_dur.clear();
	_includedStations.clear();
	_excludedStations.clear();
	_sked.clear();
	_corr.clear();
	_status.clear();
	_dbcCode.clear();
	_subm.clear();
	_del.clear();
}



void ivsSessions::printHeaders(void)
{
	// print the heading to screen
	if(intensives){
		print(1, 1, INTENSIVE_HEADING_1);
		print(1, 2, INTENSIVE_HEADING_2);
	}
	else{
		print(1, 1, NORMAL_HEADING_1);
		print(1, 2, NORMAL_HEADING_2);
	}
	//std::cout << std::endl;
}



void ivsSessions::refreshScreen(void)
{
	  write(STDOUT_FILENO, "\x1b[2J", 4);
	  write(STDOUT_FILENO, "\x1b[H", 3);
}



void ivsSessions::clearScreen(void)
{
	// Clear the terminal
	//std::cout << "\033[2J\033[1;1H" << std::flush;
	write(STDOUT_FILENO, "\x1b[2J", 4);
}


void ivsSessions::printSearchFields(void)
{
	for(int i = 0; i < (int)searchFieldList.size(); i++){
		print(searchFieldList[i].xLocation,
			  searchFieldList[i].yLocation,
			  searchFieldList[i].textColor + searchFieldList[i].searchText);
	}

}



void ivsSessions::setupSearchFields(void)
{
	bool	_active = false;
	short	_xLocation;
	short	_yLocation = 3;
	short	_cursorLocation = 0;


	int	startx	= 0;
	int	length	= (ivsListItems[0].sessionType.size() - 1);
	int	index	= 0;

	while(ivsListItems[0].sessionType[index] == '|')
		index++;
	startx = ++index;

	//std::cout << "startx: " << startx << std::endl;

	//std::string buffer, textColor;

	buffer.clear();
	buffer.append(length, ' ');

	textColor = "\033[31;47m";

	//print(startx, 3, textColor + buffer);
	_xLocation = startx;
	searchFieldList.push_back({_active, _xLocation, _yLocation, _cursorLocation, textColor, buffer});

	startx += length + 1;
	length	= (ivsListItems[0].date.size() - 1);
	buffer.clear();
	buffer.append(length, ' ');
	//print(startx, 3, textColor + buffer);
	_xLocation = startx;
	searchFieldList.push_back({_active, _xLocation, _yLocation, _cursorLocation, textColor, buffer});

	startx += length + 1;
	length	= (ivsListItems[0].sessionCode.size() - 1);
	buffer.clear();
	buffer.append(length, ' ');
	//print(startx, 3, textColor + buffer);
	_xLocation = startx;
	searchFieldList.push_back({_active, _xLocation, _yLocation, _cursorLocation, textColor, buffer});

	startx += length + 1;
	length	= (ivsListItems[0].doy.size() - 1);
	buffer.clear();
	buffer.append(length, ' ');
	//print(startx, 3, textColor + buffer);
	_xLocation = startx;
	searchFieldList.push_back({_active, _xLocation, _yLocation, _cursorLocation, textColor, buffer});

	startx += length + 1;
	length	= (ivsListItems[0].time.size() - 1);
	buffer.clear();
	buffer.append(length, ' ');
	//print(startx, 3, textColor + buffer);
	_xLocation = startx;
	searchFieldList.push_back({_active, _xLocation, _yLocation, _cursorLocation, textColor, buffer});

	startx += length + 1;
	length	= (ivsListItems[0].dur.size() - 1);
	buffer.clear();
	buffer.append(length, ' ');
	//print(startx, 3, textColor + buffer);
	_xLocation = startx;
	searchFieldList.push_back({_active, _xLocation, _yLocation, _cursorLocation, textColor, buffer});

	startx += length + 1;
	length	= (ivsListItems[0].includedStations.size() - 1);
	buffer.clear();
	buffer.append(length, ' ');
	//print(startx, 3, textColor + buffer);
	_xLocation = startx;
	searchFieldList.push_back({_active, _xLocation, _yLocation, _cursorLocation, textColor, buffer});

	startx += length + 1;
	length	= (ivsListItems[0].sked.size() - 1);
	buffer.clear();
	buffer.append(length, ' ');
	//print(startx, 3, textColor + buffer);
	_xLocation = startx;
	searchFieldList.push_back({_active, _xLocation, _yLocation, _cursorLocation, textColor, buffer});

	startx += length + 1;
	length	= (ivsListItems[0].corr.size() - 1);
	buffer.clear();
	buffer.append(length, ' ');
	//print(startx, 3, textColor + buffer);
	_xLocation = startx;
	searchFieldList.push_back({_active, _xLocation, _yLocation, _cursorLocation, textColor, buffer});

	startx += length + 1;
	length	= (ivsListItems[0].status.size() - 1);
	buffer.clear();
	buffer.append(length, ' ');
	//print(startx, 3, textColor + buffer);
	_xLocation = startx;
	searchFieldList.push_back({_active, _xLocation, _yLocation, _cursorLocation, textColor, buffer});

	startx += length + 1;
	length	= (ivsListItems[0].dbcCode.size() - 1);
	buffer.clear();
	buffer.append(length, ' ');
	//print(startx, 3, textColor + buffer);
	_xLocation = startx;
	searchFieldList.push_back({_active, _xLocation, _yLocation, _cursorLocation, textColor, buffer});

	startx += length + 1;
	length	= (ivsListItems[0].subm.size() - 1);
	buffer.clear();
	buffer.append(length, ' ');
	//print(startx, 3, textColor + buffer);
	_xLocation = startx;
	searchFieldList.push_back({_active, _xLocation, _yLocation, _cursorLocation, textColor, buffer});
}



void ivsSessions::terminalSize(void)
{
	struct	winsize	ws;

	// Use ioctl to get the window size
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
		std::cerr << "Error: Unable to get terminal size" << std::endl;
		return;
	}

	//clearScreen();

    // Assign terminal size to variables
    columns	= ws.ws_col;
    rows	= ws.ws_row;
}



void ivsSessions::print(int _x, int _y, std::string _text)
{
	std::cout << "\033[" << _y << ";" << _x << "H" << _text << std::flush;
	//std::cout << "\033[" << _y << ";" << _x << "H" << _text;
}



void ivsSessions::print(int _x, int _y, int _number)
{
	std::cout << "\033[" << _y << ";" << _x << "H" << _number << std::flush;
}



// TODO: print the list at the desired location
//
// TODO: keeping track of:
//							- how big screen I have
//							- which items are visible on the display
//							- which item is highlighted
//
// TODO:
// TODO:
void ivsSessions::printItemList(int _startItem)
{
	// "\033[Effects;Colours;Backgrounds;Extra colours m"
	//std::string	textColor;	// = "\033[33m";

	ivsListItems[_startItem].highlighted = true;

	listStartRow = 4;

	int x = 1;
	int y = listStartRow;
	//int y = 4;

	for(int i = _startItem; i < (int)ivsListItems.size(); i++){

		if(ivsListItems[i].highlighted){
			textColor = "\033[30;102m";	//
		}
		else{
			textColor = "\033[40;00m";		// white text, default background
		}
		//print(x, y, textColor);
		print(x, y, textColor
				  + ivsListItems[i].sessionType
				  + ivsListItems[i].date
				  + ivsListItems[i].sessionCode
				  + ivsListItems[i].doy
				  + ivsListItems[i].time
				  + ivsListItems[i].dur
				  + ivsListItems[i].includedStations
				  + ivsListItems[i].excludedStations
				  + ivsListItems[i].sked
				  + ivsListItems[i].corr
				  + ivsListItems[i].status
				  + ivsListItems[i].dbcCode
				  + ivsListItems[i].subm
				  + ivsListItems[i].del
				  );
		y++;

		if(y > (rows - 4))
			break;
	}

	if(y < (rows - 3)){
		print(1, y, "\033[36mNumber of elements in the session list: ");
		print(41, y, ivsListItems.size());
	}
	else{
		print(1, (rows - 3), "\033[36mNumber of elements in the session list: ");
		print(41, (rows - 3), ivsListItems.size());
	}
	listEndRow = y;

	std::cout << ". Rows: " << rows << ", listStartRow: " << listStartRow << ", listEndRow: " << listEndRow << std::endl;
}



ivsSessions::ivsSessions(const char* _ptr, unsigned long _size, bool _intensives)
{
	unsigned long	c		= 0;
	bool			quit	= false;


	// clear all buffers
	clearAllBuffers();

	intensives = _intensives;

	startIndex	= 0;
	endIndex	= 1;

	// scan forward to the first occurence of '|', to put us at the start of the actual sessions
	while(*_ptr != '|'){
		*_ptr++;
		c++;
	}

	// print the heading to screen
	//printHeaders();

    // traverse the *_ptr, assigning each line to an element in a list
    while(!quit){

		if(*_ptr == '\r'){
			buffer.append(1, *_ptr);

			// We're at the start of the buffer and the first character is '|'
			// This corresponds to startIndex = 0;
			// Now I must scan the buffer for the next occurence of '|'
			// And store that index in endIndex
			// Unless this is a divider, then the whole string is '---'
			if(buffer[0] != '-'){
			while(buffer[endIndex] != '|')
				endIndex++;
			_sessionType.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;

			_date.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_sessionCode.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_doy.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_time.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_dur.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_includedStations.append(buffer, startIndex, (endIndex - startIndex));

			//startIndex = endIndex;
			//endIndex++;
			//while(buffer[endIndex] != '|')
			//	endIndex++;
			//_excludedStations.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_sked.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_corr.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_status.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_dbcCode.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_subm.append(buffer, startIndex, (endIndex - startIndex));

			startIndex = endIndex;
			endIndex++;
			while(buffer[endIndex] != '|')
				endIndex++;
			_del.append(buffer, startIndex, (endIndex - startIndex + 1));

			ivsListItems.push_back({_sessionType,
				                    _date,
									_sessionCode,
									_doy,
									_time,
									_dur,
									_includedStations,
									_excludedStations,
									_sked,
									_corr,
									_status,
									_dbcCode,
									_subm,
									_del,
									true,
									false });


			}

			// clear all buffers
			clearAllBuffers();

			// reset indexes
			startIndex	= 0;
			endIndex	= 1;

			// advance pointer
			*_ptr++;
		}
		else{
			// add the *_ptr to the buffer
			buffer.append(1, *_ptr);
		}
		*_ptr++;
		c++;

		if((*_ptr) == '#'){
			quit = true;
		}
		if(c >= _size)
			quit = true;
	}
}



ivsSessions::~ivsSessions()
{
	std::cout << "Destructor called!\n\r";

	disableRawMode();
}
*/
