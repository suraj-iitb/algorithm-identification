#include <iostream>
using namespace std;

int bubbleSort(int a[],int n){
    bool flag=1;
    int i,j;
    int count=0;
    for (i= 0; i < n&&flag; ++i) {
        flag=0;
        for (j = n-1; j >i ; --j) {
            if (a[j]<a[j-1]){
                swap(a[j],a[j-1]);
                flag=1;
                count++;
            }
        }
    }
    return count;
}

int main() {
    int i,j,n,a[150];
    int sw;
    cin>>n;
    for (i = 0; i < n; ++i) {
        cin>>a[i];
    }

    sw=bubbleSort(a,n);

    for (j = 0; j < n; ++j) {
        if (j>0)
            cout<<" ";
        cout<<a[j];
    }
    cout<<endl;
    cout<<sw<<endl;

    return 0;
}
