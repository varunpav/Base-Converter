//Varun Pavuloori, uja2wd, uja2wd@virginia.edu, 9.22.22
//bitCounter.cpp

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class bitCounter{
public:
  bitCounter();
  int countBits(int x);
  string convertBase(string num, int y, int z);
  int charConvert(char c);
  char convertToChar(int a);
};

bitCounter::bitCounter(){
}

int bitCounter::countBits(int x){
  //used to exit the recursive function
  if (x==0)
    return 0;
  //if the passed int is even, then divide num by 2 and run again
  if (x%2==0)
    return (countBits(x/2));
  //if passed int is not even, divide num by 2 and add 1
  else
    return (countBits(x/2)+1);
}

string bitCounter::convertBase(string num, int baseX, int baseY){
  //Step 1: convert to base 10
  int b10=0;
  int pow=1;
  for (int i=num.length()-1;i>=0;i--){
    //update num
    b10=b10+charConvert(num[i])*pow;
    //update power to increase based on base
    pow=pow*baseX;
  }
  //Step 2: convert from base 10 to chosen base
  string returnVal = "";
  while (b10>0){
    returnVal.append(1,convertToChar(b10%baseY));
    b10=b10/baseY;
  }
  //reverse the string
  
  //implementation for reversing string came from
  //www.geeksforgeeks.org/reverse-a-string-in-c-cpp-different-methods/
   int v=returnVal.length();
   for(int t=0; t<v/2; t++){
     swap(returnVal[t], returnVal[v-t-1]);
  }
  
  return returnVal;
}

int bitCounter::charConvert(char c){
  if (isdigit(c)!=0)
    return c-'0';
  else 
    return c-'A'+10;
}

char bitCounter::convertToChar(int a){
  if (a<=9)
    return a + '0';
  else
    return (a-10) + 'A';
}
    

    
int main(int argc, char **argv){
  bitCounter bc;
  //for bitcounter
  cout<<argv[1]<<" has "<<bc.countBits(stoi(argv[1]))<<" bit(s)"<<endl;
  //convert base
  cout<<argv[2]<<" (base "<<argv[3]<<") = "<<bc.convertBase(argv[2],stoi(argv[3]),stoi(argv[4]))<<" (base "<<argv[4]<<")"<<endl;
  return 0;
}
