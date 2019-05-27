import std.stdio;
import std.file;
import std.array;
import std.random;

void main(){
  auto file = File("Names.txt");
  string[] pickedGiftR; string[] pickedGiftB;
  auto family = array(file.byLineCopy());
  int[] familysize;
  familysize.length = family.length;
  int counter = 0;
  //get family sizes
  foreach(person; family){
    writeln(person.split(" ").length, array(person.split(" "))[$ - 1]);
    familysize[counter] = person.split(" ").length;
    counter++;
  }
  writeln(family);
  writeln(familysize);
  int peoplePicked = 0;
  auto rnd = Random(42);
  while(peoplePicked != 30){
    int rand = uniform(0,familysize.length+1,rnd);
    peoplePicked = 30;
  }
}
