#include<iostream>
using namespace std;
int main()
{
    int N;
    int A[100];
    int num = 0;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        cin >> A[i];
    }
    for(int i=0; i<N-1;i++)
    {
        for(int j=N-1; j>i; j--)
        {
            if(A[j-1] > A[j])
            {
                int temp = A[j-1];
                A[j-1] = A[j];
                A[j] = temp;
                num++;
            }
        }
    }
    for(int i=0; i<N;i++)
    {
        if(i) cout<<" ";
        cout<<A[i];
    };
    cout<<endl<<num<<endl;
}

