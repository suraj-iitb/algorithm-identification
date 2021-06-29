#include <iostream>
#include <vector>

using namespace std;

int count = 0;

void comp(vector<int>& ans,vector<int> v1,vector<int> v2)
{
	vector<int>::iterator it1 = v1.begin();
	vector<int>::iterator it2 = v2.begin();
	
	while(it1 != v1.end() && it2 != v2.end())
	{
		if((*it1) < (*it2))
		{
			ans.push_back(*it1);
			it1++;
			count++;
		}
		else
		{
			ans.push_back(*it2);
			it2++;
			count++;
		}
	}
	//
	if(it1 != v1.end())
	{
		
		for(;it1 < v1.end();it1++)
		{	
			count++;
			ans.push_back(*it1);
		}
	}//count++;
	if(it2 != v2.end())
	{
		
		for(;it2 < v2.end();it2++)
		{
			count++;
			ans.push_back(*it2);
		}
	}
}
vector<int> mergesort(vector<int> vec)
{
	if(vec.size() == 1)
	{
		return vec;
	}
	
	vector<int> vec1(vec.begin(),vec.begin()+vec.size()/2);
	vector<int> vec2(vec.begin()+vec.size()/2,vec.end());
	
	vector<int> v1,v2;
	v1 = mergesort(vec1);
	v2 = mergesort(vec2);
	
	vector<int> ans;
	comp(ans,v1,v2);
	return ans;
}

int main()
{
//	vector<int> s1(3,10);
//	vector<int> s2(s1.begin(),s1.begin() + s1.size() / 2);
//	cout << s2.size();	
		
	
	vector<int> m;
	int n,temp;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin>> temp;
		m.push_back(temp);
	}
	vector<int> ans;
	ans = mergesort(m);
	vector<int>::iterator it = ans.begin();
	for(;it < ans.end() - 1;it++)
	{
		cout << *it << ' ';	
	}	
//	it++;
	cout << *it << endl;
	cout << count << endl;
	return 0;	
} 
