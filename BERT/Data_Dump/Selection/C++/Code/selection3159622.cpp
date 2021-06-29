#include <iostream>
using namespace std;

int SelectionSort(int A[],int N){
  int minj;
  int sw = 0 ;
     for(int i = 0; i < N-1; i++){
         minj = i;
       for(int j = i; j < N; j++){
           if(A[j] < A[minj]) minj = j;     
       }
     swap(A[i], A[minj]);           // t = A[i];A[i] = A[minj];A[minj] = t;
       if(i != minj) sw++;
     }
  return sw;
}


int main(){
   int n, A[100], sw;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> A[i];
  
  sw = SelectionSort(A,n);
  
  for(int i = 0; i < n; i++){
     if(i) cout << " ";         //if(i > 0) printf(" ");
    cout << A[i];               //printf("%d", A[i]);
  }
  cout << endl;                 //printf("\n");
  cout << sw << endl;           //printf("%d\n", sw);
  
  return 0;
}
