#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &a){

}

int main(){
    //入力
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    
    //処理
    int counter = 0;
    for(int i=0; i<n; i++){
        for(int j=n-1; j>i; j--){
            if(a[j]<a[j-1]) {
                int tmp = a[j];
                a[j] = a[j-1];
                a[j-1] = tmp;
                counter++;
            }
        }
    }

    //出力
    for(int i=0; i<n; i++){
        if(i<n-1) cout << a[i] << " ";
        else cout << a[i] << endl;
    }
    cout << counter << endl;
    
    return 0;
}
