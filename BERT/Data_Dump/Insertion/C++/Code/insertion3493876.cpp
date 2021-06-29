#include <iostream>
using namespace std;

int main(){
int N;
cin >> N;
int A[N];
int i,v,j,k;
for(i=0;i<N;i++)cin>>A[i];
for(i=0;i<N-1;i++)cout << A[i] << " ";
cout << A[N-1];
cout << endl;
for(i=1;i<N;i++)
{

  v=A[i];
  j=i-1;
  while((j>=0)&&(A[j]>v))
  {
  A[j+1] = A[j];
   j--;
  }
  A[j+1] = v;
  for(k=0;k<N-1;k++)cout << A[k] << " ";
  cout << A[N-1];
  cout << endl;

}



}
