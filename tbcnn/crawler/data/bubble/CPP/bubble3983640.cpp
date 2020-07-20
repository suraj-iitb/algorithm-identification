#include<stdio.h>
#include <sstream>
#include <iostream>
#include <cstdlib>

using namespace std;

#define BUF_SIZE 1024
#define ARRAY_SIZE 100

int main(){

	int array[1000];
    int n;
    int change_count=0;

    scanf("%d", &n);
	for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
	}

	int tmp = 0;
	for(int i = n-1;i > 0;i--){
		for(int j = 0; j < i;j++){
			if(array[j] > array[j+1]){
				tmp = array[j+1];
				array[j+1] = array[j];
				array[j] = tmp;
				change_count++;
			}
		}
	}

	for(int i = 0; i < n; i++){
		if(i != n-1){
			printf("%d ",array[i]);
		}else{
			printf("%d\n",array[i]);
		}
	}
	printf("%d\n",change_count);
}
