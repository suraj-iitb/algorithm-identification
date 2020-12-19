#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctype.h>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

//4方向ベクトル→↑←↓
int dx[] ={1,0,-1,0};
int dy[] ={0,-1,0,1};
int n;
int A[100];
int main()
{
  cin >>n;
  for(int i = 0;i <n;i++){
    cin >>A[i];
  }
  for(int i = 0;i <n;i++){
    cout <<A[i];
    if(i !=n-1)
      cout <<" ";
  }
  cout <<endl;
  int i;
  int key;
  for(int j = 1;j <n;j++){
      key = A[j];
      i = j-1;
      while(i >= 0&&A[i]>key){
	A[i+1] =A[i];
	i--;
      }
      A[i+1] =key;
      for(int i = 0;i <n;i++){
	  cout <<A[i];
	if(i !=n-1)
	  cout <<" ";
      }
      cout<<endl;
  }
  return 0;
}
