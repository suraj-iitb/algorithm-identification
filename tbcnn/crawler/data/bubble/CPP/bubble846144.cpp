#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n,cnt = 0;
	int a[100] = {0};
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",a+i);
	}
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j >= i + 1; j--){
			if(a[j] < a[j-1]){
				swap(a[j],a[j-1]);
				cnt++;
			}
		}
	}
	for(int i = 0; i < n - 1; i++){
		printf("%d ",a[i]);
	}
	printf("%d\n%d\n",a[n-1],cnt);
	return 0;
}
