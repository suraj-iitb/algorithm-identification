#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXSIZE = 1e2+7;
int num[MAXSIZE];
int n;
int bubbleSort(){
	bool flag = 1;
	int cnt = 0;
	while(flag){
		flag = 0;
		for(int j = n-1; j >= 1; j--){
			if(num[j] < num[j-1]){
				swap(num[j],num[j-1]);
				cnt++;
				flag = 1;
			}
		}
	}
	return cnt;
}
int main(){
	while(~scanf("%d",&n)){
		memset(num,0,sizeof(num));
		for(int i = 0; i < n; i++){
			scanf("%d",num+i);
		}
		int cnt = bubbleSort();
		for(int i = 0; i < n; i++){
			if(i) printf(" ");
			printf("%d", num[i]);
		}
		printf("\n");
		printf("%d\n", cnt);
	}
	return 0;
}
