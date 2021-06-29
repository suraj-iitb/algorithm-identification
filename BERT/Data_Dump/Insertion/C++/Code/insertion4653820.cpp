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

int main(){
    int n; cin >> n;
    vector<int> x(n);

    rep(i, n){
        cin >> x.at(i);
    }

    insertionSort(x, n);
    printVec(x, n);
    cout << endl;

}

