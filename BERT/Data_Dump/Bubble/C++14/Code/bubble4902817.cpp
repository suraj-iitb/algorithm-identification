#include<iostream>	
#include<vector>		
#include<utility>		    
#include<cstdio>		
#include<cmath>		  
#include<algorithm>			 			
#include<string>	
#include<ctime>		
#include<random>//mt199937	
using namespace std;
#define PPI acos(-1)//pi
#define HOG cout << "hoge" << endl //TestPrint "hoge"
#define RND(x,y) (double)(x > 0 ? floor(pow(10,y)*x+0.5) : ceil(pow(10,y)*x-0.5))/pow(10,y)//round macro

int main()
{
	int i, j, l, buf, imin, imax, isum = 0;
	int iia, iib, iic, iid, iie, iif;
	double dda, ddb, ddc, ddd, dde, ddf;
	char cca, ccb, ccc, ccd, cce;
	string ssa, ssb, ssc, ssd, sse;
	long long lla, llb, llc, lld, lle;
	vector<int> via, vib;
	////////////////////////////////////////////////////////////////////////////////////////////////////


	cin >> iia;
	for (i = 0; i < iia; i++) {
		cin >> buf;
		via.push_back(buf);
		
	}

	for (i = 0; i < iia; i++) {
		for (j = 0; j < iia-1; j++) {
			if (via.at(j) > via.at(j + 1)) {
				swap(via.at(j), via.at(j + 1));
				isum++;
				//HOG;
			}
		} 
	}
	for (i = 0; i < iia-1; i++) {
		cout << via.at(i) << ' ';
	}
	cout << via.at(i) << endl << isum << endl;




	////////////////////////////////////////////////////////////////////////////////////////////////////

	
}
