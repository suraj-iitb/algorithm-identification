#include<iostream>
using namespace std;

void print(int A[],int N)
{
    for(int i=0;i<N;i++)
    {
        if(i>0)
            cout<<" ";
        cout<<A[i];
    }
    cout<<endl;
}

int selectSort(int A[],int N)
{
    int i,minj,sum=0;
    for(i=0;i<N;i++)
    {
        minj=i;
        for(int j=i;j<N;j++)
        {
            if(A[j]<A[minj])
                minj=j;
        }

       
        if(A[minj]!=A[i])
        {
           int temp;
           temp=A[minj];
           A[minj]=A[i];
           A[i]=temp;
           sum++;
        }


    }
     print(A,N);
     return sum;

}
int main()
{
    int N,A[100],sum;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
   sum= selectSort(A,N);
   cout<<sum<<endl;
   return 0;

}
