import std.stdio;
import std.conv;
import std.file;
import std.array;


void main(){
  auto file = File("Tiny.txt");
  int sum = 0;
  auto range = file.byLine();
  float[2][] lst;
  foreach (line; range){
    ++lst.length;
    line = line[0 .. $-1];
    string[] lin = split(to!string(line),",");
    float[2][1] temp =  [to!int(lin[0]), to!float(lin[1])];
    writeln(temp[0][0]," Kms, $", temp[0][1]);
  }
  writeln(lst.length);
}

//
