#include <iostream>
#include <cmath>

using namespace std;

int main(){
 int flag=1,j,N,temp,c=0;
 cin >> N;
 int A[N];
 for (j=0;j<N;++j){
   cin >> A[j];
 }
 while(flag) {
   flag=0;
   for (j=N-1;j>0;--j){
     if (A[j]<A[j-1]) {
       temp=A[j];
       A[j]=A[j-1];
       A[j-1]=temp;
      flag=1;
      c++;
     }
   }
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

