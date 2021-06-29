#include <iostream>
using namespace std;

int A[101];

void output(int n){
  for(int i=0;i<n;i++){
    cout << A[i];
    if(i<n-1) cout << " ";
    else cout << endl;
  }
}

void insertsort(int n){
  for(int i=0;i<n;i++){
    int v=A[i];
    int j=i-1;

    while(j>-1 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
    output(n);
  }
}

int main()
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) cin >> A[i];
  insertsort(n);
  return 0;
}
