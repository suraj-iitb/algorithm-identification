#include<bits/stdc++.h>

using namespace std;
const int MAX_N = 500000;

int c[500000];
int tot = 0;

int merge_sort(int a[], int left, int right) {
    if (left >= right)return 1;//如果就一个元素，直接结束

    int mid = (left + right) / 2;

    /*
     * 不断划分
     * */
    merge_sort(a, left, mid);
    merge_sort(a, mid + 1, right);
    int i = left, j = mid + 1, k = left;

    /*
     * 划分到最后只有单个元素的时候进行比较排序
     * */
    while (i <= mid && j <= right) {
        ++tot;
        if (a[i] < a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }

    //把最后一个元素直接添加到末尾
    while (i <= mid){
        c[k++] = a[i++];
        ++tot;
    }
    while (j <= right){
        c[k++] = a[j++];
        ++tot;
    }
    for (i = left; i <= right; i++)a[i] = c[i];
    return tot;

}

int main() {

    int a[MAX_N];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    merge_sort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if(i)cout<<" ";
        cout << a[i] ;
    }
    cout << endl ;
    cout<<tot<<endl ;

    return 0;
}
