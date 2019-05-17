import std.stdio;
import std.conv;

void main(){
  char[] input;
  int[] output;
  for (int i = 0; i < 5; i++){
    write("enter a number >> ");
    input = readln.dup[0 .. $-1];
    int integer = to!int(input);
    ++output.length;
    output[i] = integer;
  }
  writeln(output);

  output[] ^^= 2;
  writeln(output);
}
