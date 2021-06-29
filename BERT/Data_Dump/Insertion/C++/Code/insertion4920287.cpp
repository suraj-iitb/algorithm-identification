#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& A) {
    for (int i = 1; i < A.size(); ++i) {
        // key为要插入的值
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = key;

        for (int i = 0; i < A.size() - 1; ++i) {
            cout << A[i] << " ";
        }
        cout << A.back() << '\n';
    }
}

int main() {
    int N;
    vector<int> A;

    // 初始化数据
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int v;
        cin >> v;
        A.push_back(v);
    }

    // 输出原始数组
    for (int i = 0; i < A.size() - 1; ++i) {
        cout << A[i] << " ";
    }
    cout << A.back() << '\n';
    // 输出各个排序步骤
    insertionSort(A);
    
    return 0;
}
