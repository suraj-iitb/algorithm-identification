#include<iostream>
using namespace std;

int selectionSort(int A[], int N){
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        int min = A[i];
        int j_min = i;
        for (int j = i; j < N; j++) {
            if(A[j] < min) {
                min = A[j];
                j_min = j;
            }
        }
        if (i != j_min){
            swap(A[i], A[j_min]);
            count++;
        }
    }
    return count;
}

int main(void)
{
    int N;
    int A[107];
    cin >> N; 
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int count = selectionSort(A, N);
    
    for (int i = 0; i < N-1; i++) {
        cout << A[i] << " ";
    }
    cout << A[N-1] << endl;
    cout << count << endl;
    
    return 0;
}
