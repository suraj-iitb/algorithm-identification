#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 void bubbleSort(int a[], int n){
    int flag=1;
    int cnt=0;
    while(flag==1){
        flag=0;
        for(int i=n-1; i>0; i--){
            if(a[i]<a[i-1]){
                cnt++;
                swap(a[i],a[i-1]);
                flag=1;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<a[i];
        if(i!=n-1) cout<<" ";
    }
    cout<<endl;
    cout<<cnt<<endl;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    bubbleSort(a,n);
    return 0;
}
