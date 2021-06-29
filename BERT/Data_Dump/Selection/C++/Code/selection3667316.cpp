#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int n;cin>>n;
    int a[n];for (int i=0;i<n;i++)cin>>a[i];
    int c=0;
    for(int i=0;i<n;i++){
        int minj=i;
        for(int j=i;j<n;j++){
            if (a[j]<a[minj]){
                minj=j;
                 
            }
            
        }
        int b=a[i];a[i]=a[minj]; a[minj]=b;
        if(i!=minj)c+=1;
       
    }
    for (int k=0;k<n-1;k++){cout<<a[k]<<" ";}cout<<a[n-1]<<endl;
    cout<<c<<endl;
}

