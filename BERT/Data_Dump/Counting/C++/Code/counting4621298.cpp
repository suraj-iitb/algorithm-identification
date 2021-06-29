#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>

#define MAX_LEN 1000000

using namespace std;

void printArray1(int *data, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d", data[i]);
		if (i != len - 1) printf(" ");
	}
	printf("\n");
}

void printArray2(int *data, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", data[i]);
	}
}

void swap(int *a, int i, int j)
{
	int temp;
	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

struct card
{
	int n;
	char c;
};

void printArray(card *cards, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%c", cards[i].c);
		printf(" ");
		printf("%d", cards[i].n);
		printf("\n");
	}

}

void swap(card *cards, int i, int j)
{
	card temp;
	temp = cards[i];
	cards[i] = cards[j];
	cards[j] = temp;
}

int compare(card c1, card c2)
{
	if (c1.n < c2.n)
	{
		return -1;
	}
	else if (c1.n == c2.n)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

bool isSame(card *cards1, card *cards2, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (cards1[i].n != cards2[i].n)return false;
		if (cards1[i].c != cards2[i].c)return false;
	}
	return true;
}

void BubbleSort(card *cards, int len, int(*compare)(card, card))
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = len - 1; j > i; j--)
		{
			if (compare(cards[j - 1], cards[j]) > 0)
			{
				swap(cards, j - 1, j);
			}
		}
	}
}

void SelectionSort(card *cards, int len, int(*compare)(card, card))
{
	for (int i = 0; i < len - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (compare(cards[j], cards[min]) < 0)
			{
				min = j;
			}
		}
		swap(cards, i, min);
	}
}

int g[MAX_LEN];
int m = 0;
int cnt = 0;

void insertSort(int *data, int len, int g)
{
	for (int i = g; i < len; i++)
	{
		int v = data[i];
		int j = i;
		while (j >= g && data[j - g] > v)
		{
			data[j] = data[j - g];
			j -= g;
			cnt++;
		}
		data[j] = v;
	}
}

void shellSort(int *data, int len)
{
	int v;
	for (v = 1; v * 3 + 1 < len; v = 3 * v + 1);
	for (int i = 0; i < len && v > 0; i++, v /= 3)
	{
		g[i] = v;
		m++;
	}
	for (int i = 0; i < m; i++)
	{
		insertSort(data, len, g[i]);
	}
}

card cards1[MAX_LEN];
card cards2[MAX_LEN];
card temp[MAX_LEN];

void mergeSort(card *data, int begin, int end)
{
	if (begin >= end)return;
	int middle = (begin + end) / 2;
	mergeSort(data, begin, middle);
	mergeSort(data, middle + 1, end);

	for (int i = begin; i <= middle; i++)
	{
		temp[i] = data[i];
	}
	for (int i = middle + 1, j = end; i <= end; i++, j--)
	{
		temp[i] = data[j];
	}

	int left = begin;
	int right = end;
	for (int i = begin; i <= end; i++)
	{
		cnt++;
		if (compare(temp[left], temp[right]) <= 0)
		{
			data[i] = temp[left];
			left++;
		}
		else
		{
			data[i] = temp[right];
			right--;
		}
	}
}

void quickSort(card *data, int begin, int end)
{
	int left = begin;
	int right = end;
	card pivot = data[(begin + end) / 2];

	while (true)
	{

		while (compare(data[left], pivot) < 0)left++;
		while (compare(data[right], pivot) > 0)right--;
		if (left >= right) break;
		swap(data, left, right);
		left++;
		right--;
	}
	if (begin < left - 1) quickSort(data, begin, left - 1);
	if (right + 1 < end) quickSort(data, right + 1, end);
}

#define MAX_LENGTH 2000000

#define MAX_VAL 10000

int input[MAX_LENGTH];

int output[MAX_LENGTH];

int my_count[MAX_VAL + 1];

void countingSort(int *input, int *output, int len)
{
	for (int i = 0; i <= MAX_VAL; i++)my_count[i] = 0;
	
	for (int i = 0; i < len; i++)my_count[input[i]]++;

	for (int i = 0; i < MAX_VAL; i++)my_count[i + 1] += my_count[i];

	for (int i = 0; i < len; i++)
	{
		output[--my_count[input[i]]] = input[i];
	}
}

int main()
{
	int len;
	scanf("%d", &len);

	for (int i = 0; i < len; i++)
	{
		scanf("%d", &input[i]);
	}

	countingSort(input, output, len);

	printArray1(output, len);

	//int len;
	//scanf("%d", &len);

	//for (int i = 0; i < len; i++)
	//{
	//	int n;
	//	char c;
	//	std::cin >> c >> n;
	//	cards1[i].n = n;
	//	cards1[i].c = c;
	//	cards2[i].n = n;
	//	cards2[i].c = c;
	//}
	//quickSort(cards1, 0, len - 1);
	//mergeSort(cards2, 0, len - 1);
	//if (isSame(cards1, cards2, len))
	//{
	//	printf("Stable\n");
	//}
	//else
	//{
	//	printf("Not stable\n");
	//}
	//printArray(cards1, len);
}
