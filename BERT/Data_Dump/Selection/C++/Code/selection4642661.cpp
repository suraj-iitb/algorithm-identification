#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
int n, cnt;
int a[maxn];
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int head = 0;
	for(int i = 0; i < n; i++){
		int mint = head;
		for(int j = head + 1; j < n; j++){
			if(a[mint] > a[j]){
				mint = j;
			}
		}
		if(mint != head){
			cnt++;
			swap(a[mint], a[head]);
		}
		head++;
	}
	int first = 1;
	for(int i = 0; i < n; i++){
		if(first)first = 0;
		else printf(" ");
		printf("%d", a[i]);
	}
	printf("\n%d\n", cnt);
	return 0;
}
