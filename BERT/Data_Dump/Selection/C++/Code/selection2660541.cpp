#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int count=0;

    for (int i=0;i<n;i++){
        int min_idx=i;
        for(int j=i; j<n; j++){
            if(a[min_idx]>a[j]) {
                min_idx=j;
            }
        }
        if(min_idx != i) {
            swap(a[i], a[min_idx]);
            count += 1;
        }
    }


    for(int k = 0;k<n-1;k++)
        cout<<a[k]<<' ';
    cout<<a[n-1];
    cout<<endl;
    cout<<count<<endl;

    return 0;
}
