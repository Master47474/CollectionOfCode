
import std.stdio;
import std.conv;
import std.string;

void main(){
  int x = 390625;
  int n = 8;
  float a = x^^(1.0/n); //1.0/n provides float where 1/n = 1//n an int
  writeln(format("%d , %d, produces a = %g",x,n,a));
}
