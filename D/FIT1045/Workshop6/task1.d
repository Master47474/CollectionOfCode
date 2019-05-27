import std.stdio;


int fit1(int x1, int y1, int x2, int y2){

        return ((x1/x2)*(y1/y2));
}


void main(){
  writeln(fit1(4,5,1,2));
}
