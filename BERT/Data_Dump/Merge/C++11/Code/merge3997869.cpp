#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <sstream>
 #include <string>
using namespace std;

void merge(vector<int> &A, int left, int mid, int right, int &count) {
    // cout << "--- merge ---\n";
    // for (int i = 0; i < A.size(); ++i)
    // {
    //     cout << A[i] << " ";
    // }
    // cout << endl;

    //左用の配列と右用の配列を作る
    int size_left  = mid - left;
    int size_right = right - mid;
    vector<int> L(size_left + 1), R(size_right + 1);

    //各配列に要素をコピーする
    // cout << "     --- vector<int> L ---\n";
    for (int i = 0; i < size_left; ++i)
    {
        L[i] = A[left + i];
        // printf("     %d\n", L[i]);
    }
    // cout << endl;
    // cout << "     --- vector<int> R ---\n";
    for (int i = 0; i < size_right; ++i)
    {
        R[i] = A[mid + i];
        // printf("     %d\n", R[i]);
    }
    // cout << endl;

    //番兵
    //  "サイズ+1"の配列を作っているので、"size_x"に入れても大丈夫("size_x-1"でなくて良い)
    L[size_left]  = INT_MAX;
    R[size_right] = INT_MAX;

    //ソート
    //  分割した2つの配列から昇順になるように要素をもとの配列に戻す
    //     -> 再帰により「要素1」の配列に分解されたあとに統合していくので、L・Rは昇順にソートされている
    int i = 0;
    int j = 0;
    for (int k = left; k < right; ++k)
    {
        count++;
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(vector<int> &A, int left, int right, int &count) {
    //分割できなくなったら終了
    if(left + 1 >= right) {
        return;
    }

    //ソート
    int mid = (left + right) / 2;
    // cout << "mid : " << mid << endl;
    mergeSort(A, left, mid, count);
    mergeSort(A, mid , right, count);
    merge(A, left, mid, right, count);
    
}


int main() {
    int n;
    cin >> n;

    vector<int> S(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> S[i];
    }

    //ソート
    int count = 0; //ソートの交換回数
    mergeSort(S, 0, n, count);

    //出力
    for (int i = 0; i < n; ++i)
    {
        cout << S[i];
        if(i < n-1) {
            cout << " ";
        }
    }
    cout << endl;
    cout << count << endl;


    return 0;
}

