#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int a[110];

int main(){
    int N,c=0,f=1;
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    while(f){
        f=0;
        for(int i=N-1;i>=1;i--){
            if(a[i]<a[i-1]){
                swap(a[i],a[i-1]);
                c++;
                f=1;
            }
        }
    }
    for(int i=0;i<N;i++){
        if(i==N-1) cout<<a[i]<<endl;
        else cout<<a[i]<<" ";
    }
    cout<<c<<endl;
    return 0;
}

