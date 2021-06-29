#include<bits/stdc++.h>

using namespace std;

int selectionSort(int A[], int);

int main()
{
  int N,A[100],k;
  cin>>N;
  for(int i=0;i<N;i++) cin>>A[i];
  k=selectionSort(A,N);
  for(int i=0;i<N;i++){
    if(i) cout<<" ";
    cout<<A[i];
  }
  cout<<endl;
  cout<<k<<endl;
}
  

int selectionSort(int A[],int n)
{
  int k=0,min,j,i;
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(A[j]<A[min]) min=j;
    }
    swap(A[i],A[min]);
    if(A[i]!=A[min]) k++;
  }
  return k;
}

