
import std.stdio;
import std.exception : assertThrown;
import std.conv;



void main(){
  string str;
  write("Enter a F temp>>");
  stdout.flush;
  str = readln;
  float integer = parse!float(str);
  float cel = (integer-32)*5/9;
  writeln(cel);
}
