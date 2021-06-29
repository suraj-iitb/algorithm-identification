// ALDS1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//C:\Users\bbtos\source
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

vector<vector<int>> A(100000, vector<int>(2));

int pos(vector<vector<int>> A, int mn, int n) {
    //cout << "mn:" << mn << " n:" << n << endl;
    int count;
    for (count = 0; count < A.size();count++) {
        if (A.at(count).at(0) == mn && A.at(count).at(1) == n) {
            return count;
        }
    }
}

int partition(int p, int r) {
    int x = A.at(r).at(1);
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A.at(j).at(1) <= x) {
            i++;
            swap(A.at(i), A.at(j));
        }
    }
    swap(A.at(i + 1), A.at(r));
    return i + 1;
}
void quicksort(int p, int r) {
    if (p < r) {
        int q = partition(p, r);
        quicksort(p, q - 1);
        quicksort(q + 1, r);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char ch;
        cin >> ch >> A.at(i).at(1);
        if (ch == 'S') A.at(i).at(0) = 0;
        else if (ch == 'H') A.at(i).at(0) = 1;
        else if (ch == 'C') A.at(i).at(0) = 2;
        else A.at(i).at(0) = 4;
    }

    vector<vector<int>> B = A;

    quicksort(0, n - 1);
    
    string ans = "Stable";

    for (int i = 1; i < n; i++) {
        if (A.at(i - 1).at(1) == A.at(i).at(1)) {
            int a = pos(B, A.at(i - 1).at(0), A.at(i - 1).at(1));
            int b = pos(B, A.at(i).at(0), A.at(i).at(1));
            //cout << a << " " << b << endl;
            
            if (a > b) {
                ans = "Not stable";
                break;
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        char ch;
        if (A.at(i).at(0) == 0) ch = 'S';
        else if (A.at(i).at(0) == 1) ch = 'H';
        else if (A.at(i).at(0) == 2) ch = 'C';
        else ch = 'D';
        cout << ch << " ";
        cout << A.at(i).at(1) << endl;
    }
    return 0;
}
