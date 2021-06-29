#include <stdio.h>

#define ELEMENT_CNT_MIN 1
#define ELEMENT_CNT_MAX 100
#define ELEMENT_MIN 0
#define ELEMENT_MAX 1000


void insertion_sort(int *arr, int size);
void put_arr(int *arr, int size);
int judge_constraint(int test_num, int min, int max);

int main(void){
    
    int element_cnt; 
	int element[ELEMENT_CNT_MAX];
    int i;
    
    /* input line 1 */
    scanf("%d", &element_cnt);
    
    if(judge_constraint(element_cnt, ELEMENT_CNT_MIN, ELEMENT_CNT_MAX) == -1)
    {
        return -1;
    }
	
	/* input line 2 */
	for(i = 0; i < element_cnt; i++)
	{
		scanf("%d", &element[i]);
		
		if(judge_constraint(element[i], ELEMENT_MIN, ELEMENT_MAX) == -1)
		{
			return -1;
		}
		
	}
	
	/* output line 1 */
	put_arr(element, element_cnt); 
	
	/* output line 2 ~ element_cnt */
	insertion_sort(&element[0], element_cnt);
	
    return 0;
}

void insertion_sort(int *arr, int size)
{
    int tmp;
    int i, j;

    for(i = 1; i < size; i++)
    {
        tmp = arr[i];
        j = i - 1;
        
        while((j >= 0) && (arr[j] > tmp))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
        
        put_arr(arr, size);  
    }
}

void put_arr(int *arr, int size)
{
	int i;
	
	for(i = 0; i < size - 1; i++)
	{
	    printf("%d ", arr[i]);
	}
	printf("%d\n", arr[size - 1]);
}

int judge_constraint(int test_num, int min, int max)
{
    if(test_num < min || test_num > max)
    {
        return -1;
    }
    
    return 0;
}
