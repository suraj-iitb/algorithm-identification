#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <sstream>
 #include <string>
using namespace std;

void print(vector<int> &v) {
    int n = (int)v.size();

    for (int i = 0; i < n; ++i)
    {
        cout << v[i];
        if(i < n - 1) {
            cout << " ";
        }
    }
    cout <<endl;
}


void CountingSort(vector<int> &A, vector<int> &B, int k) {
    //各数値の出現数を記録するための配列
    vector<int> C(k + 1, 0); //数値"0～k"の出現数を記録するので、要素数は"k+1"必要

    //各数値の出現数を記録する
    for (int i = 0; i < (int)A.size(); ++i)
    {
        C[A[i]]++; //ex. "2"はC[2]に、"5"はC[5]に保存
    }

    //C[i]に、i以下の数値の出現数を記録する
    for (int i = 1; i < (int)C.size(); ++i)
    {
        C[i] += C[i-1]; //ex C[3]には3以下の出現回数、C[5]には5以下の出現回数を記録
    }

    // print(C);


    for (int i = (int)A.size()-1; i >= 0; --i)
    {
        // cout << " ------" << endl;
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
        // print(C);
        // print(B);
    }
}


int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    int maximun = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
        maximun = max(maximun, A[i]);
    }

    vector<int> ans(n, 0);
    CountingSort(A, ans, maximun);

    print(ans);

    return 0;
}

