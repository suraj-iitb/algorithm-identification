#include <iostream>
#include <vector>

using namespace std;

void Trace(int A[], int N)
{
    for (int i = 0; i < N; ++i)
    {
        if (i > 0)
            cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int SelectionSort(int A[], int N)
{
    int sw = 0;
    for(int i=0;i<N;++i){
        int minj = i;
        for(int j=i;j<N;++j){
            if(A[j] < A[minj]) minj = j;
        }
        if(A[i]!=A[minj]){
            swap(A[i],A[minj]);
            sw++;
        }
    }
    return sw;
}

int main()
{
    int N, sw;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    sw = SelectionSort(A, N);
    Trace(A, N);
    cout << sw << endl;

    return 0;
}
