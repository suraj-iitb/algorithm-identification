#include <iostream>
#include <vector>

using namespace std;

void Trace(int A[], int N){
    for(int i=0;i<N;++i){
        if(i>0) cout << " ";
        cout << A[i] ;
    }
    cout << endl;
}

void InsertionSort(int A[],int N){
    for (int i = 1; i < N; ++i)
    {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        Trace(A, N);
    }
}

int main(){
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    Trace(A, N);
    

    InsertionSort(A, N);

    return 0;

}