#include<stdio.h>


using namespace std;

void output(int array[], int n){

	for(int k = 0;k < n; k++){
		if(k != n-1){
			printf("%d ",array[k]);
		}else{
			printf("%d\n",array[k]);
		}
	}
}

int main(){

	int array[1000];
    int n ;

    scanf("%d", &n);
	for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
	}

    output(array, n);


	int v = 0;
	int j = 0;
	for(int i = 1; i < n; i++){
		v = array[i];
		j = i-1;
        while(j >= 0 && array[j] > v){
            array[j+1] = array[j];
			j--;
		}
		array[j+1] = v;
        
        output(array, n);
		}
	}

