#include<iostream>
#include<algorithm>
using namespace std;

int SelectionSort(int A[],int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        int mini=i;
        for(int j=i;j<n;j++)
        {
            if(A[j]<A[mini])
            {
                mini=j;
            }
        }
        if(A[i]!=A[mini])
        {
            swap(A[i],A[mini]);
            count++;
        }
        
    }
    return count;
}

int main()
{
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	}
	
	int count=SelectionSort(a,n);
	for(int i=0;i<n;i++)
	{
	    if(i)cout<<" ";
	    cout<<a[i];
	}
	cout<<endl;
	cout<<count<<endl;
	//system("pause");
	return 0;
}



