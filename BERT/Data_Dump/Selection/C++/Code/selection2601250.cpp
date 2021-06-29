#include<iostream>
using namespace std;
/*
int SelctionSort(int a[],int n)
{
    int times=0;
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
                if(a[i]>a[j])
                {
                    swap(a[i],a[j]);
                    times++;
                }
    return times;
}
*/
int SelectionSort(int a[],int n)
{
	int times=0,minj,j;
	for(int i=0;i<n;i++)
	{
		minj=i;
		for(j=i;j<n;j++)
			if(a[j]<a[minj])
				minj=j;
		if(minj!=i)
		{
			swap(a[minj],a[i]);
			times++;
		}
	}
	return times;
}
int main()
{
    int a[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int times = SelectionSort(a,n);
    for(int i=0;i<n-1;i++)
        cout<<a[i]<<' ';
    cout<<a[n-1]<<endl;
    cout<<times<<endl;
    return 0;
}
