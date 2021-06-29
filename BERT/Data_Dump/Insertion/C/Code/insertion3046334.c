#include <stdio.h>
#define NUMBER 100
void print_array(int array[], int num)
{
	int i;
	for( i = 0; i< num-1; i++)
		printf("%d ", array[i]);
	
	printf("%d\n", array[i]);
}
	
void insertionSort(int array[], int num)
{
    int i, j, v;

    for (i=1; i <= num-1; i++) { 
	
	v = array[i];

        j = i - 1; 


        while (j >= 0 && array[j] > v) {
          
            array[j+1] = array[j];

          
            j--;
        }
		array[j+1] = v;
			print_array(array, num);
    }

}



int main(void)
{
	int array[NUMBER];
	int num, i;
	scanf("%d", &num);
	
	for (i = 0; i < num; i++){
		scanf("%d", &array[i]);

	}
		print_array(array, num);
	insertionSort(array, num);


	return 0;

}	
