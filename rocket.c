#include "shell.h"

/*
    rocket.c - makes a rocket animation when SO_shell starts

    -> I DID NOT WRITE THIS FUNCTION, JUST EDITED IT.
    -> ALL CREDIT GOES TO:
            
            Author: http://HelloACM.com
                    http://CodingForSpeed.com


*/

const char rocket[] =
"           ^\n\
          / \\\n\
          |-|\n\
          | |\n\
          |S|\n\
          |O|\n\
          | |\n\
          |S|\n\
          |H|\n\
          |E|\n\
          |L|\n\
          |L|\n\
          | |\n\
         /| |\\\n\
        / | | \\\n\
       |  | |  |\n\
        `-\"\"\"-`\n\
";
 
int welcomeRocket()
{
    for (int i = 0; i < 50; i ++) printf("\n"); // jump to bottom of console
    printf("%s", rocket);
    int j = 300000;
    for (int i = 0; i < 50; i ++) {
        usleep(j); // move faster and faster,
        j = (int)(j * 0.9); // so sleep less each time
        printf("\n"); // move rocket a line upward
    }
    printf(BLUE "Welcome to SO_shell!\n" RESET);
    printf(BLUE"Type" RESET); printf(GREEN " \"help\" " RESET); printf(BLUE "for a list of SO_shell commands!\n\n" RESET);
    return 0;
}