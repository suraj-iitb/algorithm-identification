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
void print(){
	for(int i=1;i<=n;i++){
		printf("%d%c",a[i],i == n ? '\n':' ');
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	print();
	for(int i=1;i<n;i++){
		int v = a[i+1];
		int j = i;
		while(j > 0 && a[j] > v){
			a[j + 1] = a[j];
			j--;
		}
		a[++j] = v;
		print();
	}
	return 0;
}

