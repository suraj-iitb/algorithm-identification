#include<iostream>
using namespace std;


int Bubblesort(int A[],int n)
{
    int count=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n;
	cin>>n;
    int A[100]={};  //测试一下
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int u=Bubblesort(A,n);
    for(int i=0;i<n;i++)
    {
        if(i)cout<<" ";
        cout<<A[i];
    }
	cout<<endl;
    cout<<u<<endl;
	//system("pause");
	return 0;
}

	

