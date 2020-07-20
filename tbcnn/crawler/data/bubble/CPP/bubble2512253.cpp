#include <iostream>
using namespace std;

int cnt=0;

void bubbleSort(int N, int A[]){
    int flag=1,tmp=0;
    while(flag){
        flag=0;
        for(int i=N-1; i>=1; i--){
            if(A[i]<A[i-1]){
                tmp=A[i];
                A[i]=A[i-1];
                A[i-1]=tmp;
                flag=1;
                cnt++;
            }
        }
    }
}

int main(){
    int n,a[105]={};
    cin>>n;
    for(int i=0; i<n; i++)cin>>a[i];
    bubbleSort(n,a);
    for(int i=0; i<n; i++){
        if(i)cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<cnt<<endl;
}
