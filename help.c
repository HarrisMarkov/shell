#include "shell.h"

/*
    help -> comandos do soshell
*/

int help()
{
    printf("\n");
    printf(RED "///////////////////////////////////////////////////////////////////////////////\n" RESET);
    printf(RED "//////////////////////////////////////////////////////////////////////////////\n" RESET);
    printf(RED "//////////////////" RESET);
    printf(YELLOW "\tLISTA DE COMANDOS SO_SHELL\t" RESET ); 
    printf(RED "//////////////////////\n" RESET);
    printf(RED "/////////////////////////////////////////////////////////////////////////////\n" RESET);
    printf(RED "////////////////////////////////////////////////////////////////////////////\n" RESET);
    printf(CYAN "\nquemsoueu" RESET); printf(YELLOW " -> " RESET); printf(GREEN "get user id;" RESET);
    printf(CYAN "\nPS1=" RESET); printf(YELLOW " -> " RESET); printf(GREEN "PS1=[prompt]; change SO_shell prompt;" RESET);
    printf(CYAN "\n42" RESET); printf(YELLOW " -> " RESET); printf(GREEN "tells you the answer to life, the universe and everything;" RESET);
    printf(CYAN "\nsocp" RESET); printf(YELLOW " -> " RESET); printf(GREEN "socpy [SRC] [DEST]; copy contents of SRC to DEST;" RESET);
    printf(CYAN "\nsocpth" RESET); printf(YELLOW " -> " RESET); printf(GREEN "same as socp but with threads;" RESET);
    printf(CYAN "\nsols" RESET); printf(YELLOW " -> " RESET); printf(GREEN "list files in directory;" RESET);
    printf(CYAN "\nisjpeg" RESET); printf(YELLOW " -> " RESET); printf(GREEN "isjpeg [FILE]; tells the user if the specified FILE is jpeg or not;" RESET);
    printf(CYAN "\ncd" RESET); printf(YELLOW " -> " RESET); printf(GREEN "cd [DIR]; changes to specified directory; goes to home directory if only cd or cd ~ is written;" RESET);
    printf(CYAN "\naviso" RESET); printf(YELLOW " -> " RESET); printf(GREEN "aviso [arg1] [arg2]; prints arg1, arg2 times while decrementing arg2;" RESET);
    printf(CYAN "\navisot" RESET); printf(YELLOW " -> " RESET); printf(GREEN "aviso t [arg1] [arg2]; same as \"aviso\" but with threads;" RESET);
    printf(CYAN "\ncalc" RESET); printf(YELLOW " -> " RESET); printf(GREEN "calc [val1] [op] [val2]; calulator with ( + , - , / , * , ^)" RESET);
    printf(CYAN "\nbits" RESET); printf(YELLOW " -> " RESET); printf(GREEN "calc [val1] [op] [val2]; binary calculatior with ( and , inclusive_OR , exclusive_OR )" RESET);
    printf(CYAN "\nletmeout ou sair ou abandonship" RESET); printf(YELLOW " -> " RESET); printf(GREEN "exit SO_shell;" RESET);

    printf("\n");

    return 0;
}