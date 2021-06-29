#include<iostream>
#include<cstdio>
using namespace std;

void myPrint(int a[], int n){
	int i;
	for(i = 0; i < n; i++ ){
		if(i > 0)	printf(" ");
		printf("%d",a[i]);
		
	}
	printf("\n");
}

void insertion_sort(int a[], int n){
	int t;
	int j,i;
	for(i = 1; i < n; i++){
		t = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > t){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = t;
		myPrint(a,n);
	}
}

int main(){
	int n;
	int i;
	cin>>n;
	int a[n];
	for(i = 0; i < n; i++){
		scanf("%d",&a[i]);
	}
	myPrint(a,n);
	insertion_sort(a,n);
	
	return 0;
} 
