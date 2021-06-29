#include <iostream>


using namespace std;


void print_arr(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
        cout << arr[i] << " ";
    cout << arr[size - 1] << endl;
}


void insertion_sort(int arr[], int size)
{
    for (int i = 1; i < size; i++) {
        print_arr(arr, size);
        int v, j;
        v = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] >= v) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = v;
    }
}


int main(void)
{
    int N;
    int A[101];

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    insertion_sort(A, N);
    print_arr(A, N);

    return 0;
}

