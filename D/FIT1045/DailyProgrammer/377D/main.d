import std.stdio;
/*
int fit1(int X, int Y, int x, int y);
int fit2(int X, int Y, int x, int y);
int fit3(int X, int Y, int Z, int x, int y, int z);
*/
int fitn(int[]  xY, int[] xy);
void permute(int[]* a, int l, int r, int[][]* tot, int* x);
void swap(int* x, int* y);


void main(){
  writeln(fitn([9,8,9,3],[3,2,2,2]));
}

/*
int fit1(int X, int Y, int x, int y){
  int mx = (X/x);
  int my = (Y/y);
  return mx*my;
}

int fit2(int X, int Y, int x, int y){
  int f1 = fit1(X,Y,x,y);
  int f2 = fit1(Y,X,x,y);
  return f1>f2 ? f1 : f2;
}

int fit3(int X, int Y, int Z, int x, int y, int z){
  int[] arr = [x,y,z];
  int[][] aar;
  int n = arr.length;
  int s = 0;
  permute(&arr, 0, n-1,&aar, &s);
  int max = X/x * Y/y * Z/z;
  for (int i = 0; i < aar.length; i++){
    int tempMax = X/aar[i][0] * Y/aar[i][1]* Z/aar[i][2];
    if (tempMax > max){
      max = tempMax;
    }
  }
  return max;
}
*/
int fitn(int[]  xY, int[] xy){
  int n = xy.length;
  int[][] aar;
  int s = 0;
  permute(&xy, 0, n-1,&aar, &s);
  int max = 0;
  for (int i = 0; i < aar.length; i++){
    int tempMax = 1;
    for (int j = 0; j < n; j++){
      tempMax *= xY[j]/aar[i][j];
    }
    if (tempMax > max){
      max = tempMax;
    }
  }
  return max;
}

void swap(int* x, int* y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

void permute(int[]* a, int l, int r, int[][]* tot, int* x){
  int i;
  if (l == r){
    ++tot.length;
    (*tot)[*x] = (*a).dup;
    *x += 1;
  }else{
    for(i = l; i <= r; i++){
      swap(&(*a)[l],&(*a)[i]);
      permute(a, l+1, r, tot, x);
      swap(&(*a)[l],&(*a)[i]);
    }
  }
}
