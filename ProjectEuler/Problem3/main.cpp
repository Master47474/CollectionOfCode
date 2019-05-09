//g++ -o main.exe main.cpp -static-libstdc++
#include <iostream>

using namespace std;


int main(void){
  long long val = 600851475143;
  long long max = 0;
  for (long long i = 3; i <= val / 2; i += 2){
    if (val % i == 0){
      max = i;
      cout << max << "," << val/max << endl;
      for (long long j = 1; i < i / 2; i++){
        if (i % j == 0)
      }
    }
  }
  cout << max;
  return 0;
}
