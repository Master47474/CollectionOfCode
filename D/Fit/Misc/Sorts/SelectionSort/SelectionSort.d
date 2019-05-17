import std.stdio;

int min(int[] arr);
void swap(int i, int j, int[]* arr);

void selectionSort(int[]* arr){
  for (int index = 0; index < arr.length; index++){
    int mini = min((*arr)[index .. $].dup);
    swap(&(*arr)[index], &(*arr)[index + mini]);
  }
}

void swap(int* i, int* j){
  int temp;
  temp = *i;
  *i = *j;
  *j = temp;
}


int min(int[] arr){
  int min = arr[0];
  int mini = 0;
  for (int i = 1; i < arr.length; i++){
    if (arr[i] < min){
      min = arr[i];
      mini = i;
    }
  }
  return mini;
}


void main(){
  int[] test = [2,5,3,8,11,32,9,4];
  selectionSort(&test);
  writeln(test);
}
