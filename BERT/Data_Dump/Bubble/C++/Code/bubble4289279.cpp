#include <algorithm>
#include <iostream>
#include <math.h>
using namespace std;
void trace(int N, int A[]) {
    for(int i = 0; i < N; i++) {
        if(i >= 1) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
}

void swap(int a[], int n1, int n2) {
    int temp = a[n1];
    a[n1] = a[n2];
    a[n2] = temp;
}

int bubble_sort(int n, int a[]) {
    int count=0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = n - 1; i < j; j--) {
            if(a[j - 1] > a[j]) {
                swap(a, j, j - 1);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int N,count;
    cin >> N;
    int data[N];
    for(int i = 0; i < N; i++)
        cin >> data[i];
    count = bubble_sort(N, data);
    trace(N, data);
    cout << count << endl;
    return 0;
}
