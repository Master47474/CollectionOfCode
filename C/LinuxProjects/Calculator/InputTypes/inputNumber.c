// will define what a number is
// can include chars ect



<<<<<<< HEAD
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
=======
typedef struct numtok{
	int integer;
	float floatingpoint;
	int boolFloat;
	//type that can have infinite many chars so x y z or xyz
	// linked list of chartoks	
} numtok;
>>>>>>> parent of a826f78... about to start making the structs to the capture


struct value{
	int integer;
	float floatingpoint;
	int boolFloat;
}

typedef struct chartok{
	char* id[];
	struct value idvalue;
} chartok;
