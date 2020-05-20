// definition os a term




typedef struct term{
	char* coefficient;
	char* alphanumeric;
	int boolhascoeff;
	int boolhasalpha;
	int boolisOperation; //operation will be stored in the coefficient slot
	int boolBracket;     // same with brackets
	int isTermination;
} term;
