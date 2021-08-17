#include "shell.h"

/*

    calc.c -> calculator function

*/

void calc (char *value1, char *op, char *value2)
{
    float result;

    /*sum*/
    if( strcmp(op,"+")==0 )
    {
        result= atof(value1) + atof(value2);
    }

    /*subtraction*/
    if( strcmp(op,"-")==0 )
    {
        result= atof(value1) - atof(value2);
    }

    /*multiplication*/
    if( strcmp(op,"*")==0 )
    {
        result= atof(value1) * atof(value2);
    }

    /*divide by zero check*/
    if( strcmp(op,"/")==0 && strcmp(value2,"0")==0 )
    {
        fprintf(stderr,"Não pode dividir por zero!\n");
    }

    /*division*/
    if(strcmp(op,"/")==0 && strcmp(value2,"0") !=0)
    {
        result= atof(value1) / atof(value2);
    }

    /* something to the power of something (value1^value2) */
    if( strcmp(op,"^")==0 )
    {
        result= powf(atof(value1),atof(value2));
    }

    printf(BOLD "%f\n" RESET ,result);
}

void bits(char *value1, char *op, char *value2)
{
	int val1 = atoi(value1), val2 = atoi(value2);

	if( strcmp(op, "&")==0 )
    {
		printf( BOLD "%d\n" RESET , val1&val2);
    }
	
    if( strcmp(op, "|")==0 )
    {
		printf( BOLD "%d\n" RESET, val1|val2);
    }
    
    if( strcmp(op, "^")==0 )
    {
		printf( BOLD "%d\n" RESET , val1^val2);
	}
}