#include<bits/stdc++.h>

using namespace std;

void disp(vector<int> a, int n){
    for(int i = 0;i < n;i++){
        if(i == n-1) cout << a[i];
        else cout << a[i] << " ";
    }
    cout << endl;
}

int select(vector<int> a, int n){
    int count = 0;
    for(int i = 0;i < n;i++){
        int minj = i;
        for(int j = i;j < n;j++){
            if(a[j] < a[minj]) minj = j;
        }
        if(i != minj){
            swap(a[i], a[minj]);
            count++;
        }
    }
    disp(a, n);
    return count;
}

int main(void){

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    cout << select(a, n) << endl;

    return 0;
}
