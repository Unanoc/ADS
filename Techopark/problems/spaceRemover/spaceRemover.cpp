#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

 string spaceRemover(string s) {
   string newS;

   for (int i = 0; i < s.size(); i++) {
     if (s[i] == ' '){
       if (s[i+1] != ' ')
          newS += ' ';
     }else {
       newS += s[i];
     }
   }

   return newS;
 }

int main() {
  string s, tmp;
  ifstream file("test.txt");

  while(getline(file, s)) {
     tmp += spaceRemover(s) + "\n";
  }

  file.close();

  ofstream fout("test.txt");
  fout << tmp;
  fout.close();
  return 0;
}
