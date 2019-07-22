import std.stdio;
import std.math;
import std.random;

float max(float[2][] array1);
float sigmoid(float z);

void main(){
  float[2][] trainX = [[3.0,5.0],[5.0,1.0],[10.0,2.0]];
  float[1][] trainY = [[75.0],[82.0],[93.0]];

  // normalize data
  float scale = 100.0;
  float maxX = max(trainX);

  foreach(i, line; trainX){
    line[] /= maxX;
    trainX[i] = line;
  }
  foreach(i, line; trainY){
    line[] /= scale;
    trainY[i] = line;
  }

  NeralNetwork network = new NeralNetwork;
}

float max(float[2][] array1){
  float max = 0;
  foreach(entry; array1){
    if (entry[0] > max){
      max = entry[0];
    }
    if (entry[1] > max){
      max = entry[1];
    }
  }
  return max;
}

float sigmoid(float z){
  float s = 1 / (1 + E^^(-z));
  return s;
}

class NeralNetwork{
  const int inputLSize = 2, outputLSize = 1, hiddenLSize = 3;
  float[hiddenLSize][inputLSize] W1;
  float[outputLSize][hiddenLSize] W2;

  this(){
    import std.algorithm.mutation;
    //fill(this.W1, uniform!"()"(0.0f, 1.0f));
    foreach(i, line; this.W1){
      //this.W1[i] = fill(line,  uniform!"()"(0.0f, 1.0f));
    }
    //fill(this.W2, uniform!"()"(0.0f, 1.0f));
    writeln(this.W1);
  //  writeln(this.W2);
  }

  void foward(){
    writeln(1);
  }
}
