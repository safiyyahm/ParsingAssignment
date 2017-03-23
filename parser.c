#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/* Global declarations */ /* Variables */ 
int charClass; 
char lexeme [100]; 
char nextChar; 
int lexLen; 
int token; 
int nextToken; 
FILE *in_fp, *fopen();

/* Function declarations */ 
void  addChar(); 
void  getChar(); 
void  getNonBlank();
void expr();
void term();
void factor(); 
int  lex();

/* Character classes */ 
#define LETTER 0 
#define DIGIT 1 
#define UNKNOWN 99
/* Token codes */ 
#define INT_LIT 10 
#define IDENT 11 
#define ASSIGN_OP 20 
#define ADD_OP 21 
#define SUB_OP 22 
#define MULT_OP 23 
#define DIV_OP 24 
#define LEFT_PAREN 25 
#define RIGHT_PAREN 26

int main(int argc, char* argv[]){
	char const* const fileName = argv[1]; //makes sure that main contains at least 1 argument (which will be the name of the file)
	FILE* infile; 
	infile = fopen(fileName, "r"); //opens file for reading
	char line[1024]; //sets line size to 1024; max number of characters that can be read in per line

	while (fgets(line, sizeof(line), infile)) //reading in individual line
	{
		printf("%s", line); //printing out line that was read in
	}

	fclose(infile); //closes file 
	return 0;
}

/* lookup - a function to lookup operators and parentheses and return the token */ 
int lookup(char ch) 
{  
	switch (ch) 
	{   
		case '(':      
		addChar();      
		nextToken = LEFT_PAREN;      
		break;

    	case ')':      
			addChar();      
			nextToken = RIGHT_PAREN;      
			break;

    	case '+':      
    		addChar();      
    		nextToken = ADD_OP;      
    		break;
    
    	case '-':      
    		addChar();      
    		nextToken = SUB_OP;      
    		break;

    	case '*':      
    		addChar();      
    		nextToken = MULT_OP;      
    		break;

    	case '/':      
    		addChar();      
    		nextToken = DIV_OP;      
    		break;

    	default:      
    		addChar();      
    		nextToken = EOF;      
    		break;  
    }  
    return  nextToken; 
}	