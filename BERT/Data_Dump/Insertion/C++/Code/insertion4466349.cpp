#include <iostream>
using namespace std;

int main(){
    int num;
    int n[1000];
    cin >> num;

    for (int i = 0; i<num; i++){
        cin >> n[i];
    }
    for (int i = 1; i<num; i++){ // 確かめる配列の番号
        for (int p = 0; p < num; p++){
            cout << n[p];
            if (p < num -1) cout << " ";
        }
        for (int j=0; j<i; j++){    //
            if (n[i] < n[j]){ //小さければ
                int tmp = n[j];
                n[j] = n[i];
                n[i] = tmp;
            }
        }
        cout << endl;
    }
    for (int p = 0; p < num; p++){
        cout << n[p];
        if (p < num -1) cout << " ";
    }
    cout << endl;
}
