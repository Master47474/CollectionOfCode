//g++ -o main.exe main.cpp -static-libstdc++
#include <iostream>

using namespace std;

int main(void){
  int sum = 0;
  for (int i = 0; i < 1000; i++){
    if(i % 3 == 0 || i % 5 == 0){
      sum += i;
    }
  }
  cout << sum;
  return 0;
}



/*
//g++ -o main.exe main.cpp -static-libstdc++
#include <iostream>

using namespace std;


int main(void){

  return 0;
}


*/
