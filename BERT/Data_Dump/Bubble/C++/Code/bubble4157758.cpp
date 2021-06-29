#include<iostream>

using namespace std;

#define MAX_INT 1000

int A[MAX_INT];

int bubbleSort(int*A, int N)
{
    int count=0;
    bool flg =true;

    while(flg)
    {
        flg =false;
        for(int j=N-1;j>0;--j)
        {
            if(A[j] < A[j-1])
            {
                int tmp;
                tmp = A[j-1];
                A[j-1] = A[j];
                A[j]=tmp;
                flg =true;
                count ++;
            }
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
    int N; cin >>N;

    for(int i =0;i< N; ++i)
    {
        cin >> A[i];
    }

    cout<<bubbleSort(A,N)<<endl;
    return 0;
}
