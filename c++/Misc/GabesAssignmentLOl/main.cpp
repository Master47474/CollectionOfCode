
#include <iostream>
#include <string>


using namespace std;


string Translate(string inputString, string translationArray[], int transLen){
  // input is a word to be translated

  for(int index = 0; index < transLen; index += 2){
    if(inputString == translationArray[index]){
      return translationArray[index+1];
    }
  }
  //if we are out of the for loop then we must have not found the translation
  return "There is No American to English translation for that word";
}



int main(){
  string translation[] =  {"pop","dad","drug store","chemist"};
  int tLen = 4; //hard code the length

  cout << "Input a word >> ";
  string inputString;
  getline(cin, inputString);

  string translated = Translate(inputString, translation, tLen);

  cout << translated << endl;



  return 0;
}


class Translator{
  public:
    string input;
    string output;

}
