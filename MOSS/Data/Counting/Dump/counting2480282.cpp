#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n,a[3000000];
	cin >> n;
	for(int i = 0;i < n;i++) scanf("%d",&a[i]);
	sort(a,a + n);
	for(int i = 0;i < n;i++) {
		if(!i) printf("%d",a[i]);
		else printf(" %d",a[i]);
	}
	cout << endl;
	return 0;
}
