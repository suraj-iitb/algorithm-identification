#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	long N;
	cin >> N;
  	long Array[N];
  	int idx = 0;
  	while(cin >> Array[idx]) idx++;
  	int count = 0;
  	for(int i = 0; i< N;i++)
    {
      long key = Array[i];
      for(int j=N-1;j>=i+1;j--)
      {
        if(Array[j] < Array[j-1])
        {
          long tmp = Array[j];
          Array[j] = Array[j-1];
          Array[j-1] = tmp;
          count++;
        }
      }
    }
	for(int i=0;i<N-1;i++)
    {
      cout << Array[i] << " ";
    }
  	cout << Array[N-1] << endl;
  	cout << count << endl; 
  	return 0;
}

