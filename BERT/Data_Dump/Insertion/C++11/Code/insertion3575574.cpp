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
  	for(int i = 1; i< N;i++)
    {
      for(int k=0;k<N -1 ;k++) cout << Array[k] << " ";
      cout << Array[N-1] << endl;

      long key = Array[i];
      for(int j=i-1;j>=0;j--)
      {
        if(key < Array[j])
        {
          Array[j+1] = Array[j];
          Array[j] = key;
        }else
        {
          break;
        }
      }
    }
  	for(int k=0;k<N -1 ;k++) cout << Array[k] << " ";
    cout << Array[N-1] << endl;

  	return 0;
}

