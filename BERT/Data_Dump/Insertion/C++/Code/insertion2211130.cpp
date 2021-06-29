#include <iostream>
using namespace std;

int main() {
    int n=100;
    int k[n];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k[i];
    }
    
    for(int i=0; i<n; i++){
        int v = k[i];
        int j = i-1;
        while(j>=0 && k[j]>v){
            k[j+1]=k[j];
            j--;
        }
        k[j+1]=v;
        for(int m=0;m<n;m++){
            cout << k[m] << (m+1<n ? " " : "\n");
            //printf("%d",k[m]);
            //printf(" ");
        }
    }
    return 0;
}
