/************************/
/* Simple Test Main     */
/* by: Andrew Daniele   */
/************************/
#include "console.h"

using namespace cio;

int main()
{
    char title   [30] = "Small Tester for Assignment 1";
    char author  [19] = "by: Andrew Daniele";
    char name    [20] = "";
    char phone   [15] = ""; 
    char address [20] = "";
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

    return 0;
} // end of main()