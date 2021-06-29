#include<bits/stdc++.h>

using namespace std;

void disp(vector<int> a, int n){
    for(int i = 0;i < n;i++){
        if(i == n-1) cout << a[i];
        else cout << a[i] << " ";
    }
    cout << endl;
}

int bubble(vector<int> a, int n){
    int count = 0;
    int temp = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n-1;j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                count++;
            }
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

    cout << bubble(a, n) << endl;

    return 0;
}
