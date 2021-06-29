#include <iostream>
using namespace std;

int selectionSort(int a[],int n){
    int i,j,min_pos;
    int sw=0;
    for (i = 0; i < n-1; ++i) {
        min_pos=i;
        for (j = i; j < n; ++j) {
            if (a[j]<a[min_pos])
                min_pos=j;
        }
        swap(a[i],a[min_pos]);
        if (min_pos!=i)
            sw++;
    }
    return sw;
}

int main() {
    int n,i,j,sw;
    int a[150];
    cin>>n;
    for (i = 0; i < n; ++i) {
        cin>>a[i];
    }
    sw=selectionSort(a,n);

    for (j = 0; j < n; ++j) {
        if (j>0)
            cout<<" ";
        cout<<a[j];
    }
    cout<<endl;
    cout<<sw<<endl;

    return 0;
}
