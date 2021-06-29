#include <iostream>
using namespace std;

void print(int x[],int n){
    for(int i=0;i<n;i++){
        if(i>0)printf(" ");
        printf("%d",x[i]);
    }
    printf("\n");
}

void InsertionSort(int x[],int n){
	int t,j;
	for(int i=1;i<n;i++){
	    print(x,n);
		t = x[i];
		j = i-1;
		while( j>=0 && t<x[j]){
			x[j+1]=x[j];
			x[j]=t;
			j--;
		}
	}
	print(x,n);
}

int main() {
    int n;
	scanf("%d",&n);
	int lst[n];
	for(int i=0;i<n;i++){
	    cin >> lst[i];
	}
	InsertionSort(lst,n);
	return 0;
}
