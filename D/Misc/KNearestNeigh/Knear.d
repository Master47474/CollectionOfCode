import std.stdio;
import std.array;
import std.conv;
import std.random;
import std.math;


// funciton declerations
void openFile(string filename,float splitf, string[]* classTrain, string[]* classTest, float[][]* dTrain, float[][]* dTest);
float[][] getNeighbours(float[][] dTrain, float[] dataPoint, string[] cTrain, const int k);
float distance(float[] inst1, float[] inst2);
string classifiy(string[] cTrain, float[][] neighbours);
float accuracy(string[] cTest, string[] predictions);
void selectionSort(float[][]* arr);
void swap(float* i, float* j);
int min(float[] arr);


void main(){
  string[] classifierTrain, classifierTest;
  float[][] dataTrain, dataTest;
  openFile("sup", 0.66, &classifierTrain, &classifierTest, &dataTrain, &dataTest);

  string[] predictions = [];
  const int k = 3;
  for (int i = 0; i < dataTest.length; i++){
    float[][] neig = getNeighbours(dataTrain, dataTest[i], classifierTrain, k);
    string classif = classifiy(classifierTrain, neig);
    ++predictions.length;
    predictions[i] = classif;
    writefln("> Predicted -> %s | Actual -> %s" ,classif[0 .. $-1], classifierTest[i][0 .. $-1]);
  }
  float accurate = accuracy(classifierTest, predictions);
  writeln("Accuracy of > ", accurate, "%");
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

float[][] getNeighbours(float[][] dTrain, float[] dataPoint, string[] cTrain, const int k){
    float[][] distances = [];
    int length = dataPoint.length - 1;
    for (int i = 0; i < dTrain.length; i++){
      float dist = distance(dTrain[i], dataPoint);
      ++distances.length;
      distances[i] = [i, dist];
    }
    // sort distances
    float[][] neighbours;
    neighbours.length = k;
    selectionSort(&distances);
    //get the first k elements and append to neighbours
    for (int i = 0; i < k; i++){
      neighbours[i] = distances[i].dup;
    }
    return neighbours[][];
}

string classifiy(string[] cTrain, float[][] neighbours){
  float[string] votes;
  for (int i = 0; i < neighbours.length; i++){
    string response = cTrain[to!int(neighbours[i][0])];
    if (response in votes){
      votes[response]++;
    }else{
      votes[response] = 1;
    }
  }
  // get highest flower
  string[] keys = votes.keys;
  int counter = 0;
  float max = votes[keys[counter]];
  string retString = keys[counter];
  foreach(line; votes){
    if (line > max){
      retString = keys[counter];
      max = line;
    }
    counter++;
  }
  return retString;
}

float accuracy(string[] cTest, string[] predictions){
  float correct = 0;
  for (int i = 0; i < cTest.length; i++){
    if(cTest[i] == predictions[i]){
      correct += 1;
    }
  }
  return (correct/to!float(cTest.length)) * 100.0;
}

void selectionSort(float[][]* arr){
  for (int index = 0; index < arr.length; index++){
    int mini = min((*arr)[index .. $].dup);
    swap(&(*arr)[index], &(*arr)[index + mini]);
  }
}

void swap(float[]* i, float[]* j){
  float[] temp;
  temp = *i;
  *i = *j;
  *j = temp;
}


int min(float[][] arr){
  float min = arr[0][1];
  int mini = 0;
  for (int i = 1; i < arr.length; i++){
    if (arr[i][1] < min){
      min = arr[i][1];
      mini = i;
    }
  }
  return mini;
}
