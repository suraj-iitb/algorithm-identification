#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n;cin>>n;
    int a[n];
    for (int i=0;i<n;i++)cin>>a[i];
   
    int flag=1;
    int c=0;
    while (flag){
        flag=0;
        for(int j=n-1;j>=1;j--){
            
            if (a[j]<a[j-1]){
                int b=a[j];
                a[j]=a[j-1];
                a[j-1]=b;
                flag=1;
                c+=1;
            }
        }
        
    }for (int k=0;k<n-1;k++){cout<<a[k]<<" ";}cout<<a[n-1]<<endl;
    cout<<c<<endl;
}
