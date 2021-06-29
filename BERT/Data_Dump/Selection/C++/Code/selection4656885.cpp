#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int selectionSort(vector<int> &x, int n){
    int swap_cnt = 0;
    for(int i = 0; i < n; i++){
        int minj = i;

        for(int j = i; j < n; j++){
            if(x.at(j) < x.at(minj)){
                minj = j;
            }
        }

        if(i != minj){
            swap_cnt++;
            int tmp = x.at(i);
            x.at(i) = x.at(minj);
            x.at(minj) = tmp;
        }
    }
    return swap_cnt;
}

void printVec(vector<int> x, int n){
    rep(i, n-1){
        cout << x.at(i) << " ";
    }
    cout << x.at(n-1) << endl;
}

int main(){
    int n; cin >> n;
    vector<int> x(n);
    rep(i, n){
        cin >> x.at(i);
    }
    int cnt = selectionSort(x, n);

    printVec(x, n);
    cout << cnt << endl;
}
