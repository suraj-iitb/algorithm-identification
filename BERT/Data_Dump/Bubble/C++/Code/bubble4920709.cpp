#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int bubbleSort(vector<int>& A) {
    int cnt = 0;

    // 存在顺序相反的两个元素
    bool flag = 1;
    int i = 0;
    while (flag) {
        flag = 0;
        // 这里是把从末尾开始，把小的交换到开头
        // 也可以是从开头开始，把大的交换到末尾
        for (int j = A.size() - 1; j > i; --j) {
            // A[j] <= A[j - 1]则失去稳定性
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = 1;
                ++cnt;
            }
        }
        ++i;
    }

    return cnt;
}

int main() {
    int N;
    vector<int> A;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int v;
        cin >> v;
        A.push_back(v);
    }

    int cnt = bubbleSort(A);
    for (int i = 0; i < A.size() - 1; ++i) {
        cout << A[i] << " ";
    }
    cout << A.back() << endl;
    cout << cnt << endl;

    return 0;
}
