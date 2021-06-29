//参考答案 C++
#include<iostream>
using namespace std;

const int maxn = 101;
int n, a[100];
int cnt;

int bubbleSort(int a[], int n) {//使用flag的冒泡排序法
    int cnt = 0;
    bool flag = true;
    for (int i = 0; flag; i++) {
        flag = false;
        for (int j = n - 1; j > i ; j--) {//1.升序降序排列，按实际需要修改。
        //2.升序降序遍历，按给出数组的大致排列，确定
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                flag = true;
                cnt++;
            }
        }
    }
    return cnt;
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cnt = bubbleSort(a, n);
    for (int i = 0; i < n; i++) {
        if (i)  cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
