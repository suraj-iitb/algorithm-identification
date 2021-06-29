#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int cnt;
    cin >> cnt;
    int* num = new int[cnt];
    if (num == NULL) { return -1; }
    for (int i = 0; i < cnt; i++) {
        cin >> num[i];
    }
    int Scnt = 0;
    bool flag = true;
    for (int i = 0; i < cnt; i++) {
        int minj = i;
        for (int j = i; j < cnt; j++) {
            if (num[j] < num[minj]) {
                minj = j;
            }
        }
        if(i!=minj){
            swap(num[i], num[minj]);
            Scnt++;
        }
    }
    for (int i = 0; i < cnt; i++) {
        if (i)cout << ' ';
        cout << num[i];
    }
    cout << endl << Scnt << endl
        ;
    delete num;
    return 0;
}
