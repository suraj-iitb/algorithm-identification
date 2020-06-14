#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[105];

int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int cnt=0;
	bool flag=true;
	while(flag){
		flag=false;
		for(int j=0;j<n-1;j++){
			if(a[j+1]<a[j]){
				cnt++;
				swap(a[j],a[j+1]);
				flag=true;
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%d%c",a[i],i==n-1?'\n':' ');
	}
	printf("%d\n",cnt);
	return 0;
}
