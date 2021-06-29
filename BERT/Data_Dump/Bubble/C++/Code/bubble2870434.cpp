#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int cnt;
    cin >> cnt;
    int* num= new int[cnt];
    if (num == NULL) { return -1; }
    for (int i = 0; i < cnt; i++) {
        cin >> num[i];
    }
    int Scnt = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = cnt - 1; i >= 1; i--) {
            if (num[i] < num[i - 1]) {
                swap(num[i], num[i - 1]);
                Scnt++;
                flag = true;
            }
        }
    }
    for (int i = 0; i < cnt; i++) {
        if (i)cout << ' ';
        cout << num[i];
    }
    cout << endl<<Scnt<<endl
        ;
    delete num;
    return 0;
}
