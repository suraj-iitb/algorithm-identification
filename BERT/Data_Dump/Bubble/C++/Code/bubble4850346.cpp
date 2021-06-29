#include <iostream>
using namespace std;
int bubbleSort(int a[100],int n){
    int z = 0,N = n;
    while(N > 1){
    for(int i = 0 ; i < n-1 ; i++){
        if(a[i]>a[i+1]){
            int c = a[i];
            a[i] = a[i+1];
            a[i+1] = c;
            z++;
        }
    }
    N--;
    }
    return z;
}
int main(void){
    // Your code here!
    int n,a[100],z;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    z = bubbleSort (a,n);
    for(int i = 0 ; i < n-1 ; i++){
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl<<z<<endl;
}

