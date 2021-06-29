#include <iostream>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    
    int A[N];
    for(int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    
    int count = 0;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = N - 1; j >= i; j--)
        {
            if(A[j] < A[j - 1])
            {
                int T = A[j];
                A[j] = A[j - 1];
                A[j - 1] = T;
                count++;
            }
        }
    }
    
     for(int i = 0; i < N - 1; i++)
    {
        cout << A[i] << " ";
    }
    cout << A[N - 1] << endl;
    
    cout << count << endl;
    
}
