//g++ -o main.exe main.cpp -static-libstdc++
#include <iostream>

using namespace std;

#define MAXV 4000000

int main(void){
  int f1 = 1,f2 = 1;
  int f3 = f1 + f2;
  int sum = 0;
  while (f3 < MAXV){
    if(f3 % 2 == 0){
      sum += f3;
    }
    f1 = f2;
    f2 = f3;
    f3 = f1+ f2;
  }
  cout << sum;
  return 0;
}
