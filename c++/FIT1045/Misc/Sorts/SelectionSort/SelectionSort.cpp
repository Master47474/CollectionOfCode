#include <iostream>
#include <array>

void swap(int *xp, int *yp);
void selction(int arr[], int n);
void printarr(int arr[]);


int main(){
  int arr[] = {1,5,2,7,88,1};
  selction(arr, 6);
  printarr(arr);
  return 0;
}

void printarr(int arr[]){
  for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    std::cout << arr[i] << ", ";
  }
}

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selction(int arr[], int n){
  int i,j,mixind;
  for (i = 0; i < n-1; i++){
    mixind = i;
    for (j = i + 1; j < n; j++){
      if (arr[j] < arr[mixind]){
        mixind = j;
      }
      swap(&arr[mixind], &arr[i]);
    }
  }
}
