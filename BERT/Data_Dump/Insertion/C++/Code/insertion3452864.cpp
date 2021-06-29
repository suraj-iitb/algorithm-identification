#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>

#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORN(i, a, b) for (int i = a; i <= b; i++)
#define P(s) cout << s << endl
#define PC(condition, _true, _false) if (condition) _true; else _false;

using namespace std;
//
// Created by karayuu on 2019-3-28.
//

/**
 * 配列の要素を表示します.(1 2 3 4 5)のような感じ.
 *
 * @param a 表示したい配列
 * @param n 配列の要素数
 */
void printArray(const int a[], int n) {
    FOR(i, 0, n) {
        if (i != 0) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int a[1000] = {0};
    FOR(i, 0, n) {
        cin >> a[i];
    }

    printArray(a, n);

    FOR(i, 0, n) {
        //a[0]は無視する
        if (i == 0) continue;

        //a[i]を入れておく
        int v = a[i];
        //探索する一番最後のオリジン
        int o = i - 1;

        //a[0]よりは右にあり,右のほうが大きかったとき
        while (o >= 0 && a[o] > v) {
            //右と入れ替える
            swap(a[o],a[o + 1]);
            o--;
        }

        FOR(j, 0, n) {
            if (j != 0) {
                cout << " ";
            }
            cout << a[j];
        }
        cout << endl;
    }
}
