#include<iostream>
using namespace std;
int main()
{
    int A[100];
    int N;
    int num = 0;
    int minj;
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> A[i];
    for(int i=0; i<N-1;i++)
    {
        minj = i;
        for(int j=i+1; j<N; j++)
        {
            if(A[j] < A[minj])
            {
             //   min = A[j];
                minj = j;
            }
        }
        if(minj != i)
        {
            int temp = A[i];
            A[i] = A[minj];
            A[minj] = temp;
            num++;
        }
        
    }
    for(int i=0; i<N; i++)
    {
        if(i) cout<<" ";
        cout<<A[i];
    }
    cout<<endl<<num<<endl;
}
