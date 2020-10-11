#include <stdio.h>
#define N 1000
void InsortionSort (int ,int *);//This function includes display procedure
void print (int, int*);

int main(){
    int array[N], *p = array;
    int i, n; // n is for storing number

    //input the number of data and data
    scanf("%d", &n);
    for (i = 0; i < n; i++)
	scanf("%d", &array[i]);
    
    print(n, p);
    //sort procedure
    InsortionSort(n, p);
    
    return 0;
}

void InsortionSort ( int n, int *p ){
    int i, j;
    int key;

    for (i = 1; i < n; i++){
	key = p[i];
	for (j = i-1; j >= 0 && p[j] > key; j--){
	    p[j+1] = p[j];
	    p[j] = key;
	}
	print(n, p);
    }
}

void print(int n, int* p ){
    int i;
    for (i = 0; i < n-1; i++)
	printf("%d ", p[i]);
    printf("%d\n", p[i]);
}
