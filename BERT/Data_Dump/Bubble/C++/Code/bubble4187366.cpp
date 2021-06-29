#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> A, int N);

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for (int i=0; i<N; i++) {
        cin >> A.at(i);
    }
    
    bubbleSort(A, N);
}

void bubbleSort(vector<int> A, int N) {
    int flag = 1;
    int i = 0;
    int count = 0;
    while (flag) {
        flag = 0;
        for (int j = N-1; j >= i+1; j--) {
            if (A.at(j-1) > A.at(j)) {
                int tmp = A.at(j);
                A.at(j) = A.at(j-1);
                A.at(j-1) = tmp;
                count ++; // 入れ替え回数を記録
                flag = 1; // 入れ替えが１つでもあったら1
            } // 入れ替えが1つもなかったらソート完了
        }
        i++;
    }
    
    for (int i=0; i<N; i++) {
        cout << A.at(i);
        if (i == N-1) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }
    
    cout << count << endl;
}


