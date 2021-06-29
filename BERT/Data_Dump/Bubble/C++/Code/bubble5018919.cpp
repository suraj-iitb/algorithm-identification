#include <iostream>
#include <string>

using namespace std;

int bubble_sort(int a[], int num) {
    
    int   count = 0;
    bool  gyaku_exist = 1;  // 逆の隣接要素が存在する
    
    for (int i = 0; gyaku_exist; i++) {
        gyaku_exist = 0;
        for (int j = num - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                swap(a[j], a[j - 1]);
                gyaku_exist = 1;
                count++;
            }
        }
    }
    
    return count;
}

int main(void) {
    
    int  num;
    int  a[100];
    int  count = 0;
    
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> a[i];
    }
    
    count = bubble_sort(a, num);
    for (int i = 0; i < num - 1; i++) {
        cout << a[i] << " ";
    }
    cout << a[num - 1] << endl;
    cout << count << endl;


    return 0;
}

