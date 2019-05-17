import std.stdio;
import std.random;



void main(){

  for (int j = 0; j < 10; j++){
    auto rnd = Random((j+13)*7);
    auto i = uniform(0,2,rnd);
    writeln(i);
  }

}
