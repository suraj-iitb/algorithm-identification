#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXSIZE = 1e2+7;
int num[MAXSIZE];
int n;
void print(){
	for(int i = 0; i < n; i++){
		if(i)printf(" ");
		printf("%d",num[i]);
	}
	printf("\n");
}
void insertSort(){
	print();
	for(int i = 1; i < n; i++){
		int key = num[i];
		int j = i-1;
		while(j >= 0 && num[j] > key){
			num[j+1] = num[j];
			j--;
		}
		num[j+1] = key;
		print();
	}
}

int main(){
	while(~scanf("%d",&n)){
		for(int i = 0;i < n; i++){
			scanf("%d",&num[i]);
		}
		insertSort();
	}
	return 0;
}
