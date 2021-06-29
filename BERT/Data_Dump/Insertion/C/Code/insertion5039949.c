#include<stdio.h>

 void process(int B[], int N){
 	int i;
 	for(i=0; i<N; i++){
 		if(i>0){
 			printf(" ");
 		}
 		printf("%d", B[i]);
 	}
 	printf("\n");
 }
 void sort (int B[], int N){
 	int j, i, v;
 	for(i=1; i<N; i++){
 		v=B[i];
 		j=i-1;
 		while(j>=0&&B[j]>v){
 			B[j+1] = B[j];
 			j--;
 		}
 		B[j+1]=v;
 		process(B,N);
 	}
 }

int main(){
int N, i, j;
int B[100];

scanf("%d", &N);
for(i=0; i<N; i++){
scanf("%d",&B[i]);
}

process(B,N);
sort(B,N);

return 0;
}

