
#include <stdio.h>
#include <stdlib.h>
typedef struct
{    
    char suit;
    int num;
    int index;
}Card;

int partition(Card A[], int p, int r){
	int i,x,j;
	Card tmp;
	x = A[r].num;
	i = p-1;
	for (j = p; j <= r; j++) {
		if (A[j].num <= x) {
			i++;
			tmp = A[i]; A[i] = A[j]; A[j] = tmp;
		}
	}
	return i;
}

void quicksort(Card A[], int p, int r){
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);

	}
}

int isStable(Card A[], int n)
{
	int i;
	for (i = 0; i < n - 1; i++) {
		if (A[i].num == A[i + 1].num&&A[i].index > A[i + 1].index) return 0;
	}
	return 1;
}
int main(int argc, char** argv) {
    int size,i,j;
    scanf("%d\n",&size);
    Card card[size+1];
    for(i = 1; i< size+1; i++)
    {
        scanf( " %c%d", &card[i].suit, &card[i].num);
        card[i].index = i;
    }
    quicksort(card, 1, size);
    int right = isStable(card, size);
    if(right == 1)
        printf("Stable\n");
    else
        printf("Not stable\n");
    
    
     for(i= 1; i<size+1;i++)
    {
        printf("%c %d\n", card[i].suit, card[i].num);
    }
    return (EXIT_SUCCESS);
}



