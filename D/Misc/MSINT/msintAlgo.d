import std.stdio;
import std.conv;
import std.array;

void extractData(int[]* classif, int[][]* data);


void main(){
  int[] classifierTrain, classifierTest;
  int[783][] dataTrain, dataTest;
  extractData(&classifierTrain, &dataTrain);

  foreach(number; dataTrain[0 .. 5]){
    //for(int i = 0; i < 28; i++){
    //  write("-");
    //}
    string[28][28] stringn;
    string[28] temp;
    int counterin = 0, counter = 0;

    for(int i = 0; i < number.length; i++){
      if((i+1) % 28 == 0){
        stringn[counter] = temp.dup;
        //writeln(stringn[counter]);
        counter++;
        counterin = 0;
      }

      if (number[i] == 0){
        temp[counterin] = " ";
      }else{
        temp[counterin] = "#";
      }
      counterin++;

    }

    foreach(line; stringn){
      writeln(line);
    }
  }

}


void extractData(int[]* classif, int[783][]* data){

  int[] tempClass;
  int[783][] tempData;

  auto file = File("train.csv");
  auto range = file.byLine();

  int counter = 0;

  foreach(line; range){
    if (counter == 0){
      counter++;
      continue;
    }

    string[] lin = split(to!string(line),",");
    int[783] temp;
    int counter1 = 0;

    foreach(entry; lin[1 .. $-1]){
      temp[counter1] = to!int(entry);
      counter1++;
    }

    ++tempClass.length;
    ++tempData.length;
    tempData[counter-1] = temp.dup;
    tempClass[counter-1] = to!int(lin[0]);


    counter++;
  }

  *data = tempData.dup;
  *classif = tempClass.dup;
}
