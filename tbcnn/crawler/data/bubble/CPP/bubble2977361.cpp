#include <cstdio>
using namespace std;

int main(){
		int n;
		int a[1000];
		int v;
		int c=0;

		scanf("%d",&n);
		for(int i=0 ; i<n ; i++) scanf("%d",&a[i]);

		for(int i=0 ; i<n ; i++){
				for(int j=n-1 ; j>i ; j--){
						if(a[j] < a[j-1]){
								v = a[j];
								a[j] = a[j-1];
								a[j-1] = v;
								c++;
						}
				}
		}
		for(int j=0 ; j<n-1 ; j++) printf("%d ",a[j]);
		printf("%d\n",a[n-1]);
		printf("%d\n",c);
		return 0;
}

