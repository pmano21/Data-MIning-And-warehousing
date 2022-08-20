#include <fstream>
#include <iostream>
using namespace std;
 
int main () {
   char data[100];

   ofstream outfile;
   outfile.open("output1.txt");
   outfile<<"T1 a b c e"<<endl;
   outfile<<"T2 b d f"<<endl;
   outfile<<"T3 a c d f"<<endl;
   outfile<<"T4 d f"<<endl;
   outfile<<"T5 c d e"<<endl;
   
  

   return 0;
}


