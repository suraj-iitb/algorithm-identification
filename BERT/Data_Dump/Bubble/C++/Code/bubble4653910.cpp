#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

// void func(type &variable)とすることで参照渡しとなる。
void STLSort(vector<int> &x){
    sort(x.begin(), x.end());
}

void printVec(vector<int> x, int n){
    for(int i = 0; i < n - 1; i++){
        cout << x.at(i) << " ";
    }
    cout << x.at(n - 1);
}
void insertionSort(vector<int> &x, int n){
    //
    for(int i = 1; i < n; i++){
        printVec(x, n);
        cout << endl;

        int v = x.at(i);
        int j = i - 1;
        while(j  >= 0 && x.at(j) > v){
            x.at(j + 1) = x.at(j);
            j--;
        }
        x.at(j + 1) = v;
    }
}

int bubbleSort(vector<int> &x, int n){
    int flag = 1;
    int cnt = 0;
    // swapが無くなったらループ終了
    while(flag){
        flag = 0;
        for(int j = n - 1; j > 0; j--){
            if(x.at(j) < x.at(j-1)){
                int tmp = x.at(j-1);
                x.at(j-1) = x.at(j);
                x.at(j) = tmp;
                flag = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    int n; cin >> n;
    vector<int> x(n);

    rep(i, n){
        cin >> x.at(i);
    }

    int swap_cnt = 0;

    swap_cnt = bubbleSort(x, n);
    printVec(x, n);
    cout << endl;
    cout << swap_cnt << endl;

}

