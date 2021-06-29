#include <iostream>
#define rep(i,n) for (int i=0; i<n;i++)
using namespace std;

int bubbleSort(int a[], int n){
    int sw = 0;
    bool flag = 1;
    for(int i=0;flag;i++){
        flag = 0;
        for(int j=n-1; j >= i + 1; j--){
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                flag = 1;
                sw++;
            }
        }
    }
    return sw;
}

int main(){
    int a[100], n, sw;
    cin >> n;
    rep(i,n) cin >> a[i];

    sw = bubbleSort(a,n);

    rep(i,n){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << sw << endl;

    return 0;
}
