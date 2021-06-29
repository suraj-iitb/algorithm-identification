#include<stdio.h>
#include<stdlib.h>
#define MAX1 10000
#define MAX2 500


int line_search(int p[], int N1, int key){
	
	for(int i=0;i<N1;i++){
		if(p[i]==key){
			int tmp=p[i];
			for(int j=i;j<N1-1;j++){
				p[j]=p[j+1];
			}
			p[N1-1]=tmp;
			return i;
		}
	}
	
	return -1;
}

int main(void){
	
	int N1,N2,key;
	int p[MAX1];
	int cnt=0;
	
	scanf("%d",&N1);
	
	for(int i=0;i<N1;i++){
		scanf("%d",&p[i]);
	}
	
	scanf("%d",&N2);
	
	for(int i=0;i<N2;i++){
		scanf("%d",&key);
		
		int ans=line_search(p,N1,key);
		if(ans!=-1){
			cnt++;
		}
	}
	
	printf("%d\n",cnt);
	
	
	return 0;
	
}
