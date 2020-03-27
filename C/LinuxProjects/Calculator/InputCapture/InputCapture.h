



#include "InputCapture.c"


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
