#include<bits/stdc++.h>

using namespace std;

void disp(vector<int> a, int n){
    for(int i = 0;i < n;i++){
        if(i == n-1) cout << a[i];
        else cout << a[i] << " ";
    }
    cout << endl;
}

void insertSort(vector<int> a, int n){
    for(int i = 1;i < n;i++){
        int v = a[i];
        int j = i-1;
        for(;j >= 0;j--){
            if(v < a[j]){
                a[j+1] = a[j];
            }else{
                break;
            }
        }
        a[j+1] = v;
        disp(a, n);
    }
}

int main(void){
    
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];
    
    disp(a, n);
    insertSort(a, n);
    
    return 0;
}
