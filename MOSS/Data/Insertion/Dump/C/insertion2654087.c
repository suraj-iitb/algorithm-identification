#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_NUM      100

static void Exchange_Void(int *pSortBuff, int insert, int key );

int main(void)
{
    int data_num;			/* Data Num */
	int cd;					/* Count Data */
	int key = 0;			/* Compare Num */
	int *pSortBuff;
	int insert;
	int loop;
   
    pSortBuff = (int *)malloc(sizeof(int) * MAX_DATA_NUM);
    /* get "Data Num" */
    scanf("%d", &data_num);
     
    /* get Name & time */
    while((scanf("%d", &(pSortBuff[cd])) != EOF) && cd < MAX_DATA_NUM)
    {
        cd++;
    }
    
	
    /* get Data Num equal process num */
    if( data_num == cd )
    {
         while(key < data_num)
        {
        	if(key>0)
        	{
        		insert = -1;
	        	for(loop=key-1; loop>=0; loop--)
	        	{
	        		if(pSortBuff[loop] > pSortBuff[key])
	        		{
	        			insert = loop;
	        		}
	        	}
        		if(insert != -1)
        		{
        			Exchange_Void(pSortBuff, insert, key);
        		}
        	}
        	// print
			for(loop=0; loop<data_num-1; loop++)
			{
				printf("%d ", pSortBuff[loop]);
			}
        	printf("%d\n", pSortBuff[data_num-1]);
			key++;
        }
    }
    else
    {
        /* error input */
    }
	free(pSortBuff);
    return 0;
}

static void Exchange_Void(int *pSortBuff, int insert, int key )
{
	int swap;
	int loop;
	
	swap = pSortBuff[key];
	
	for(loop=key; loop>insert; loop--)
	{
		pSortBuff[loop] = pSortBuff[loop-1];
	}
	pSortBuff[insert] = swap;
}
