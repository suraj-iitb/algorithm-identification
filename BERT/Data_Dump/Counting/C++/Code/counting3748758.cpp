#include<cstdio>

//M adalah bilangan Maks
void CountingSort(int N, int M, int *input, int *freq) {
	int x;
	for(int i=0;i<=M;i++) {
		freq[i]=0;
	}
	for(int i=1;i<=N;i++) {
		x=input[i];
		freq[x] = freq[x] +1;	
	}
	int index=1;
	for(int i=0;i<=M;i++) {
		for(int j=1;j<=freq[i];j++) {
			input[index] = i;
			index++;
		}
	}
}

int main() {
	int N;
	scanf("%d",&N);
	int input[N+1];
	int M=0;
	for(int i=1;i<=N;i++) {
		scanf("%d",&input[i]);
		if(input[i]>M) {
			M=input[i];
		}
	}
	int freq[M+1];
	CountingSort(N,M,input,freq);
	for(int i=1;i<=N;i++) {
		printf("%d",input[i]);
		if(i<N) {
			printf(" ");
		} 
		if(i==N) {
			printf("\n");
		}
	}
}
	
