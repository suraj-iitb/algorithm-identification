#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int maxn = 1e2 + 5;
int a[maxn], n;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
	   int t = 0; 
	   while(a[i] > a[t] && t < i)t++;
	   	int target = a[i];
	   	for(int k = i - 1; k >= t; k--){
	   		a[k + 1] = a[k];
	   	}
	   	a[t] = target;
	   	int first = 1;
		for(int j = 0; j < n; j++){
			if(first) first = 0;
			else printf(" ");
			printf("%d", a[j]);
		}	
		printf("\n");
	}
	
	return 0;
}
