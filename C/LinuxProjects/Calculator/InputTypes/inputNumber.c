// will define what a number is
// can include chars ect



struct chartok{
	char* id;
	char* intvalue;
	char* floatvalue;
	int boolfloat;
} chartok_default = {'\0', '\0', '\0', 0};
typedef struct chartok chartok;

typedef struct opertok{
	char* operid;
} opertok;

struct numtok{
	char* integer; // make it an integer and flaoting point after testing with string first
	char* floatingpoint;
	int boolfloat;
	chartok alphanumeric;		
	int boolalpanumeric;
	opertok operation;
	int booloper;
	int boolbracket;
} numtok_default = {'\0', '\0', 0, NULL, 0, NULL, 0, 0};


typedef struct numtok numtok;








