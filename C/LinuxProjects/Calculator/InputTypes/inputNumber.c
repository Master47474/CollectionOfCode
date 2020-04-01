// will define what a number is
// can include chars ect



struct chartok{
	char* id;
	int intvalue;
	float floatvalue;
	int boolfloat;
};
typedef struct chartok;

typedef struct opertok{
	char* operid;
};



struct numtok{
	char* integer;
	char* floatingpoint;
	int boolFloat;
	chartok alphanumeric;
	int boolalpanumeric;
	opertok operation;
	int booloper;
};

typedef struct numtok;
