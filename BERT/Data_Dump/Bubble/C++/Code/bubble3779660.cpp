#include <iostream>


using namespace std;


void print_arr(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        cout << arr[i] << " ";
    cout << arr[size - 1] << endl;
}


void bubble_sort(int A[], int N, int *cnt)
{
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                int t = A[j + 1];
                A[j + 1] = A[j];
                A[j] = t;
                (*cnt)++;
            }
        }
    }
}


int main(void)
{
    int N;
    int A[101];

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int cnt = 0;
    bubble_sort(A, N, &cnt);
    print_arr(A, N);
    cout << cnt << endl;

    return 0;
}

