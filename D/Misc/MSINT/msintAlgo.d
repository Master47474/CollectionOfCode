import std.stdio;
import std.conv;
import std.array;
import std.math;

void extractData(int[][]* classif, float[][]* data);
int[] labelToArray(int label);
float sigmoid(int z);

void main(){
  int[][] classifierTrain, classifierTest;
  float[783][] dataTrain, dataTest;

  // get data
  extractData(&classifierTrain, &dataTrain);
  extractData(&classifierTest, &dataTest);

  for(int i = 0; i < 4; i++){
    writeln( "is actually -> ", classifierTrain[i]);
  }

  /*
  foreach(number; dataTrain[0 .. 5]){
    string[28][28] stringn;
    string[28] temp;
    int counterin = 0, counter = 0;

    for(int i = 0; i < number.length; i++){
      if((i+1) % 28 == 0){
        stringn[counter] = temp.dup;
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
  */
}


void extractData(int[][]* classif, float[783][]* data){

  int[][] tempClass;
  float[783][] tempData;

  auto file = File("train.csv");
  auto range = file.byLine();

  int counter = 0;

  foreach(line; range){
    if (counter == 0){
      counter++;
      continue;
    }

    string[] lin = split(to!string(line),",");
    float[783] temp;
    int counter1 = 0;

    foreach(entry; lin[1 .. $-1]){
      // normalize each value 0 to 1
      float fac = 0.99 / 255;
      temp[counter1] = to!float(entry) * fac + 0.01;
      counter1++;
    }

    ++tempClass.length;
    ++tempData.length;
    tempData[counter-1] = temp.dup;
    tempClass[counter-1] = labelToArray(to!int(lin[0]));


    counter++;
  }

  *data = tempData.dup;
  *classif = tempClass.dup;
}


int[] labelToArray(int label){
  const int max_size = 10;
  int[max_size] temp;
  temp[label] = 1;
  return temp.dup;
}

float sigmoid(int z){
  float s = 1 / (1 + E^^(-z));
  return s;
}
