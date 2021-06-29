#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 void selectionSort(int a[], int n){
    int cnt=0;
    for(int i=0; i<n; i++){
        int minj = i;
        for(int j=i; j<n; j++){
            if(a[j]<a[minj]){
                minj = j;
            }
        }
        if(i!=minj) cnt++;
        swap(a[i],a[minj]);
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
    selectionSort(a,n);
    return 0;
}
