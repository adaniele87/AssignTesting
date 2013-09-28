#include "console.h"

using namespace cio;

int main()
{
    char author[19] = "by: Andrew Daniele";
    char name    [20] = "";
    char phone   [9]  = ""; 
    char address [20] = "";
    int  position     = 0;
    int  key          = 0;

    console.display("Small Tester for Assignment 1", 0, 0);
    console.display(author, 0, con.getCols()-1-bio::strlen(author));

    console.display("Name:    ", 2, 2);
    console.display("Phone:   ", 4, 2);
    console.display("Address: ", 6, 2);

    bool running = true;
    while (running)
    {
        console.display(name, 2, 11, 10);
        console.display(phone, 4, 11, 10);
        console.display(address, 6, 11, 10);

        switch (position)
        {
        case 0:
            key = con.edit(name, 2, 11, 10, 19);
            break;
        case 1:
            key = con.edit(phone, 4, 11, 10, 8);
            break;
        case 2:
            key = con.edit(address, 6, 11, 10, 19);
            break;
        }

        switch(key)
        {
        case UP:
            if (position > 0)
                position--;
            break;
        case DOWN:
            if (position < 2)
                position++;
        case ESCAPE:
            !running;
        }
    }

    return 0;
}