#include<iostream>
using namespace std;
const int MAX = 10000;
int Count[MAX + 1];

int main(){
  int a, b;
  cin >> a;



  for(int i = 0; i <= MAX; i++)
    Count[i] = 0;


  for(int i = 0; i < a; i++){
    cin >> b;
    Count[b]++;
  }

  for(int i = 0, c = 0; c < a; i++){
    if(Count[i] > 0){
      while(Count[i]--){
        if(c)
          cout << " ";
        cout << i;
        c++;
      }
    }
  }
  cout << endl;
  return 0;
}
