#include<iostream>
#include<algorithm>
using namespace std;
int bubbleSort(int a[], int n){
    bool flg=true;
    int c=0;
    while(flg){
        flg=false;
        for(int j=n-1;j>=1;j--){
            if(a[j]<a[j-1]){
                swap(a[j], a[j-1]);
                c++;
                flg=true;
            }
        }
    }
    return c;
}
int main(){
    int N;
    int A[110];
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int cnt=bubbleSort(A, N);
    for(int i=0;i<N;i++){
        cout<<A[i];
        if(i<N-1){
            cout<<' ';
        }else{
            cout<<endl;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
