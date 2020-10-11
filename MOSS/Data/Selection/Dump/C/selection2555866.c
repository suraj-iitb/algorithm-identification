#include <stdio.h>
#include <math.h>

#define ELEMENT_CNT_MIN 1
#define ELEMENT_CNT_MAX 100
#define ELEMENT_MIN 0
#define ELEMENT_MAX 100

int selection_sort(int *p_arr, int size);
void swap(int *px, int *py);
void put_arr(int *p_arr, int size);
int get_int_sequence(int *p_num, int min, int max, int size);
int get_int(int *p_num, int min, int max);
int judge_constraint(int test_num, int min, int max);


int main(void){
    
    int element_num;
    int element[ELEMENT_CNT_MAX];
    int cnt_exchange;
    
    if(get_int(&element_num, ELEMENT_CNT_MIN, ELEMENT_CNT_MAX) == -1)
    {
        return -1;
    }
    
    if(get_int_sequence(&element[0], ELEMENT_MIN, ELEMENT_MAX, element_num) == -1)
    {
        return -1;
    }
    
    cnt_exchange = selection_sort(&element[0], element_num);
    
    put_arr(&element[0], element_num);
    printf("%d\n", cnt_exchange);
    
    return 0;
}

int selection_sort(int *p_arr, int size)
{
    int i;
    int j;
    int min_idx;
    int cnt = 0;    /* exchange count */
    
    for(i = 0; i < size - 1; i++)
    {
        min_idx = i;
        for(j = i + 1; j < size; j++)
        {
            if(p_arr[j] < p_arr[min_idx])   
            {
                min_idx = j;        /* minimum value [i,size - 1] */
            }
        }
        if(p_arr[i] != p_arr[min_idx])
        {
            swap(&p_arr[i], &p_arr[min_idx]);
            cnt++;
        }
    }
    
    return cnt;
}

void swap(int *px, int *py)
{
    int tmp = *px;
    *px = *py;
    *py = tmp;
    
    return;
}

void put_arr(int *p_arr, int size)
{
	int i;
	
	for(i = 0; i < size - 1; i++)
	{
	    printf("%d ", p_arr[i]);
	}
	printf("%d\n", p_arr[size - 1]);
}

int get_int_sequence(int *p_num, int min, int max, int size)
{
    int i;
    
    for(i = 0; i < size; i++)
    {
        if(get_int(&p_num[i], min, max) == -1)
        {
            return -1;
        }
    }
    
    return 0;
}

int get_int(int *p_num, int min, int max)
{
	scanf("%d", p_num);
	
	if(judge_constraint(*p_num, min, max) == -1)
    {
        return -1;
    }
	
	return 0;
}
int judge_constraint(int test_num, int min, int max)
{
    if(test_num < min || test_num > max)
    {
        return -1;
    }
    
    return 0;
}
