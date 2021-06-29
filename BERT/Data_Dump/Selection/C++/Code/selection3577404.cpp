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
      int min_idx = i;
      for(int j=i;j<N;j++)
      {
        if(Array[j] < Array[min_idx])
        {
          min_idx = j;
        }
      }
      if(i != min_idx)
      {
        long tmp = Array[i];
        Array[i] = Array[min_idx];
        Array[min_idx] = tmp;
        count++;
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

