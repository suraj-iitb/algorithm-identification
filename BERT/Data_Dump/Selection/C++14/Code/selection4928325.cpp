#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int A[100];
    int count =0;
    int minj,t;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    for(int i=0;i<n;i++){
       minj = i;
       for(int j=i;j<n;j++){
           if(A[j] < A[minj]){
               minj = j;
           }
       }
       if(i!=minj){
           t=A[i];
           A[i]=A[minj];
           A[minj]=t;
           count++;
       }
    }
    for(int i=0;i<n;i++){
        if(i!=n-1){
            cout<<A[i]<<' ';
        }else{
            cout <<A[i]<<endl;
        }
    }
    cout <<count<<endl;
    return 0;
}

