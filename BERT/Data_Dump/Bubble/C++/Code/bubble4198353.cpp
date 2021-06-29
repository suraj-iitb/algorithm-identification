#include<iostream>
using namespace std;

int A[107];

int bubbleSort(int A[], int N)
{
    bool isReversed = true; 
    int count = 0;
    int i = 0;
    while (isReversed) {
        isReversed = false;
        for (int j = N-1; j > i; j--) {
            if (A[j] < A[j-1]) {
                int swp = A[j-1];
                A[j-1] = A[j];
                A[j] = swp;
                isReversed = true;
                count++;
            }
        }
        i++;
    }
    return count;
}

int main(void)
{
    int N; 
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int count = bubbleSort(A, N);
    for (int i = 0; i < N-1; i++) {
        cout << A[i] << " ";
    }
    cout << A[N-1] << endl;
    cout << count << endl;
    
    return 0;
}
