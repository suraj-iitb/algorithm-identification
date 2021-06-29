#include <iostream>
using namespace std;
int A[100000]={},count=0;
void sort(int n){
    for(int i=0;i<n;i++){
        int minj=i;
        for(int j=i;j<n;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
        if(minj!=i){
            int tmp=A[i];
            A[i]=A[minj];
            A[minj]=tmp;
            count++;
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int k=0;k<n;k++){
        cin>>A[k];
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
    cout<<count<<endl;
    return 0;
}
