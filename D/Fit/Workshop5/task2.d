import std.stdio;
import std.conv;
import std.file;
import std.array;


void main(){
  auto file = File("Tiny.txt");
  auto range = file.byLine();
  foreach (line; range){
    line = line[0 .. $-1];
    string[] lin = split(to!string(line),",");
    writeln(to!int(lin[0])," Kms, $", to!float(lin[1]));
  }
}
