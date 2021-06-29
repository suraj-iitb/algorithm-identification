#include <iostream>
using namespace std;

#define maxN 2000001
#define maxData 10000
int boxA[maxN], boxB[maxN], boxC[maxData];

int main(void)
{
/* *** initialize *** */
	int dataN = 0;
	boxA[maxN] = {0};
	boxB[maxN] = {0};
	boxC[maxData] = {0};

/*  *** input Data *** */
	cin >> dataN;
//	cout << "dataN = " << dataN << endl;		//Debug
	
	for(int n = 1; n <= dataN; n++)
	{
		cin >> boxA[n];
//		cout << "boxA[" << n << "] = " << boxA[n] << endl;		//Debug
		
		boxC[boxA[n]]++;
//		cout << "boxC[" << boxA[n] << "] = " << boxC[boxA[n]] << endl;		//Debug
	}
	
/* *** data analysis *** */
	for(int c = 1; c <= maxData; c++)
	{
		boxC[c] += boxC[c-1];
//		cout << "boxC[" << c << "] = " << boxC[c] << endl;		//Debug
	}
	
/* *** sort *** */
	for(int b = dataN; b >= 1; b--)
	{
		boxB[boxC[boxA[b]]] = boxA[b];
		boxC[boxA[b]]--;
	}
	
/* *** result *** */
	for(int data = 1; data <= dataN; data++)
	{
		if(data == dataN)
		{
			cout << boxB[data] << endl;
		}
		else
		{
			cout << boxB[data] << " ";
		}
	}
	return 0;
}
