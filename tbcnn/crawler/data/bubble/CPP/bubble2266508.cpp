#include <iostream>
using namespace std;

int main(){
  int N;
  int A[102];
  int i,j,t,cnt=0;
  
  cin >> N;
  for (i=0;i<N;i++)cin >> A[i];

  for (i=0;i<N;i++){
    for (j=N-1;j>i;j--){
      if (A[j]<A[j-1]){
	t=A[j];
	A[j]=A[j-1];
	A[j-1]=t;
	cnt++;
      }
    }
  }

  for (i=0;i<N-1;i++)
    cout << A[i] << " ";

  cout << A[i] << endl;
  cout << cnt << endl;
  return 0;
}
