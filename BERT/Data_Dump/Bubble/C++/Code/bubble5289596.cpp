#include<bits/stdc++.h>

using namespace std;
int main()
{
	int n,x,swp=0;
	vector<int> vec;
	vector<int> :: iterator it,ot;
	cin >> n;
	while(n--)
	{
		cin >> x;
		vec.push_back(x);
	}
	for(it = vec.begin();it != vec.end();++it)
	{
		for(ot = vec.end()-1;ot != it;ot--)
		{
			if((*ot)<(*(ot-1)))
			{
				swap((*ot),(*(ot-1)));	
				swp++;
			}
		}
	}
	for(it = vec.begin();it != vec.end();it++)
	{
		if(it ==vec.begin())cout << *it;
		else cout << " " << *it;
	}
	cout << endl << swp << endl;
	return 0;
}
