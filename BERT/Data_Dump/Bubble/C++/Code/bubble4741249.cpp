#include <iostream>
using namespace std;
int main(void){
   int k,n,c;
   cin >> n;
   c=0;
   int A[n];
    for(int i=0;i<n;i=i+1){
        cin >> A[i];
    }
//
    for(int l=1;l<=n;l=l+1){
    
    for(int j=n-1;j>0;j=j-1){
        if(A[j]<A[j-1]){
            k=A[j-1];
            A[j-1]=A[j];
            A[j]=k;
            c=c+1;
        }
    
    }
    }

   for(int i=0;i<n;i=i+1){
            if(i==n-1){
                cout << A[i] <<endl;
            }else{
                cout << A[i] <<" ";
            }
                
            }
            cout << c <<endl;

}
