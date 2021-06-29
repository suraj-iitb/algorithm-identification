#include <bits/stdc++.h>

using namespace std;

int main() {
 int R[110],n,j,v;
 cin >> n;

 for(int i = 0; i<n; i++){
   cin >> R[i];
 }
 for(int i = 0; i<n; i++){
   if(i == (n-1)) {cout << R[i] << endl;}
   else {cout << R[i]<< " ";}
 }
 for(int k=1; k<n;k++){
  v = R[k];
  j = k-1;
  while(j>=0&&R[j]>v){
    R[j+1] = R[j];
    j--;
    R[j+1] = v;
  }
  for(int i = 0; i<n; i++){
     if(i == (n-1)) {cout << R[i] << endl;}
     else {cout << R[i]<< " ";}
  }
 }
}
