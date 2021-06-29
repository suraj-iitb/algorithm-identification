#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=1;i<n;i++){
        int v=a[i];
        int j=i-1;
        for (int k=0;k<n-1;k++){
                cout<<a[k]<<" ";
        }
        cout<<a[n-1]<<endl;
        while(j>=0&&a[j]>v){
            int t=a[j+1];
            a[j+1]=a[j];
            a[j]=t;
            j--;
        }
        a[j+1]=v;
    }
    for (int k=0;k<n-1;k++){
        cout<<a[k]<<" ";
    }cout<<a[n-1]<<endl;
    return 0;
}
