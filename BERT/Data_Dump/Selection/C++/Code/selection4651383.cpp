#include<iostream>
using namespace std;

int main(){
    int n;
    int count=0;
    int a[100];
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    
    for(int i=0;i<n;i++){
        int minj=i;
        for(int j=i;j<n;j++){
            if(a[minj]>a[j]){
                minj=j;
            }
        }
        if(minj != i){
            int z=a[minj];
            a[minj]=a[i];
            a[i]=z;
            count++;
        }
    }
    for(int i=0;i<n;i++)cout<<a[i]<<((i==n-1)?'\n':' ');
    cout<<count<<endl;
    return 0;
}
