#include<iostream>
using namespace std;	
int arr[1000];
int main()
{

	int n;
	int j;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
			for(int i = 1;i<=n;i++)
			{
			    if(i!=n)
			    cout<<arr[i]<<" ";
			    else
			    cout<<arr[i]<<endl;
			}
		for (int i = 2; i <= n; i++)
		{
			int temp = arr[i];
			for ( j = i - 1; j >= 1; j--)
			{
				if (temp < arr[j])
				{
					arr[j + 1] = arr[j];
				}
				else
					break;
			}
			arr[j + 1] = temp;
			for (int i = 1; i <= n; i++)
			{
				if (i != n)
					cout << arr[i] << " ";
				else
					cout << arr[i] << endl;
			}
		}
	}
}
