#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define rep0(i,n) for(i=0;i<n;i++)
#define rep1(i,n) for(i=1;i<=n;i++)
#define test(a) cout << "*" << a << endl;
static const int NMAX = 100;
int main (){
  int i,j,k;
  int N;
  int A[NMAX+1];
  int v;
  
  cin >> N;
  for(i=0;i<N;i++){
    cin >> A[i];
  }
  
  for(k=0;k<N;k++){
      if(k==N-1)
        cout << A[k];
      else
        cout << A[k] << " ";
  }
  cout << endl;
  
  for(i=1;i<N;i++){
    v = A[i];
    j = i-1;
    while(j>=0&&A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    
    for(k=0;k<N;k++){
      if(k==N-1)
        cout << A[k];
      else
        cout << A[k] << " ";
    }
    cout << endl;
  }
    
  
  
}
    
  
  

