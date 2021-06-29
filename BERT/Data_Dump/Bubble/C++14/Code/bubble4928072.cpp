#include<iostream>
using namespace std;

int main(){
    int n,A[100];
    cin >> n;
    for(int i=0;i<n;i++)cin >> A[i];
    int j=0;

    for(int i=0;i<n;i++){
        for(int s=n-1;s>i;s--){
            if(A[s]<A[s-1]){
                int a=A[s];
                A[s]=A[s-1];
                A[s-1]=a;
                j++;
            }
           
        }
    }
    
    for(int b=0;b<n;b++){
        if(b== n-1)cout << A[b] << endl;
        else cout << A[b] << " " ;
    }

    cout << j << endl;
    return 0;
}
