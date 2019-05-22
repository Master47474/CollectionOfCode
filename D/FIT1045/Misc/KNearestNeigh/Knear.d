import std.stdio;
import std.array;
import std.conv;
import std.random;
import std.math;


// funciton declerations
void openFile(string filename,float splitf, string[]* classTrain, string[]* classTest, float[][]* dTrain, float[][]* dTest);
float distance(float[] inst1, float[] inst2);

void main(){
  string[] classifierTrain, classifierTest;
  float[][] dataTrain, dataTest;
  openFile("sup", 0.66, &classifierTrain, &classifierTest, &dataTrain, &dataTest);



  for (int i = 0; i < dataTrain.length;i++){
    writeln(dataTrain[i]," Is of Training -> ", classifierTrain[i]);
  }
  for (int i = 0; i < dataTest.length;i++){
    writeln(dataTest[i]," Is of Testing -> ", classifierTrain[i]);
  }

  writeln(dataTrain[0]);
  writeln(dataTrain[1]);
  float x = distance(dataTrain[0], dataTrain[1], 3);
  writeln(x);

}




void openFile(string filename,float splitf, string[]* classTrain, string[]* classTest, float[][]* dTrain, float[][]* dTest){
  auto file = File("iris-species/Iris.csv");
  auto range = file.byLine();
  string[] classifierTrain, classifierTest;
  float[][] dataTrain, dataTest;

  int counterTrain = 0;
  int counterTest = 0;
  int counter = 0;

  foreach(line; range){
    if (counter == 0){
      counter++;
      continue;
    }

    string[] lin = split(to!string(line),",");
    float[4] temp;
    int counter1 = 0;

    foreach(entry; lin[1 .. $-1]){
      temp[counter1] = to!float(entry);
      counter1++;
    }

    if(uniform01 < splitf){
      ++classifierTrain.length;
      ++dataTrain.length;
      dataTrain[counterTrain] = temp.dup;
      classifierTrain[counterTrain] = lin[$-1];
      counterTrain++;
    }else{
      ++classifierTest.length;
      ++dataTest.length;
      dataTest[counterTest] = temp.dup;
      classifierTest[counterTest] = lin[$-1];
      counterTest++;
    }

    counter++;
  }

  *classTrain = classifierTrain.dup;
  *classTest = classifierTest.dup;
  *dTrain = dataTrain.dup;
  *dTest = dataTest.dup;
}



float distance(float[] inst1, float[] inst2){
  float distance = 0;
  for (int i = 0; i < inst1.length; i++){
    distance += pow(inst1[i] - inst2[i], 2);
  }
  return sqrt(distance);
}



string[] getNeighbours(float[][] dTrain, float[] dTest, string[] cTrain, int k){
    float[] distances = [];
    int length = dTest.length - 1;
    for (int i = 0; i < dTrain.length; i++){
      int dist = distance(dTrain[i], dTest);
      ++distances.length;
      distances[i] = dist;
    }
    // sort distances
    float[] neighbours = [];
    //get the first k elements and append to neighbours
    
    return neighbours[];
}
