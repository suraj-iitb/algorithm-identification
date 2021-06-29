#include <cstdio>
using namespace std;

int main(){
		int n;
		int a[100];
		int v;
		int min_index;
		int c=0;

		scanf("%d",&n);
		for(int i=0 ; i<n ; i++) scanf("%d",&a[i]);

		for(int i=0 ; i<n ; i++){
				min_index = i;
				for(int j=i ; j<n ; j++){
						if(a[j] < a[min_index]) min_index = j;
				}
				if(min_index != i){
						v = a[i];
						a[i] = a[min_index];
						a[min_index] = v;
						c++;
				}
		}
		for(int i=0 ; i<n-1 ; i++) printf("%d ",a[i]);
		printf("%d\n",a[n-1]);
		printf("%d\n",c);
}


