#include <iostream>
using namespace std;

int main(){

int N;
cin >> N;
int A[N];
int kaisuu=0,i,j,k;
for(i=0;i<N;i++)cin >> A[i];
for(k=N-1;k>=0;k--)
{
for(i=N-1;i>0;i--)
{
  if(A[i]<A[i-1])
  {
    j = A[i];
    A[i] = A[i-1];
    A[i-1]=j;
    kaisuu++;
  }
}
}
for(i=0;i<N-1;i++)cout << A[i] << " ";
cout <<A[N-1] << endl;
cout << kaisuu << endl;

}
