#include<iostream>
#include<vector>

using namespace std;

void swap ( vector<int> &v, int a, int b )
{
	int tmp = v[a];
	v[a] = v[b];
	v[b] = tmp;
}

int SelectionSort ( vector<int> &v )
{

	int i,j,count=0,min_index;

	for ( i = 0 ; i < v.size() ; i++ )
	{
		min_index = i;
		for ( j = i ; j < v.size() ; j++ )
		{
			if ( v[min_index] > v[j] )
			{
				min_index = j;
			}
		}
		if ( min_index != i )
		{
			swap ( v, min_index, i );
			count++;
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
	int N,n,count=0;

	cin >> N;

	while ( N-- )
	{
		cin >> n;
		v.push_back ( n );
	}

	count = SelectionSort ( v );

	show ( v );

	cout << count << endl;;

return 0;
}

