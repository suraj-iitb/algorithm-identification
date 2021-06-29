//参考答案 C++
#include<iostream>
using namespace std;

const int maxn = 100;
int n, a[maxn];

void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        if (i)  cout << " ";
        cout << a[i];
    }
    cout << endl;
}

void insertSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
        print(a, n);
  
    
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    print(a, n);//第一次打印，原数组
    insertSort(a, n);//插入排序+打印
    return 0;
}
