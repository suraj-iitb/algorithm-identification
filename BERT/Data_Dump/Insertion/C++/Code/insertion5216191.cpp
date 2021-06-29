#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
    for(int i=1;i<n;i++){
        int v,j=i;
        v=a[i];
        while(j-1>=0&&a[j-1]>v){
            a[j]=a[j-1];
            a[j-1]=v;
            v=a[j-1];
            j--;
        }
        for(int k=0;k<n-1;k++){
            cout<<a[k]<<" ";
        }
        cout<<a[n-1]<<endl;
    }
    return 0;
}
