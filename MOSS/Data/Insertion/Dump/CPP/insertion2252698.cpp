#include <bits/stdc++.h>
#define N 101
using namespace std;
int n,A[N];

void sort(){
  for(int i=0;i<n;i++)cout<<(i? " ":"")<<A[i];cout<<endl;    
  for(int i=1;i<n;i++){
    int v = A[i];
    int j = i -1;
    while(j>=0&&A[j]>v) A[j+1]=A[j--];
    A[j+1] = v;
    for(int i=0;i<n;i++)cout<<(i? " ":"")<<A[i];cout<<endl;    
  }
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++) cin>>A[i];
  sort();
  return 0;
}
