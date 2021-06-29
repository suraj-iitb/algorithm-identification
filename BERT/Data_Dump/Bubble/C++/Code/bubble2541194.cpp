#include<iostream>
using namespace std;
void print(int a[],int N)
{
    for(int i=0;i<N;i++)
    {
        if(i>0)
            cout<<" ";
        cout<<a[i];
    }
    cout<<endl;
}
int  bubbleSort(int a[],int N)
{
    int i,j;
    int sum=0;
    for(i=N-1;i>=0;i--)
        for(j=N-1;j>0;j--)
    {
        if(a[j-1]>a[j])
        {
            int temp;
            temp=a[j-1];
            a[j-1]=a[j];
            a[j]=temp;
            sum++;
        }
    }
    print(a,N);
    return sum;

}
int main()
{
    int N;
    int A[105];
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
   int sum= bubbleSort(A, N);
   cout<<sum<<endl;


    return 0;

}
