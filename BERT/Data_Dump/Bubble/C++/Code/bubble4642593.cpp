#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e2 + 5;
int a[maxn];
int n, cnt;
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n - 1; i++){
		int tail = n - 1;
		for(int j = tail - 1; j >= 0; j--){
			if(a[j] > a[tail]){
				swap(a[j], a[tail]);
				tail--;
				cnt++;
			}else{
				tail--;
			} 
		}
	}
	int first = 1;
	for(int i = 0; i < n; i++){
		if(first)first = 0;
		else printf(" ");
		printf("%d", a[i]);
	} 
	printf("\n");
	printf("%d\n", cnt);
	return 0;
}
