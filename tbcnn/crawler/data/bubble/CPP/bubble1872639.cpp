#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <complex>
#include <math.h>
#include <ctype.h>
using namespace std; 
int flag, n, A[100], N, s = 0; int j;
int main() {
	cin >> N;
	for (int i = 0; i < N;i++) {
		cin >> A[i];
	}
	flag = 1; // ????????£??\????´?????????¨??????
		while (flag) {
			flag = 0;
			for (j = N - 1; j > 0;j--) {
				if (A[j] < A[j - 1])
				{
					n=A[j];A[j] = A[j-1];A[j - 1] = n;
						flag = 1;
						s++;
				}
			}
			j = N - 1;
		}
		for (size_t j = 0; j < N-1; j++)
		{
			cout << A[j]<<" ";
		}
		cout << A[N - 1] << endl<<s<<endl;
			return 0;
}
