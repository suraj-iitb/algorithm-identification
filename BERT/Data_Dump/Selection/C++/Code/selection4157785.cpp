#include<iostream>

using namespace std;
#define MAX_INT 1000

int A[MAX_INT];

int selectionSort(int* A, int N)
{
    int count=0;
    for(int i=0;i<N;++i)
    {
        int minj =i;
        for(int j=i;j<N;++j)
        {
            if(A[j]<A[minj])
            {
                minj = j;
            }
        }
        if(minj !=i)
        {
            int tmp;
            tmp = A[i];
            A[i] =A[minj];
            A[minj]=tmp;
            count ++;
        }
    }
    for(int k=0;k<N;k++)
    {
        if(k<N-1) cout << A[k] << " ";
        if(k==N-1) cout<< A[k]<<endl;
    }
    return count;
}

int main()
{
    int N;cin >>N;
    for(int i=0;i<N;++i)
    {
        cin >> A[i];
    }

    cout << selectionSort(A,N)<<endl;
    return 0;
}
