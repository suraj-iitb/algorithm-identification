#include<iostream>
#include<vector>
#include<utility>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<ctime>
#include<random>

using namespace std;
#define PPI acos(-1)
#define HOG cout << "hoge" << endl
#define WS  << ' '
#define CL  << ':'

int main()
{
	int i, j, l, buf, imin, imax, sum = 0, elss = 0;
	int iia, iib, iic, iid, iie;
	double dda, ddb, ddc, ddd, dde;
	char cca, ccb, ccc, ccd, cce;
	string ssa, ssb, ssc, ssd, sse;
	long long lla, llb, llc, lld, lle;
	////////////////////////////////////////////////////////////////////////////////////////////////////
	vector<int> n;
	cin >> iia;
	for (i = 0; i < iia; i++) {
		cin >> buf;
		n.push_back(buf);
	}
	
	for (i = 0; i < iia; i++) {
		for (j = 0; j < i; j++) {
			if (n[j] >= n[i] ){
				//HOG;
				n.insert(n.begin()+j, n[i]);
				n.erase(n.begin()+i+1);
				break;
			}

		}
		for (j = 0; j < n.size()-1; j++) {
			cout << n[j] WS ;

		}
		cout << n[j] << endl;
	}
	




	////////////////////////////////////////////////////////////////////////////////////////////////////

	
}
