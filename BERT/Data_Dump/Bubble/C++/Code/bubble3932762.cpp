#include<iostream>

using namespace std;

int main(){
    bool flag = 1;
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    int count = 0;
    
    while(flag){
        flag=0;
        for(int j=n-1; j>0; j--){
            if(a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                flag=1;
                count++;
            }
        }
    }
    for(int i=0; i<n; i++){
        cout<<a[i]<<" \n"[i==n-1];
    }
    cout<<count<<endl;
    return 0;
}
