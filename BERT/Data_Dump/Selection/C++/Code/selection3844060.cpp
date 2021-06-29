#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXSIZE = 1e2+7;
int num[MAXSIZE];
int n;
int selectSort(){
	int minj;
	int cnt = 0;
	for(int i = 0; i < n-1; i++){
		minj = i;
		for(int j = i; j < n; j++){
			if(num[minj] > num[j]){
				minj = j;
			}
		}
		swap(num[i],num[minj]);
		if(i != minj) cnt++;
	}
	return cnt;
}
int main(){
	while(~scanf("%d",&n)){
		memset(num,0,sizeof(num));
		for(int i = 0; i < n; i++){
			scanf("%d",&num[i]);
		}
		int cnt = selectSort();
		for(int i = 0; i < n; i++){
			if(i) printf(" ");
			printf("%d",num[i]);
		}
		printf("\n");
		printf("%d\n", cnt);
	}
	return 0;
}
