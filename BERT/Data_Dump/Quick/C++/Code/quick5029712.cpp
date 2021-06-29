#include<stdio.h>

struct Card {
	char mark;
	int number, order;
};

int partition(Card[], int, int);
void quicksort(Card[], int, int);
void swap(Card*, Card*);
bool check(Card[], int);

int main()
{
	Card *cards;
	int n;
	bool flag = 1;
	scanf("%d", &n);
	cards = new Card[n];
	for (int i = 0; i < n; i++)
	{
		scanf(" %c %d", &cards[i].mark, &cards[i].number);
		cards[i].order = i;
	}

	quicksort(cards, 0, n - 1);
	
	if (check(cards, n))
		printf("Stable\n");
	else
		printf("Not stable\n");
	for (int i = 0; i < n; i++)
		printf("%c %d\n", cards[i].mark, cards[i].number);
	delete[] cards;

	return 0;
}

void swap(Card *a, Card *b)
{
	Card tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

int partition(Card cards[], int left, int right)
{
	int i, x;
	x = cards[right].number;
	i = left;
	for (int j = left; j < right; j++)
		if (cards[j].number <= x)
		{
			swap(cards + i, cards + j);
			i++;
		}
	swap(cards + i, cards + right);

	return i;
}

void quicksort(Card cards[], int left, int right)
{
	if (left < right)
	{
		int q;
		q = partition(cards, left, right);
		quicksort(cards, left, q - 1);
		quicksort(cards, q + 1, right);
	}
	return;
}

bool check(Card cards[], int n)
{
	for (int i = 0; i < n - 1; i++)
		if (cards[i].number == cards[i + 1].number && cards[i].order > cards[i + 1].order)
			return false;
	return true;
}

