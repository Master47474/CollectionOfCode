// will define what a number is
// can include chars ect


typedef struct chartok{
	char* id;
	char* intvalue;
	char* floatvalue;
	int boolfloat;
} chartok;

typedef struct opertok{
	char* operid;
} opertok;

typedef struct numtok{
	char* integer; // make it an integer and flaoting point after testing with string first
	char* floatingpoint;
	int boolfloat;
	chartok alphanumeric;		
	int boolalpanumeric;
	opertok operation;
	int booloper;
	int boolbracket;
} numtok;


opertok createOperationToken(char* operidIn){
	opertok returntok = {operidIn};       	
	//opertok* operationtok = &returntok;
	return returntok;
}

chartok createCharToken(char* idIn,char* intvalueIn, char* floatvalueIn, int boolfloatIn){
	chartok returntok = {idIn, intvalueIn, floatvalueIn, boolfloatIn};
	return returntok;
}

