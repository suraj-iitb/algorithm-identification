#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

using namespace std;


int main(){

  int n;
  cin >> n;
  int * x = new int[n];
  
  for(int i=0;i<n;i++){
    cin >> x[i];
  }

  int c=0;
  for(int i=0;i<n;i++){
    int mini = i;
    for(int j=i;j<n;j++){
      if(x[j] < x[mini]){
        mini = j;
      }
    }
    if(i != mini){
      c++;
      int tmp = x[i];
      x[i] = x[mini];
      x[mini] = tmp;
    }
  }

  for(int i=0;i<n;i++){
    cout << x[i];
    if(i==n-1) cout << endl;
    else cout << " ";
  }
  cout << c << endl;


}

