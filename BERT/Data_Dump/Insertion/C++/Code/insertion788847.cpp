#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	vector<int> m;

	cin >> n;

	for(int i=0;i<n;++i){
		int j;
		cin >> j;
		m.push_back(j);
	}

	for(int j=1;j<m.size();++j){
		for(int k=0;k<m.size();++k){
			cout << m[k];
			if(k != m.size()-1)
				cout << " ";
		}
		cout << endl;

		int key = m[j],
			 i = j-1;

		while(i >= 0 && m[i] > key){
			m[i+1] = m[i];
			--i;
		}

		m[i+1] = key;
	}

	for(int k=0;k<m.size();++k){
		cout << m[k];
		if(k != m.size()-1)
			cout << " ";
	}
	cout << endl;
	

	return 0;
}
