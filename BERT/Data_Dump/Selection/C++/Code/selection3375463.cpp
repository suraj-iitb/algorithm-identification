#include <bits/stdc++.h>
using namespace std;

int selectionSort(int A[], int N){ // N個の要素を含む0-オリジンの配列A
  int count=0,k;
  for(int i=0;i<N-1;i++){
    int minj = i;
     for(k=i+1;k<N;k++)
       if(A[k] < A[minj])
         {minj = k;}
    if(i!=minj){swap(A[i],A[minj]);count++;}
  }
  return count;
}

int main() {
  int n,temp;
  cin>>n;
  int A[1000];
  for(int i=0;i<n;i++){
    scanf("%d",&temp);
    A[i]=temp;
  }
  int ans=selectionSort(A,n);
  cout << A[0];
  for(int i=1;i<n;i++)
    cout<<" "<<A[i];
  cout<<endl<<ans<<endl;
}

