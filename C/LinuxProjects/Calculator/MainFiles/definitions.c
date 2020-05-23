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



int valueincoeff(term current){
	if(current.boolhascoeff == 1 || current.boolisOperation == 1 || current.boolBracket == 1)
		return 1;
	return 0;
}

int valueinalpha(term current){
	if(current.boolhasalpha == 1)
		return 1;
	return 0;
}
