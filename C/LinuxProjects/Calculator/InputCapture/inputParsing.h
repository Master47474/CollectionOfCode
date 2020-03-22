#define INPUT_ERROR -1
#define INPUT_END 0
#define INPUT_SPACE 1
#define INPUT_CHAR 2
#define INPUT_DIGIT 3
#define INPUT_OPERATION 4
#define INPUT_BRACKET 5


#define BRACKETS "()[]{}"
#define OPENBRACKET "([{"
#define ENDBRACKET ")]}"

#ifdef INPUTPARSING_H_INCLUDED
#define INPUTPARSING_H_INCLUDED

char** captureInput(void);


//identify function declarations
OperationsPrec operation2Enum(const int symbol);
int isOperation(const int symbol);

int GetInputIdentifier(char c);
int isLetter(const int letter);
int isBracket(const int bracket);
int isDigit(const int digit);
int isActualEndBracket(const int openBracket, const int closeBracket);
int isEndBracket(const int bracket);
int isOpenBracket(const int bracket);

void appendNumber(char** string, int* posi, char* temp, int* tempi);

#endif
