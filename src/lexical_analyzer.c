#include <stdio.h>
#include <ctype.h>

int charClass;
char lexeme[100];
char nextChar;
int lexLen;
int token;
int nextToken;

FILE *in_fp, *fopen();

void addChar();
void getChar();
void getNonBlank();
int lex();

#define LETTER 0
#define DIGIT 1
#define UNKNOWN 99
/*TOKEN CODES*/
#define INT_LIT 10
#define IDENT 11
#define ASSIGN_OP 20
#define ADD_OP 21
#define SUB_OP 22
#define MULT_OP 23
#define DIV_OP 24
#define LEFT_PAREN 25
#define RIGHT_PAREN 26

#define FOR_CODE 30
#define IF_CODE 31
#define ELSE_CODE 32
#define WHILE_CODE 33
#define DO_CODE 34
#define INT_CODE 35
#define FLOAT_CODE 36
#define SWITCH_CODE 37

int main(){
    if ((in_fp = fopen("front.in", "r")) == NULL)
        printf("ERROR - cannot open front.in \n");
    else{
        getChar();
        do {
            lex();
        }while (nextToken != EOF);
      }
   }
// lookUp

int lookup(char ch){
	switch(ch){
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

       case'-':
           addChar();
           nextToken = SUB_OP;
           break;

       case'*':
           addChar();
           nextToken = MULT_OP;
           break;

       case'/':
           addChar();
           nextToken = DIV_OP;
           break;

       default:
           addChar();
           nextToken = EOF;
           break;
       }
       return nextToken;
   }
//AddChar

void addChar(){
	if (lexLen <= 98) {
		lexeme[lexLen++] = nextChar;
		lexeme[lexLen] = 0;
    }else
        printf("Error - lexeme is too long \n");
}

//getChar
void getChar(){
	if ((nextChar = getc(in_fp)) != EOF) {
		if (isalpha(nextChar))
			charClass = LETTER;
		else if (isdigit(nextChar))
			charClass = DIGIT;
		else charClass = UNKNOWN;
	}
    else
        charClass = EOF;
}

// getNonBlank
void getNonBlank(){
    while (isspace(nextChar))
        getChar();
}

//lex
int lex(){
	lexLen = 0;
    getNonBlank();
    switch (charClass){
    case LETTER:
		addChar();
        getChar();
        while (charClass == LETTER || charClass == DIGIT){
			addChar();
            getChar();
        }
		if(lexeme[0] =='f'&&lexeme[1] =='o'&&lexeme[2] =='r'&&lexeme[3] ==0){
			nextToken = FOR_CODE;
		}
		else if(lexeme[0] =='i'&&lexeme[1] =='f'&&lexeme[2] ==0){
			nextToken = IF_CODE;
		}
		else if(lexeme[0] =='e'&&lexeme[1] =='l'&&lexeme[2] =='s'&&lexeme[3] =='e'&&lexeme[4] ==0){
			nextToken = ELSE_CODE;
		}
		else if(lexeme[0] =='w'&&lexeme[1] =='h'&&lexeme[2] =='i'&&lexeme[3] =='l'&&lexeme[4] =='e'&&lexeme[5] ==0){
			nextToken = WHILE_CODE;
		}
		else if(lexeme[0] =='d'&&lexeme[1] =='o'&&lexeme[2] ==0){
			nextToken = DO_CODE;
		}
		else if(lexeme[0] =='i'&&lexeme[1] =='n'&&lexeme[2] =='t'&&lexeme[3] ==0){
			nextToken = INT_CODE;
		}
		else if(lexeme[0] =='f'&&lexeme[1] =='l'&&lexeme[2] =='o'&&lexeme[3] =='a'&&lexeme[4] =='t'&&lexeme[5] ==0){
			nextToken = FLOAT_CODE;
		}
		else if(lexeme[0] =='s'&&lexeme[1] =='w'&&lexeme[2] =='i'&&lexeme[3] =='t'&&lexeme[4] =='c'&&lexeme[5] =='h'&&lexeme[6] ==0){
			nextToken = SWITCH_CODE;
		}
		else
			nextToken = IDENT;
    break;
    // parse ints lits
    case DIGIT:
        addChar();
        getChar();
        while (charClass == DIGIT){
            addChar();
            getChar();
        }
    nextToken = INT_LIT;
    break;

    //pares and ops
    case UNKNOWN:
       lookup(nextChar);
       getChar();
       break;

    //EOF
    case EOF:
    nextToken = EOF;
    lexeme[0] = 'E';
    lexeme[1] = 'O';
    lexeme[2] = 'F';
    lexeme[3] = 0;
	break;
	}// end of switch
    printf("Next toke is: %d, next lexeme is %s\n",nextToken, lexeme);
    return nextToken;
}