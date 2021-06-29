#include <iostream>
#include <algorithm>
using namespace std;


int bubblesort(int A[], int N)
{
    int sw = 0;
    for(int i=0; i< N-1;i++)
    {
        for(int j=0; j<N-i-1 ; j++)
        {
            if(A[j] > A[j+1])
            {
                //int temp = A[j];
                //A[j] = A[j+1];
                // A[j+1] = temp;
                swap(A[j], A[j+1]);
                ++sw;
            }
        }
    }
    return sw;
}
int main()
{
    int A[100], N, sw;
    cin >> N;
    for(int i=0; i<N; ++i) cin >> A[i];
    
    sw = bubblesort(A,N);
    
    for(int i=0; i<N; ++i)
    {
        if(i) cout<< " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
    return 0;
    
    
}
