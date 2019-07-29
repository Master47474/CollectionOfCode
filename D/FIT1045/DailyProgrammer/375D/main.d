import std.stdio;
import std.file;
import std.exception;
import std.algorithm.iteration;

// function declerations
void flip(int* x);


const int size = 7;


void main(){
  int[size] board = [0,1,0,0,1,1,0];


  int[] m = [0,1,2];
  writeln(m.permutations);
  int[][] perms = m.permutations;
  writeln(perms);




  flip(&board[0]);
  flip(&board[2]);
  writeln(board);
}



void solve(int[] board){
  int[size] steps;
  for (int i = 0; i < board.length; i++){
    if (board[i] == 1){
      board[i] = 2;
      flip(&board[i-1]);
    }
  }
}


void flip(int* x){
    if (*x == 1){
      *x = 0;
    }else if(*x == 0){
      *x = 1;
    }
}
