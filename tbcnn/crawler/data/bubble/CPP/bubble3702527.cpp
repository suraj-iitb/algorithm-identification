#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define rep(i,n) for (int i=0; i< (n) ; i++)
typedef long long ll;

int bubuleSort(vector<int> &A,int N){
  int flag = 1,count=0;
  for(int i=0; flag; i++){
    flag = 0;
    for(int j = N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
        swap(A[j],A[j-1]);
        flag = 1;
        count++;
      }
    }
  }

  return count;
}

int main(){
  int n,num;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  num = bubuleSort(a,n);
  rep(i,n-1){
     cout << a[i] << " " ;
   }

   cout << a[n-1] << endl;
   cout << num << endl;

   return 0;
}

