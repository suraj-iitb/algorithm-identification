#include<cstdio>
#include<iostream>
using namespace std;
int N;
const int MAX_SIZE = 101;
int arr[MAX_SIZE];
void trace(int arr[], int N){
	for(int i = 0; i < N ; i++){
		if(i > 0) printf(" ");
		printf("%d",arr[i]);
	}
	printf("\n");
}
void insertionSort(int arr[], int N){
	for(int i = 1; i < N; i++){
		int v = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > v){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = v;
		trace(arr,N);
	}
} 
int main(){
	scanf("%d",&N);
	for(int i = 0; i < N; i++){
		scanf("%d",&arr[i]);
	}
	trace(arr,N);
	insertionSort(arr,N);
	return 0;
}
