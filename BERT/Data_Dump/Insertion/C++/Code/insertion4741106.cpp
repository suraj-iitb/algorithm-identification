#include <iostream>
using namespace std;
int main(void){
   int n,k,j;
   cin >> n;
   int A[n];
    for(int i=0;i<n;i=i+1){
        cin >> A[i];
    }
//
    for(int i=1;i<n;i=i+1){
        j=i-1;
        
        for(int l=0;l<n;l=l+1){
            if(l==n-1){
                cout << A[l] <<endl;
            }else{
                cout << A[l] <<" ";
            }
                
            }
        
        k=A[i];
        for(;A[j]>k&&j>=0;j=j-1){
            
            A[j+1]=A[j];
            A[j]=k;
            
        }
         
}
   for(int l=0;l<n;l=l+1){
            if(l==n-1){
                cout << A[l] <<endl;
            }else{
                cout << A[l] <<" ";
            }
                
            }

}
