#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
void print(){
    bool f = 0;
    for(int p = 0; p < a.size(); p++){
        if(f == 1) cout << ' ';
        cout << a[p];
        f = 1;
    }
    cout << endl;
}
int main(){
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        int tmp = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > tmp){
            a[j + 1] = a[j];//ソート済みの場所の大きさを右側から調べる
            j--;
        }
        a[j + 1] = tmp;//空いたスペースに入れる
        print();
    }
    return 0;
}

