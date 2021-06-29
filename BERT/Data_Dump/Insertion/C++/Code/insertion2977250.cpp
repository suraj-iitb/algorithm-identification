#include <cstdio>
using namespace std;

int main(){
		int n;
		int a[1000];
		int v;

		scanf("%d",&n);
		for(int i=0 ; i<n ; i++) scanf("%d",&a[i]);

		for(int i=0 ; i<n ; i++){
				v = a[i];
				for(int j=i-1 ; j>=0 ; j--){
						if(a[j]>v){
								a[j+1] = a[j];
								a[j] = v;
						}else break;
				}

				for(int j=0 ; j<n-1 ; j++) printf("%d ",a[j]);
				printf("%d\n",a[n-1]);
		}
		return 0;
}


