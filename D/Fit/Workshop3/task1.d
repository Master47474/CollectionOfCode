import std.stdio;
import std.conv;


void main(){
  int[5] output;
  int input;
  for (int i = 0; i < output.length; i++){
    write("Input a Number >> ");
    output[i] = to!int(readln().dup[0 .. $-1]);
  }
  writeln(output);

  // for squares
  output[] ^^= 2;
  writeln(output);
}
