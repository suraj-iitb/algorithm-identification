#include<bits/stdc++.h>
using namespace std;


int main(){
   
    int n;
    cin >> n;
    int A[n];
    for(int i=0;i<n;i++){
        cin >> A[i]; 
    }
    int s,count = 0;
    for(int i=1;i<n;i++){
      for(int k=n-1;k > 0;k--){
          if(A[k] < A[k-1]){
              s = A[k];
              A[k] = A[k-1];
              A[k-1] = s;
              count++;
          }
      }
    }

    for(int i=0;i<n;i++){
        if(i != n-1)
            cout << A[i] <<  " ";
        else cout << A[i];
    }
        cout << endl;
        cout << count << endl;
}
