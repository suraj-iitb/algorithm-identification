#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int a[110];

int main(){
    int N,c=0,minj;
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    for(int i=0;i<=N-1;i++){
        minj=i;
        for(int j=i;j<=N-1;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        swap(a[i],a[minj]);
        if(i!=minj) c++;
    }
    for(int i=0;i<N;i++){
        if(i==N-1) cout<<a[i]<<endl;
        else cout<<a[i]<<" ";
    }
    cout<<c<<endl;
    return 0;
}

