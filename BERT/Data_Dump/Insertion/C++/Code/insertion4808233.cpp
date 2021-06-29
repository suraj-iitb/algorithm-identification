#include<iostream>

int main(void)
{
	using namespace std;
	int n;
	cin >> n;
	int card[n];
	for(int i = 0; i < n; i++)
		cin >> card[i];
	for(int m = 0; m < n; m++)
	{
		if(m)
			cout << " ";
		cout << card[m];
	}
	cout << endl;
	for(int i = 1; i < n; i++)
	{
		int j = i;
		while(j > 0)
		{
			int temp;
			if(card[j] < card[j - 1])
			{
				temp = card[j];
				card[j] = card[j - 1];
				card[j - 1] = temp;
			}
			j--;
		}
		for(int m = 0; m < n; m++)
		{
			if(m)
				cout << " ";
			cout << card[m];
		}
		cout << endl;
	}
}
