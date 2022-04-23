#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
  
  fstream file;
  file.open("file.txt",ios::in);
  if(!file){
    cout<<"file error";
  }else{
    string tp;
      while(getline(file, tp)){ 
         cout << tp << "\n";       }
  }
  file.close();
  return 0;
}