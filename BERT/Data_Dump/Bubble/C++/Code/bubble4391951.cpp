#include<iostream>
using namespace std;
int main()
{
	int n;
	int count=0;
	cin>>n;
	int a[n] = {0};
	for(int i = 0; i < n; i++)cin >> a[i];
	
	int flag = 1;
	
	while(flag)
	{
		flag = 0;
		
		for(int i = n-1; i>0; i--)
		{
			if(a[i] < a[i-1])
			{
				int temp = a[i];
				a[i] = a[i-1];
				a[i-1] = temp; 
				
				flag = 1; 
				
				count++;
			}
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		if(i > 0)cout << " ";
		cout << a[i];
	}
	cout << endl;
	
	cout << count << endl;
	
	return 0;
	
 } 
