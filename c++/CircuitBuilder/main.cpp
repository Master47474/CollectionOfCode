
#include <iostream>

using namespace std;

template <class SomeType>
SomeType sum(SomeType a, SomeType b);

int main(){
  int x = 5;
  cout << sum<int>(x,x) << endl;
  return 0;
}

template <class SomeType>
SomeType sum(SomeType a, SomeType b){
  return a + b;
}
