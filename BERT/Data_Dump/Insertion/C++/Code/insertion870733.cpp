#include<iostream>
using namespace std;

int main(){
 int num = 0;
 cin >> num;
 int insSort[101];
 for(int i = 0; i < num; i++)
  cin >> insSort[i];

  for(int j = 0; j < num; j++)
   cout << insSort[j] << ( (j == num-1) ? '\n' : ' ');

 for(int i = 1; i < num; i++){ 
  int buf = insSort[i];
  int j = i-1; 
  while(0 <= j && insSort[j] > buf){
   insSort[j+1] = insSort[j];
   j--;
  }
  insSort[j+1] = buf;

  for(int j = 0; j < num; j++)
   cout << insSort[j] << ( (j == num-1) ? '\n' : ' ');
 }

 return 0;
} 
