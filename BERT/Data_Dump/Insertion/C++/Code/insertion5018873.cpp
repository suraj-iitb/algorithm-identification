#include <iostream>
#include <string>

using namespace std;

void print_array(int a[], int num) {
    
    for (int i = 0; i < num - 1; i++) {
        cout << a[i] << " ";
    }
    cout << a[num - 1] << endl;
}

void insertion_sort(int a[], int num) {
    
    int  tmp, j;
    
    for (int i = 1; i < num; i++) {
        tmp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > tmp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = tmp;
        print_array(a, num);
    }
}

int main(void) {
    
    int  num;
    int  a[100];
    
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> a[i];
    }

    print_array(a, num);
    insertion_sort(a, num);

    return 0;
}

