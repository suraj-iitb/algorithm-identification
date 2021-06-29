#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
void hyouji(int a[], int n){
    int i;
    for(i=0; i<n-1; ++i){
        cout<<a[i]<<" ";
    }
    cout<<a[n-1]<<endl;
}
int main() {
    int i, j, n, k, p, q,v;
    int num = 0;
    int temp = 0;
    int flag = 0;
    cin>>n;
    int r[n];
    for(i=0; i<n; ++i){
        cin>>r[i];
    }
    hyouji(r,n);
    for(i=1; i<n; ++i){
        v=r[i];
        j=i-1;
        while(j>=0&&r[j]>v) {
            r[j + 1] = r[j];
            --j;
        }
        r[j+1]=v;
        hyouji(r,n);
    }

    return 0;
}
