#include <iostream>
using namespace std;

int main(){
    int n,count=0;
    cin >> n;
    int a[100];
    for(int i=0;i<n;i++)cin>>a[i];
    
    for(int i=0;i<n;i++){
        int minj=i;
            for(int j=i;j<n;j++){
                if(a[j]<a[minj]){
                    minj=j;
                    
                }
            }
            if(i!=minj){
            swap(a[minj],a[i]);
            count++;
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
