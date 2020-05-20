



#include "InputCapture.c"


term* captureInput(void);

//identify function declarations
OperationsPrec operation2Enum(int symbol);
int isOperation(int symbol);
int hasPrecedence(int oper1, int oper2);

int GetInputIdentifier(char c);
int isLetter(const int letter);
int isBracket(const int bracket);
int isDigit(const int digit);
int isActualEndBracket(const int openBracket, const int closeBracket);
int isEndBracket(const int bracket);
int isOpenBracket(const int bracket);
int isAssignmentOperation(const int c);

//appending to number
void appendTerm(term* expression, term addTerm,int* posi, int* tempi, int* alpai);

//creating terms
term createTerm(char* coefficient, char* alphanumeric, int coeffPos, int alphanumPos, int boolOperation, int boolbracket, int Termination);

