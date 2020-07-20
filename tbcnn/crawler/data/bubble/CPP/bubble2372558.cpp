#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n,s=0;
	vector<int> a;
	scanf("%d",&n);
	a.resize(n);
	for(int i=0; i<n; ++i) {
		scanf("%d",&a[i]);
	}
	for(int i=0; i<n-1; ++i) {
		for(int j=n-1; j>=i+1; --j) {
			if(a[j]<a[j-1]) {
				swap(a[j],a[j-1]);
				++s;
			}
		}

	}
	for(int i=0; i<n-1; ++i) {
		printf("%d ",a[i]);
	}
	printf("%d\n%d\n",a[n-1],s);
	return 0;
}
