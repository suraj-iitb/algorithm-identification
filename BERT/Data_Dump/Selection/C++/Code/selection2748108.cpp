#include <iostream>
#include <cmath>

using namespace std;

int main(){
 int i,j,N,temp,c=0,minj;
 cin >> N;
 int A[N];
 for (j=0;j<N;++j){
   cin >> A[j];
 }
 for (i=0;i<N;++i) {
   minj=i;
   for (j=i;j<N;++j) {
     if (A[j] < A[minj]) {
       minj=j;
     }
   }
   temp=A[i];
   A[i]=A[minj];
   A[minj]=temp;
   if (i!=minj) c++;
 }
 for (j=0;j<N;++j){
   cout << A[j];
   if (j<N-1) {
     cout << " ";
   } else {
     cout << endl;
   }
 }
 cout << c << endl;
 return 0;
}

