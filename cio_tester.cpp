/*********************************************************/
/* Console Input Output Library                     R0.1 */
/*                                                       */
/* Andrew Daniele                  adaniele1@myseneca.ca */
/* September 30, 2013                                    */
/* cio_tester.cpp                                        */
/*                                                       */
/* Adds edit and display functionality to the Console    */
/* Input Output library by creating class 'Console',     */
/* derived publicly from BConsole.                       */
/*********************************************************/


// leave the mode you want, uncommented, and the other, commented
#define TEXTEDITOR
//#define FORM

#if defined TEXTEDITOR && defined FORM
    #undef TEXTEDITOR
    #undef FORM
#endif

#include "console.h"

using namespace cio;
int main()
{
#ifdef TEXTEDITOR //text editor mode
    char title   [30] = "Small Tester for Assignment 1";
    char author  [19] = "by: Andrew Daniele";
    char line1   [79] = {'\0'};
    char line2   [79] = {'\0'};
    char line3   [79] = {'\0'};
    char line4   [79] = {'\0'};
    char line5   [79] = {'\0'};
    int  c            = console.getCols()-1;
    int  curPos       = 0;
    int  fieldLength  = c;
    int  key          = 0;
    int  line         = 1;
    int  r            = console.getRows()-1;
    int  strOffset    = 0;

    bool running = true;
    while (running)
    {
        console.display(title, 0, (c/2)-(bio::strlen(title)/2));
        console.display(author, 0, c-bio::strlen(author));
        console.display("------", r-3, c-6);
        console.display("|Exit|", r-2, c-6);
        console.display("------", r-1, c-6);

        switch (line)
        {
        case 1:
            key = console.edit(line1, 1, 0, fieldLength, 78, &strOffset, &curPos, true);
            break;
        case 2:
            key = console.edit(line2, 2, 0, fieldLength, 78, &strOffset, &curPos, true);
            break;
        case 3:
            key = console.edit(line3, 3, 0, fieldLength, 78, &strOffset, &curPos, true);
            break;
        case 4:
            key = console.edit(line4, 4, 0, fieldLength, 78, &strOffset, &curPos, true);
            break;
        case 5:
            key = console.edit(line5, 5, 0, fieldLength, 78, &strOffset, &curPos, true);
            break;
        case 6:
            key = console.edit("Exit - test read-only", r-2, c-5, 4, 21, (int*)0, (int*)0, false, true);
            break;
        } // end of switch(line)

        switch(key)
        {
        case UP:
            if (line > 1)
                line--;
            break;
        case DOWN:
            if (line < 6)
                line++;
            break;
        case ENTER:
            if (line <= 5)
                line++;
            else if (line == 6)
                running = false;
            break;
        } // end of switch(key)

    } // end of while(running)

#endif // end text editor

#ifdef FORM // form mode
    char title   [30] = "Small Tester for Assignment 1";
    char author  [19] = "by: Andrew Daniele";
    char name    [20] = {'\0'};
    char phone   [15] = {'\0'}; 
    char address [20] = {'\0'};
    int  position     = 0;
    int  key          = 0;
    int  r            = console.getRows()-1;
    int  c            = console.getCols()-1;
    bool running      = true;

    while (running)
    /*
    *  Draw Screen
    *  Get position of user
    *  Process key used to exit editing area
    */
    {
        /*code below draws the screen*/
        console.display(title, 0, (c/2)-(bio::strlen(title)/2));
        console.display(author, 0, c-bio::strlen(author));

        console.display("Name:    ", 6, 9);
        console.display("Phone:   ", 8, 9);
        console.display("Address: ", 10, 9);
    
        console.display("------", r-3, c-6);
        console.display("|Exit|", r-2, c-6);
        console.display("------", r-1, c-6);

        console.display(name, 6, 18, 10);
        console.display(phone, 8, 18, 10);
        console.display(address, 10, 18, 10);
        /*code above draws the screen*/

        switch (position)
        {
        case 0: // name
            key = console.edit(name, 6, 18, 10, 19);
            break;
        case 1: // phone
            key = console.edit(phone, 8, 18, 10, 14);
            break;
        case 2: // address
            key = console.edit(address, 10, 18, 10, 19);
            break;
        case 3: // exit box
            key = console.edit("Exit - test read-only", r-2, c-5, 4, 21, (int*)0, (int*)0, false, true);
            break;
        } // end of switch(position)
        
        switch(key)
        {
        case UP:
            if (position > 0)
                position--;
            break;
        case DOWN:
            if (position < 3)
                position++;
            break;
        case ENTER:
            if (position < 3)
                position++;
            else if (position == 3)
                running = false;
            break;
        default:
            position = 0;
        } // end of switch(key)

    } // end of while(running)

#endif // end form

#ifndef TEXTEDITOR
    #ifndef FORM
    char error[55] = "error with TEXTEDITOR/FORM defines, see cio_tester.cpp";
        console.display(error, console.getRows()/2, (console.getCols()/2)-(bio::strlen(error)/2));
        console.pause();
    #endif
#endif

    return 0;
} // end of main()