import std.stdio;
import std.conv;




void main(){
  // 1 is up 0 is down
  int[] cards = [1,0,0,1,1];
  int[] a = [1,0];
  int turns = 0;
  writeln(cards);
  while (cards[] != [0,0,0,0,0]){
    for (int i = 0; i < 5; i++){
      if (cards[i] == 1){
          cards[i] = 0;
          if (i != 0){
            cards[i-1] = a[cards[i-1]];
          }
          break;
      }
    }
    writeln(cards);
  }
}
