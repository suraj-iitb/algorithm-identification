#include <iostream>
using namespace std;

int main(void){
  int n;
  cin >> n;

  int a[n];
  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  for(int i=0; i<n; i++){
    int v = a[i];
    int j = i-1;
    while(j>=0 && a[j]>v){
      a[j+1] = a[j];
      j--;
    }
  a[j+1] = v;
  for(int i=0; i<n; i++){
     cout << a[i];
     if(i!=n-1){
       cout << " ";
     } 
   } 
   cout << endl;
  }
  return 0;
}

