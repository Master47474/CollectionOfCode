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

  // normalize data
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

float dot(){

}

class NeralNetwork{
  const int inputLSize = 2, outputLSize = 1, hiddenLSize = 3;
  // 2 x 3 matrix (2,3)
  float[hiddenLSize][inputLSize] W1;
  // 3 x 1 matrix (1,3)
  float[outputLSize][hiddenLSize] W2;

  // make W1 and W2 Weights random on creation
  this(){
    import std.algorithm.mutation;
    //w1 is a 2 x 3 matrix
    foreach(i, line; this.W1){
      float rndNum = uniform!"()"(0.0f, 1.0f);
      // as rows are 3 long
      float[] toFill = [rndNum, rndNum, rndNum];
      this.W1[i] = toFill.dup;
    }
    //w2 is a 3x1 matirix
    foreach(i, line; this.W2){
      float rndNum = uniform!"()"(0.0f, 1.0f);
      // as rows are 1 long
      float[] toFill = [rndNum];
      this.W2[i] = toFill.dup;
    }
    writeln(this.W1);
    writeln(this.W2);
  }

  void foward(float[][] X){
    writeln(1);
    //dotproduct
  }
}
