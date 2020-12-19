//include---------------------------------------------------------------------------
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<cctype>
#include<vector>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<bitset>
#include<map>
#include<algorithm>
#include<memory>

//using namespace-------------------------------------------------------------------
using namespace std;

//define,const----------------------------------------------------------------------
#define rep(i, n) for(int i = 0; i < n; i++)
const int INF = 1 << 25;
#define MAX_N 100

//global----------------------------------------------------------------------------
int numbar[MAX_N], n;

//function--------------------------------------------------------------------------
int main(){
	scanf("%d", &n);
	const int N = n;
	int num;
	rep(i, N)
		scanf("%d", &numbar[i]);
	rep(i, N - 1)
		printf("%d ", numbar[i]);
	printf("%d\n", numbar[N - 1]);
	for(int i = 1; i < N; i++){
		num = i;
		for(int j = 0; j < i; j++){
			if(numbar[i] < numbar[j]){
				num = j;
				break;
			}
		}
		if(num != i){
			for(int j = num; j < i; j++){
				swap(numbar[j], numbar[i]);
			}
		}
		for(int j = 0; j < N - 1; j++)
			printf("%d ", numbar[j]);
		printf("%d\n", numbar[N - 1]);
	}
	return 0;
}
