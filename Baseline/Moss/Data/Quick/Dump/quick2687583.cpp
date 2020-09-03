#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct DATA
{
	int num, id;
	string s;
};

vector<DATA> v;

int partitionSort(int p,int r)
{
	int x = v.at(r).num;// v[r];
	int i = p - 1;

	for (int j = p; j != r; ++j)
	{
		if (v.at(j).num<=x) //v[j] <= x
		{
			++i;
			swap(v.at(i), v.at(j));
		}
	}

	swap(v.at(i + 1), v.at(r));

	return i + 1;
}


void quicksort(int p, int r)
{
	if (p < r)
	{
		int q=partitionSort(p,r);
		quicksort(p, q - 1);
		quicksort(q + 1, r);
	}
}

void check()
{
	for (int i = 1; i != v.size(); ++i)
	{
		if (v.at(i - 1).num == v.at(i).num)
		{
			if (v.at(i - 1).id>v.at(i).id)
			{
				cout << "Not stable" << endl;
				return;
			}
		}
	}
	cout << "Stable" << endl;
}



int main()
{
	int n,t;
	string s;
	DATA data;
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i != n; ++i)
	{
		cin >> s>>t;
		data.s = s;
		data.num = t;
		data.id = i;
		v.push_back(data);
	}

	quicksort(0, n - 1);
	check();

	for (int i = 0; i != v.size(); ++i)
	{
		cout << v.at(i).s<<" " << v.at(i).num<<endl;
	}
	//cout << endl;

	return 0;

}
