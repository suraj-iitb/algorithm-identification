#include <iostream>
#include <algorithm>

using namespace std;
static const int MAX = 200000;



int selectionsort(int A[],int n){
  int count = 0;
  int i,j,t;
  int minj;

  for(i=0;i<n-1;i++){
    minj = i;
    for(j=i;j<n;j++){
        if(A[j]<A[minj]){
          minj = j;
        }
    }
    t = A[i];
    A[i]=A[minj];
    A[minj]= t;

    if(i != minj) count++;

  }
  return count;
}



int main(){
  int A[MAX],n;
  int count;

  cin >> n;

  for (int i = 0;  i <n; i++){
  cin >> A[i];
}

   count = selectionsort(A,n);

  for (int i=0;i<n;i++){
    if(i) cout <<" ";
    cout << A[i];
  }
  cout << endl;

  cout << count << endl;

  return 0;
}
