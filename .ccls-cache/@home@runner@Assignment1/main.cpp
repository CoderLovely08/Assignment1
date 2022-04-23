#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;



int main() {

  //create file object
  fstream file;
  string goodWords[]={"good","best","nice","excelellnt","great","satis","acceptable","fab","awesome","amazing"};
  int goodlength=sizeof(goodWords)/sizeof(goodWords[0]);
  string badWords[]={"bad","worst","poor","regret","awful","terrible","disgusting"};
  int badlength=sizeof(badWords)/sizeof(badWords[0]);
  //open file 
  file.open("file.txt",ios::in);
  if(!file){
    cout<<"file error";
  }else{
    string review;
    int counter=0;
    //file traversal
      while(getline(file, review)){
        //array traversal
        transform(review.begin(), review.end(), review.begin(), ::tolower);

        for(int i=0;i<goodlength;i++){
          regex reg(goodWords[i]);
          regex reg1("not "+goodWords[i]);
          if(regex_search(review,reg) && !regex_search(review,reg1)){
            cout<<review<<"\n";
          }
        }
      }
  }
  file.close();
  return 0;
}