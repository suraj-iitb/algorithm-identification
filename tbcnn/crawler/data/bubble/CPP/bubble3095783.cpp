#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 1005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int cnt = 0;
	for(int i=1;i<=n;i++){
		for(int j=n;j>i;j--){
			if(a[j-1] > a[j]){
				swap(a[j-1],a[j]);
				cnt++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d%c",a[i],i == n ? '\n' : ' ');
	}
	printf("%d\n",cnt);
	return 0;
}

