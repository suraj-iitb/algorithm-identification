#include <stdio.h>
#include <stdlib.h>

#define MAX_SEQUENCE_DATA_NUM   100000
#define MAX_SEARCH_DATA_NUM      50000

#define FIND      1
#define NOT_FIND  0

typedef struct ST_BINARYDAtA{
    int  mid;       /* middle position */
    int  right;     /* right  position */
    int  left;      /* left   position */
}BinaryData_t;


static int BinarySerch(int *pSequenceBuffer, BinaryData_t *ptBinaryData, int search_value);


static int BinarySerch(int *pSequenceBuffer, BinaryData_t *ptBinaryData, int search_value)
{
	if(pSequenceBuffer[ptBinaryData->mid] == search_value)       /* find data */
	{
		return FIND;
	}
	else if(pSequenceBuffer[ptBinaryData->mid] > search_value )  /* Serch Value is left side */
	{
		
		if( ( ptBinaryData->left + 1 ) != ptBinaryData->mid )    /* No Data middle */
		{
			/* search left side data */
			ptBinaryData->right = ptBinaryData->mid;
			ptBinaryData->mid   = ((ptBinaryData->mid + ptBinaryData->left) / 2);
			
			return BinarySerch(pSequenceBuffer, ptBinaryData, search_value);
		}
		else
		{
			/* Not find */
		}
	}
	else                                                         /* Serch Value is right side */
	{
		
		if( ( ptBinaryData->right - 1 ) != ptBinaryData->mid )   /* No Data middle */
		{
			/* search right side data */
			ptBinaryData->left  = ptBinaryData->mid;
			ptBinaryData->mid   = ((ptBinaryData->mid + ptBinaryData->right) / 2);
			
			return BinarySerch(pSequenceBuffer, ptBinaryData, search_value);
		}
		else
		{
			/* Not find */
		}
	}
	
	return NOT_FIND; /* error return */
}


int main(void)
{
	BinaryData_t tBinaryData;
    int   sequence_data_num;
    int   search_data_num;
	int * pSequenceBuff;
	int   search_value;
	int   find_count = 0;
	int   loop = 0;
	
    /* get sequence data num */
    scanf("%d", &sequence_data_num);
    
	/* check Sequence Data Num */
	if(( sequence_data_num <= MAX_SEQUENCE_DATA_NUM ) || ( sequence_data_num != 0 ))
	{
        pSequenceBuff = (int *)malloc(sizeof(int) * sequence_data_num);
	}
	else
	{
		/* error input or not data */
		printf("0\n");
		return 0;
	}
	
	/* get Sequence Data */
    while( (loop < sequence_data_num) && (scanf("%d", &(pSequenceBuff[loop])) != EOF) )
    {
    	loop++;
    }

	/* get search data num */
    scanf("%d", &search_data_num);
    
	/* check Search Data Num */
	if(( search_data_num > MAX_SEARCH_DATA_NUM ) || ( search_data_num == 0 ))
	{
		/* error input or not data */
		printf("0\n");
		return 0;
	}

	/* init loop count */
	loop = 0;
	
    /* Search Data by Binary Search */
    while((scanf("%d", &search_value) != EOF) && ( loop < search_data_num ))
    {
    	/* Set Binary Search Init Data */
    	tBinaryData.left  = 0;
    	tBinaryData.right = (sequence_data_num - 1);
	    tBinaryData.mid = (tBinaryData.right + tBinaryData.left) / 2;
    	
		if( (search_value == pSequenceBuff[tBinaryData.left])   /* find Init Data */
		 || (search_value == pSequenceBuff[tBinaryData.right]) )
    	{
    		find_count++;
    	}
    	else if(sequence_data_num > 3)               /* find Binary Search */
    	{
    		find_count += BinarySerch(pSequenceBuff, &tBinaryData, search_value);
    	}
    	else
    	{
    		/* Not Find */
    	}
    	
    	loop++;
    }
	
	/* print result */
	printf("%d\n", find_count);
    
	free(pSequenceBuff);
	
    return 0;
}

