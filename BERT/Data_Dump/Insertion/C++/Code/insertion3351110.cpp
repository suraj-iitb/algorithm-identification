#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    int n,chukei;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    for(int i=0;i<n;++i){
        cout<<a[i];
        if(i!=n-1){
            cout<<" ";
        }
    }
        cout<<endl;
    for(int i=1;i<n;++i){
        for(int j=i;j>=0;--j){
            if(a[j]<a[j-1]){
                chukei=a[j-1];
                a[j-1]=a[j];
                a[j]=chukei;
            }
        }
        for(int i=0;i<n;++i){
            cout<<a[i];
            if(i!=n-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}

