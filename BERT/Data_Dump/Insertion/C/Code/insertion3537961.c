#include <stdio.h>

void sort(int,int[]);

int main(void)
{
	int i, n, card_a[110] = {};

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &card_a[i]);
	}
    
    sort(n,card_a);

	return 0;
}

void sort(int num,int card[])
{
    int i, v, j, k;
	for (i = 0; i < num; i++) {
	    if(i!=0){
	        v=card[i];
	        j=i-1;
	        while(j>=0 && card[j]>=v){
	            card[j+1]=card[j];
	            j--;
	            card[j+1]=v;
	        }
        }
		for (k = 0; k < num; k++) {
			printf("%d", card[k]);
			if (k != num - 1)
				printf(" ");
			else
				printf("\n");
		}
	}
}
