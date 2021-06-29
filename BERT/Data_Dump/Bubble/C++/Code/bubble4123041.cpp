#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int* a = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int BubbleSort(int, int[]);
    int count = BubbleSort(n, a);
    for(int i = 0; i < n - 1; i++)
        cout << a[i] << ' ';
    cout << a[n - 1] << '\n' << count << endl;
    return 0;
}

int BubbleSort(int n, int a[]) {
    int count = 0;
    void swap(int&, int&);
    for(int i = 0; i < n - 1; i++) 
        for(int j = n - 1; j > i; j--) 
            if(a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                count++;
            }
    return count;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
