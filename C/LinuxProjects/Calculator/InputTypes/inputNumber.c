// will define what a number is
// can include chars ect



typedef struct numtok{
	int integer;
	float floatingpoint;
	int boolFloat;
	//type that can have infinite many chars so x y z or xyz
	// linked list of chartoks	
} numtok;


struct value{
	int integer;
	float floatingpoint;
	int boolFloat;
}

typedef struct chartok{
	char* id[];
	struct value idvalue;
} chartok;
