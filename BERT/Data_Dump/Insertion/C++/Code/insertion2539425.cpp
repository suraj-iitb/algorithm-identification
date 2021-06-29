#include<iostream>
using namespace std;

void insertionSort(int A[],int N)
{
    int v;

    for(int i=1;i<N;i++)
    {

        v=A[i];
       int j=i-1;


        for(int n=0;n<N;n++)
        {
            if(n>0)
                cout<<" ";

         cout<<A[n];

        }
          cout<<endl;
        while(j>=0&&A[j]>v)
        {
            A[j+1]=A[j];
            j--;
            A[j+1]=v;

        }

    }
    for(int i=0;i<N;i++)
    {
        if(i>0)
        cout<<" ";
        cout<<A[i];
    }
    cout<<endl;

}

int main()
{
    int N,a[105];
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>a[i];
    insertionSort(a,N);
    return 0;

}
