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
    for(int j=n-1;j>=i+1;j--){
      if(x[j] < x[j-1]){
        int tmp = x[j];
        x[j] = x[j-1];
        x[j-1] = tmp;
        c++;
      }
    }
  }
  for(int i=0;i<n;i++){
    cout << x[i];
    if(i==n-1) cout << endl;
    else cout << " ";
  }
  cout << c << endl;


}

