#include <iostream>
using namespace std;
int selsort(int *A,int n){
    int min,temp,cnt;
    cnt=0;
    for(int i=0;i<n;i++){
        min=i;
        for(int j=i;j<n;j++){
            if(A[min]>A[j]){
                min=j;
            }
        }
        if(i!=min){
            temp=A[i];
            A[i]=A[min];
            A[min]=temp;
            cnt++;
        }
    }
    return cnt;
}

int main(void){
    int n,ret;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    ret = selsort(A,n);
    for(int i=0;i<n;i++){
        cout<<A[i];
        if(i<n-1)cout<<' ';
    }
    cout<<endl;
    cout<<ret<<endl;
}

