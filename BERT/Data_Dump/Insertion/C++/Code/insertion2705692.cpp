#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    vector<int> a;
    cin>>N;
    a = vector<int>(N);
    for(int i=0;i<N;i++) cin>>a[i];
    for(int i=0;i<N;i++) {
        int k=a[i];
        int j=i-1;
        for(;j>=0 && a[j]>k;j--) a[j+1]=a[j];
        a[j+1] = k;
        cout<<a[0];
        for(j=1;j<N;j++) cout<<" "<<a[j];
        cout<<endl;
    }
    return 0;
}
