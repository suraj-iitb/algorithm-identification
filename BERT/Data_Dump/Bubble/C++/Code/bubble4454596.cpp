#include <iostream>
using namespace std;
int BubbleSort(int A[],int N){
    int sw=0;
    bool fl=1;
    for (int i = 0; fl ; ++i) {
        fl=0;
        for (int j = N-1; j >= i+1; --j) {
            if(A[j]<A[j-1]){
                swap(A[j],A[j-1]);
                fl=1;
                sw++;
            }
        }
    }
    return sw;
}
int main() {
    int n,i,j,a[110],sw;
    cin>>n;
    for (i = 0; i < n; ++i) cin>>a[i];
    sw=BubbleSort(a,n);
    for (int i = 0; i < n; ++i) {
        if(i) cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
    cout<<sw<<endl;
    return 0;
}
