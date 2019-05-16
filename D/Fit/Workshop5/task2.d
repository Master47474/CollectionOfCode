import std.stdio;
import std.conv;
import std.file;


void main(){
  byte[] buffer;
  buffer.length = 1024;
  auto file = File("Tiny.txt", "r");
  auto data = file.rawRead(buffer);
  writeln(data);
}
