import std.stdio;
import std.string;
import std.math;

void tohex(rgb colour);

struct rgb {
  int r,g,b;
}

void main(){
  rgb red;
  // colour goes here
  red.r=0; red.g=0; red.b=205;
  //colour values printed
  writeln(red.r, " ",red.g, " ",red.b,);
  // hex values printed
  writeln(format("#%s%s%s",tohex(red.r).idup,tohex(red.g).idup,tohex(red.b).idup));
}

char[] tohex(int colour){
  immutable char[int] hex = [0:'0',1:'1',2:'2',3:'3',4:'4',5:'5',6:'6',7:'7',8:'8',9:'9',10:'A',11:'B',12:'C',13:'D',14:'E',15:'F'];

  char[] conversion;
  conversion.length = 2;
  for (auto j = 0; j < conversion.length; j++){
    conversion[j] = '0';
  }
  int maxpow = 1;
  int iter = 0;
  if(colour <= 15){
    conversion[0] = hex[0];
    conversion[1] = hex[colour];
  }else{
    while(iter <= maxpow){
      for (int dif = 0; dif < 16; dif++){
        if((colour-dif)%16 == 0 && iter == maxpow){
          conversion[iter] = hex[dif];
          iter++;
          break;
        }else if((colour-dif)%16 == 0){
          conversion[iter] = hex[(colour-dif)/16];
          iter++;
          break;
        }
      }
    }
  }
  return conversion;
}
