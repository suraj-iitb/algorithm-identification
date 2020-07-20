#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[100];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    bool flag=1;
    int count=0;
    while(flag){
        flag=0;
        for(int j=n-1;j>0;j--){
            if(a[j]<a[j-1]){
               swap(a[j],a[j-1]);
            flag=1;
            count++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(i!=n-1)cout<<a[i]<<" ";
        else cout<<a[i];
    }
    cout<<endl;
    cout<<count<<endl;
    return 0;
}
