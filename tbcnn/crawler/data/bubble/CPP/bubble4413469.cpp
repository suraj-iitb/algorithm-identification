#include <iostream>
using namespace std;

#define rep(s, e) for(int i(s); i < e; ++i)

#define N 100

int number_of_exchange(0);
void peek(int[], int);
void swap(int*, int*);
void bubble_sort(int[], int);

int main() {
    int n(0);
    int *A = new int[N];

    cin >> n;

    rep(0, n) {
        cin >> A[i];
    }

    bubble_sort(A, n);
    peek(A, n);
    cout << number_of_exchange << "\n";
    return 0;
}

void peek(int A[], int n) {
    rep(0, n) {
        if(i != 0) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << "\n";
}

void swap(int *a, int *b) {
    int tmp(*a);
    *a = *b;
    *b = tmp;
}

void bubble_sort(int A[], int n) {
    int flag(1);
    while(flag) {
        flag = 0;
        for(int j(n-1); j >= 1; --j) {
            if(A[j] < A[j-1]) {
                swap(A+j, A+(j-1));
                flag = 1;
                number_of_exchange++;
            }
        }
    }
}

