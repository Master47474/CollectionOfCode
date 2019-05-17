import std.stdio;
import std.conv;
import std.array;


void main(){
  int[][] list;
  string input;
  for (int i = 0; i < 5; i++){
    write("Input a list of Numbers >> ");
    input = readln[0 .. $-1];
    ++list.length;
    list[i] = to!(int[])(split(input, " "));
  }
  writeln(list);
}
