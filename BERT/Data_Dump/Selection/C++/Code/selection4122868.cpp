#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int SelectionSort(int, int[]);
    int count = SelectionSort(n, a);
    for(int i = 0; i < n - 1; i++)
        cout << a[i] << ' ';
    cout << a[n - 1] << '\n' << count << endl;
    return 0;
}

int SelectionSort(int n, int a[]) {
    int count = 0;
    void swap(int &, int &);
    for(int i = 0, min; i < n - 1; i++) {
        min = i;
        for(int j = i + 1; j < n; j++) 
            if(a[min] > a[j])
                min = j;
        if(min != i) {
            swap(a[min], a[i]);
            count++;
        }
    }
    return count;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
