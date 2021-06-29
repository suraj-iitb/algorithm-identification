/*
swap????????則??????????????則?????属????属??????????????????則??????
*/
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int main() {
    int i,j,k;
    int n;
    char buf;
    int A[100];
    
    cin >> n;
    for(k=0; k<n; k++) cin >> A[k];
 
    for(k=0; k<n; k++){
         cout << A[k];
         if(k!=n-1) cout << ' ';
         else cout << endl;
    }
 
    
    for(j=1; j<n; j++){
         for(i=j-1; i>=0; i--){
             if(A[i+1]<A[i]) swap(A[i+1],A[i]);
         }
         for(k=0; k<n; k++){
             cout << A[k];
             if(k!=n-1) cout << ' ';
             else cout << endl;
         }
    }
    
        return 0;
}
 
