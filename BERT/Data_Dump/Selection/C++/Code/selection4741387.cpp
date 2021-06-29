#include <iostream>
using namespace std;
int main(void){
   int k,n,c,min,m,j;
   cin >> n;
   c=0,min=100;
   int A[n];
    for(int i=0;i<n;i=i+1){
        cin >> A[i];
    }
//
    for(int i=0;i<n&&n>1;i=i+1){
      
        for(int j=i;j<n;j=j+1){
        if(A[j]<min){
            min=A[j];
            m=j;
        }
        }
        
        if(A[m]<A[i]){
            k=A[i];
            A[i]=A[m];
            A[m]=k;
            c=c+1;
        }
        min=100;
    }
//
   for(int i=0;i<n;i=i+1){
            if(i==n-1){
                cout << A[i] <<endl;
            }else{
                cout << A[i] <<" ";
            }
                
            }
            cout << c <<endl;

}
