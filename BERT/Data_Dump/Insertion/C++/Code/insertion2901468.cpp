#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,v,j;cin>>n;
    int A[n+1];
    for(int i=0;i<n;i++)cin>>A[i];
    for(int i=0;i<n-1;i++)cout<<A[i]<<' ';cout<<A[n-1]<<endl;
    for(int i=1;i<n;i++){
        v = A[i];
        j = i -1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        A[j+1] = v;
        }
        for(int i=0;i<n-1;i++)cout<<A[i]<<' ';cout<<A[n-1]<<endl;
    }
}

