#include<iostream>
#include<cstdio>
using namespace std;

int selection_sort(int a[], int n){
	int sw = 0,t,min;
	for(int i = 0; i < n; i++){
		min = i;
		for(int j = i; j < n; j++)
			if(a[j] < a[min])
				min = j;
		if(min != i){
			t = a[i];
			a[i] = a[min];
			a[min] = t;
			sw++;
		}
	}
	return sw;
}
int main(){
	int a[100];
	int n;
	int sw;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	sw = selection_sort(a,n);
	for(int i = 0; i < n; i++){
		if(i > 0)	printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
	printf("%d\n",sw);
	return 0;
}
