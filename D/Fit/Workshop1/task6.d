import std.stdio;
import std.conv;

void main(){
  string input;
  write("whats your name>> ");
  stdout.flush;
  input = readln;
  char[] name = input.dup;
  writeln(name);
}
