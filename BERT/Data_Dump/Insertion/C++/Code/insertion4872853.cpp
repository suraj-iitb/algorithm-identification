#include<iostream>
#include<cstdio>
 
using namespace std;
 
const int maxn=1e2+5;
 
int s[maxn];
 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	for(int i=0;i<n;i++){
		if(i!=0){
			printf(" ");
		}
		printf("%d",s[i]);
	}
	printf("\n");
	for(int i=1;i<n;i++){
		int key=s[i];
		int j=i-1;
		//Insertion Sort算法核心
		while(j>=0&&s[j]>key){
			s[j+1]=s[j];
			j--;
		}
		s[j+1]=key;
		for(int k=0;k<n;k++){
			if(k!=0){
				printf(" ");
			}
			printf("%d",s[k]);
		}
		printf("\n");
	}
	return 0;
}

