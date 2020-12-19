#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 2000005
#define maxk 10005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[maxn],c[maxk];
int main(){
	scanf("%d",&n);
	int maxval = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxval = max(maxval,a[i]);
		c[a[i]]++;
	}
	int k = 0;
	for(int i=0;i<=maxval;i++){
		for(int j=1;j<=c[i];j++){
			a[++k] = i;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d%c",a[i],i==n?'\n':' ');
	}
	return 0;
}

