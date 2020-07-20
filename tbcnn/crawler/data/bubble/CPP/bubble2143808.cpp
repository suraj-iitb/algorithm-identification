#include<cstdio>
using namespace std;

void b_sort(int *a,int N);

int main(){
	int a[100];
	int N;
	scanf("%d",&N);
	for(int i = 0; i < N;i++){
		scanf("%d",&a[i]);
	}
	
	b_sort(a,N);	
}

void b_sort(int *a,int N){
	int j = N-1;
	int t;
	int count = 0;
	
	while(1){
		for(int i = 0;i < j;i++){
			if(a[i]  > a[i+1]){
				t = a[i];
				a[i] = a[i+1];
				a[i+1] = t;
				count++;
			}
		}
		if(j != 0) j--;
		if(j == 0) {
			break;
		}
	}
	for(int i = 0;i < N;i++){
		printf("%d",a[i]);
		if(i != N-1){
			 printf(" ");
			}else{
				printf("\n");
			}
	}
	printf("%d\n",count);
}
	
