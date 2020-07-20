#include <iostream>
using namespace std;
int main(void){
    int n,i,j,a[100+1],tmp,count=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<n;i++){
        for(j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                tmp=a[j];
                a[j]=a[j-1];
                a[j-1]=tmp;
                count++;
            }
        }
    }
    for(i=0;i<n;i++){
        i==n-1?cout<<a[i]<<endl:cout<<a[i]<<" ";
    }
    cout<<count<<endl;
    return 0;
}
