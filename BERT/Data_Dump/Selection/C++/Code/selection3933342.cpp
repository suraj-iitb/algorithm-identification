#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    int count=0;
    int minj;
    for(int i=0; i<n; i++){
        minj=i;
        for(int j=i; j<n; j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        if(i!=minj){
            swap(a[i],a[minj]);
        	count++;
        }       
    }
    for(int i=0; i<n; i++){
        cout<<a[i]<<" \n"[i==n-1];
    }
    cout<<count<<endl;
    return 0;
}
