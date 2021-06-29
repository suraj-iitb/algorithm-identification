#include <stdio.h>
#include <stdlib.h>


typedef struct{
	char suit;
	int num;
	int pos;
} CARD_T;


int Partition(CARD_T *box, int l, int r)
{
	int pivot;
	CARD_T bk;
	int i, j;

	pivot = box[r].num;
	i = l - 1;
	j = r;

	while(1){
		while(box[++i].num < pivot);

		while(i < --j && pivot < box[j].num);

		if(j <= i)
			break;

		bk = box[i];
		box[i] = box[j];
		box[j] = bk;
	}

	bk = box[i];
	box[i] = box[r];
	box[r] = bk;

	return i;
}


int Partition2(CARD_T *box, int l, int r)
{
	int pivot;
	CARD_T bk;
	int i, j;

	pivot = box[r].num;
	j = l - 1;

	for(i = l; i < r; i++){
		if(box[i].num <= pivot){
			j++;
			if(i != j){
				bk = box[i];
				box[i] = box[j];
				box[j] = bk;
			}
		}
	}

	bk = box[r];
	box[r] = box[j + 1];
	box[j + 1] = bk;

	return j + 1;
}


void Quick_sort(CARD_T *box, int l, int r)
{
	int pivot;


	if(r <= l)
		return;

	pivot = Partition2(box, l, r);

	Quick_sort(box, l, pivot - 1);

	Quick_sort(box, pivot + 1, r);
}


int main()
{
	char in_str[20];
	int n;
	CARD_T *cards;
	int i;


	fgets(in_str, sizeof(in_str), stdin);
	sscanf(in_str, "%d", &n);

	cards = (CARD_T *)malloc(sizeof(CARD_T) * n);

	for(i = 0; i < n; i++){
		fgets(in_str, sizeof(in_str), stdin);
		sscanf(in_str, "%c %d", &cards[i].suit, &cards[i].num);
		cards[i].pos = i;
	}


	Quick_sort(cards, 0, n - 1);


	// 表示
	for(i = 0; i < n - 1; i++){
		if(cards[i].num == cards[i + 1].num && cards[i].pos > cards[i + 1].pos){
			printf("Not stable\n");
			break;
		}
	}
	if(i == n - 1)
		printf("Stable\n");

	// test
	for(i = 0; i < n; i++){
		printf("%c %d\n", cards[i].suit, cards[i].num);
	}

	return 0;
}
