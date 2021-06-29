#include <iostream>
using namespace std;
int out (int a[],int n){
    int i;
    for(i=0;i<n;i++)i==n-1?cout<<a[i]<<endl:cout<<a[i]<<" ";
    return 0;
}
int main(void){
    int n,i,j,num,a[100+1],min,count,v;
    cin>>n;
    for(i=0;i<n;i++)cin>>a[i];
    v=0;
    for(i=0;i<n;i++){
        min=100,count=0;
        for(j=i;j<n;j++){
            if(a[j]<min)min=a[j],num=j,count++;
        }
        if(count>=2)swap(a[i],a[num]),v++;
        
    }
    out(a,n);
    cout<<v<<endl;
    return 0;
}
