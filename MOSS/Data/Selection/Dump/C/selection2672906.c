#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int data_num;			/* Count Data Num */
	int dn;					/* Data Num */
    int *pSortBuff;
	int sn = 0;				/* SortNum */
	int minj;				/* MininumNum */
	int i, j;
	int swap;
    
    /* get "Data Num" */
    scanf("%d", &dn);
     
    pSortBuff = (int *)malloc(sizeof(int) * dn);
	
    /* get Name & time */
    while((scanf("%d", &(pSortBuff[data_num])) != EOF) && data_num < dn)
    {
        data_num++;
    }
    
	
    /* get Data Num equal process num */
    if( data_num == dn )
    {
    	for( i=0; i<dn; i++ )
    	{
    		minj = i;
    		for( j=i; j<dn; j++ )
    		{
    			if( pSortBuff[minj] > pSortBuff[j] ) 
    			{
    				minj = j;
    			}
    		}
    		if(minj != i)
    		{
    			swap = pSortBuff[minj];
    			pSortBuff[minj] = pSortBuff[i];
    			pSortBuff[i] = swap;
    			sn++;
    		}
    	}
    }
    else
    {
        /* error input */
    }
	
	for(i=0; i<dn-1; i++)
	{
		printf("%d ", pSortBuff[i]);
	}
	printf("%d\n%d\n", pSortBuff[dn-1], sn);
	
	free(pSortBuff);
    return 0;
}

