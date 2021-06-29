#include<iostream>
using namespace std;

 #define NMAX 2000000
 #define AMAX 10000

int main(){
    int n,a[NMAX+1],b[NMAX+1],c[AMAX+1];
    cin>>n;
    for(int i=0;i<=AMAX;i++) c[i]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        c[a[i]]++;
    }
    for(int i=1;i<=AMAX;i++) c[i]+=c[i-1];
    for(int i=n;i>0;i--){
        b[c[a[i]]]=a[i];
        c[a[i]]--;
    }    
    for(int i=1;i<=n;i++){
        cout<<b[i]<<((i==n)?'\n':' ');
    }
}
