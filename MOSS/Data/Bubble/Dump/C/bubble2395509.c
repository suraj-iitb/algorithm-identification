#include <stdio.h>

/*
1 bubbleSort(A, N) // N ??????????´?????????? 0-????????????????????? A
2   flag = 1 // ????????£??\????´?????????¨??????
3   while flag
4     flag = 0
5     for j ??? N-1 ?????? 1 ?????§
6       if A[j] < A[j-1]
7         A[j] ??¨ A[j-1] ?????????
8         flag = 1
 */

#define		MXPRG		100+10

int			bubbleSort( int *ARY , int );	//???????????°?????????

int			A[MXPRG];

int		main(void)
{
	int		i;
	int		N;
	int		chg;

	scanf("%d",&N);
	for(i=0; i<N; i++)
	{
		scanf("%d",&A[i]);
	}

	chg = bubbleSort( A , N);

	for(i=0; i<N-1; i++)
	{
		printf("%d",A[i]);
		printf(" ");
	}
	printf("%d",A[N-1]);
	printf("\n");
	printf("%d\n",chg);

	return 0;
}

int		bubbleSort( int ary[], int num )
{
	int		chg;
	int		flag;
	int		j;
	int		tmp;

	chg = 0;
	flag = 1;
	while(flag)
	{
		flag = 0;
		for( j=num-1; j>=1; j-- )
		{
			/*
			printf("ary[j]=%d ",ary[j]);
			printf("ary[j-1]=%d\n",ary[j-1]);
			*/

			if( ary[j] < ary[j-1] )
			{
				tmp = ary[j];
				ary[j] = ary[j-1];
				ary[j-1] = tmp;
				chg = chg + 1;
				flag =1;
			}
		}
	}

	//printf("%d\n",chg);
	return chg;
}