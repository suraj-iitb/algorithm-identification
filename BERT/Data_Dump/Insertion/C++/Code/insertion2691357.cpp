#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

using namespace std;

int main(){
  static int n;
  cin >> n;

  int x[n];
  memset(x, 0, n*sizeof(int));
  for(int i=0;i<n;i++){
    cin >> x[i];
    cout << x[i];
    if(i==n-1) cout << endl;
    else cout << " ";
  }

  for(int i = 1; i< n;i++){
    int key = x[i];

    int j= i-1;
    while(j>=0 && x[j] > key){
      x[j+1] = x[j];
      j--;
    }
    x[j+1] = key;

    for(int j=0;j<n;j++){
      cout << x[j];
      if(j==n-1) cout << endl;
      else cout << " ";
    }
  }
  
}

