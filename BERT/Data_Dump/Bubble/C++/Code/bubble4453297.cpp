#include<iostream>
#include<vector>

using namespace std;

void swap ( vector<int> &v, int i, int j )
{
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

int BubbleSort ( vector<int> &v )
{

	int i,j,count=0;
	for ( i = 0 ; i < v.size()-1 ; i++ )
	{
		for ( j = v.size()-1 ; i < j ; j-- )
		{
			if ( v[j-1] > v[j] )
			{
				swap ( v, j-1, j );
				count++;
			}
		}
	}

	return count;
}

void show ( vector<int> &v )
{
	int i;
	for ( i = 0 ; i < v.size()-1 ; i++ )
	{
		cout << v[i] << " ";
	}
	cout << v[i] << endl;
}

int main ()
{
	vector<int> v;
	int N,n,count;

	cin >> N;

	while ( N-- )
	{
		cin >> n;
		v.push_back ( n );
	}

	count =  BubbleSort ( v );
	
	show ( v );

	cout << count << endl;

return 0;
}
