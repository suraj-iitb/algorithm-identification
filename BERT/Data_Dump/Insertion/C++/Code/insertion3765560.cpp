#include <iostream>
#include <vector>
using namespace std;

void print_array(vector<int> &A) {
    for (int i = 0; i < (int)A.size(); i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void insertion_sort(vector<int> &A) {
    int N = (int)A.size();
    for (int i = 1; i < N; i++) {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
        print_array(A);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    print_array(A);
    insertion_sort(A);

    return 0;
}
