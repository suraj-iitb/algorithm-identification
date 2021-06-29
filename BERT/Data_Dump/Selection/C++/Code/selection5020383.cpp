#include <iostream>
#include <string>

using namespace std;

int selection_sort(int a[], int num) {
    
    int   count = 0;
    int   min_idx;
    
    for (int i = 0; i < num; i++) {
        min_idx = i;
        for (int j = i; j < num; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        if (i != min_idx) {
            count++;
        }
        swap(a[i], a[min_idx]);
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
    
    count = selection_sort(a, num);
    for (int i = 0; i < num - 1; i++) {
        cout << a[i] << " ";
    }
    cout << a[num - 1] << endl;
    cout << count << endl;

    return 0;
}

