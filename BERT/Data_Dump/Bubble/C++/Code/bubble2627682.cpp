#include <iostream>
#include <stdio.h>
using namespace std;

void bubble_sort(int a[], int n)
{
	bool flag=1;
	int temp;
	int change_count=0;

	while(flag){	//if??????????????????????????°???????????¶????????????????????±????????????
		flag=0;
		for (int j = n-1; j > 0; j--)
		{
			if (a[j]<a[j-1])
			{
				change_count++;
				temp=a[j];	a[j]=a[j-1];	a[j-1]=temp;
				flag=1;
			}
		}
	}

	//??????
	for (int i = 0; i < n; i++)	//???????????????????????¢????????????????????????????????????
	{
		if (i==n-1)
		{
			cout << a[i] << endl;
		}
		else
		{
			cout << a[i] << " ";
		}
	}
	cout << change_count << endl;
}

int main(int argc, char const *argv[])
{
	int n;

	//??\???
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	bubble_sort(a,n);
	
	return 0;
}
