#include <iostream>
#include <algorithm>
using namespace std;
int A[1000000]={};
int sum=0;
void sort(int n){
    int flag = 1;
    while(flag){
        flag=0;
        for(int j=n-1;j>=1;j--){
            if(A[j]<A[j-1]){
                int tmp=A[j];
                A[j]=A[j-1];
                A[j-1]=tmp;
                flag=1;
                sum++;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    sort(n);
    for(int i=0;i<n;i++){
        if(i==n-1){
            cout<<A[i];
        }
        else{
            cout<<A[i]<<" ";
        }
    }
    cout<<endl;
    cout<<sum<<endl;
    return 0;
}
