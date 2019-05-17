import std.stdio;
import std.random;
import std.math;
import std.algorithm;
import std.conv;

void main(){
  const int num = 1000;
  int[num] results;
  for(int i =1; i < num; i++){
    int rand = uniform(1,7);
    results[i] = rand;
  }
  writeln(sum(results[])/to!float(num));
}
