#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,j,sum = 0,minj;
	int a[100];
	cin >> n;
	for (i = 0 ; i < n ; i++) cin >> a[i];
	
	for (i = 0 ; i < n ; i++)
	{
		minj = i;
		for (j = i ; j < n ; j++)
        {
		    if (a[j] < a[minj]) 
		    {
		    	minj = j;	
			}
	    }
	    if (minj != i) 
		{
		    sum+=1;
		}
		swap(a[i] , a[minj]);
	}
	
	for (i = 0 ; i < n ; i++)
	{
		if (i != 0 )
		{
		    cout << " ";
	    }
		cout << a[i];
	}
	cout << "\n";
	cout << sum << endl;
	return 0;
}
