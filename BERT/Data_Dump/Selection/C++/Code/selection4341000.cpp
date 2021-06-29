//#pragma comment (linker,"/STACK:256000000")
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define next(a) ( ((a)+1)%SIZE )
#define ABS(x) ( (x)>0 ? x : -(x) )
#define MIN(x,y) ( (x) < (y) ? (x) : (y) )
#define MAX(x,y) ( (x) > (y) ? (x) : (y) )
#define INF 1000000000
#define SIZE 100000

#define INF 1000000000
#define LLINF 10000000000000000

typedef long long ll;

typedef struct queue
{
	int front;
	int rear;
	int *data;
}queue;

/*
void init(queue* p)
{
	p->front = 0;
	p->rear = 0;
}

void enqueue(queue *p,int x)
{
	if (next(p->rear) == p->front)
		printf("OVERFLOW!\n");
	p->data[p->rear] = x;
	p->rear = next(p->rear);
}

int dequeue(queue *p)
{
	int x;

	if (p->front == p->rear)
		printf("NO DADA\n");

	x = p->data[p->front];
	p->front = next(p->front);

	return x;
}

int empty(queue *p)
{
	return p->front == p->rear;
}

void print(char* str, int a, int b)
{
	int i;

	for (i = a; i <= b; i++)
		printf("%c", str[i]);
	printf("\n");
}
*/

void reverse(char* str, int a, int b)
{
	int i,j=0;
	char t;

	for (i = a; i <= (a + b) / 2; i++)
	{
		t = str[i];
		str[i] = str[b - j];
		str[b - j] = t;
		j++;
	}
}

void replace(char* str, int a, int b, char* temp)
{
	int i, j=0;

	for (i = a; i <= b; i++)
	{
		str[i] = temp[j];
		j++;
	}
}

double rad(int C)
{
	return M_PI * C / 180;
}

double distance(int* a, int* b, int n, int p)
{
	double sum = 0.0;

	int i, j;

	int max = 0;

	for (i = 0; i < n; i++)
	{
		sum += pow(ABS(a[i] - b[i]), p);

		if (ABS(a[i] - b[i]) > max)
			max = ABS(a[i] - b[i]);
	}

	if (p == INF)
		return max;

	return pow(sum, (double)1 / p);
}

/*
typedef struct Vector
{
	int data[10];
	int size;
	int max;
}Vector;

Vector *init()
{
	Vector* p;

	//p = malloc(sizeof(int)*(10+2));
	p = (Vector*)(sizeof(int) * 12);
	//p->data = (int*)malloc(sizeof(int) * 10);
	p->size = 0;
	p->max = 10;

	return p;
}

Vector* Extend(Vector* p)
{
	Vector* q;

	q = (Vector*)malloc(sizeof(int) * p->max * 2);

	memcpy(q, p, sizeof(int) * p->size);

	p->max *= 2;

	free(p);

	return q;
}

Vector *pushBack(Vector *p,int x)
{
	if (p->size == p->max)
		p = Extend(p);

	p->data[p->size++] = 1;

	return p;
}

int randomAccess(Vector* p,int x)
{
	return p->data[x];
}

Vector* popBack(Vector* p)
{
	//free(p->data[--(p->size)]);
	--p->size;
	return p;
}
*/

int max_array(int* p, int n, int a, int b)
{
	int i, max = -INF;

	for (i = a; i < b; i++)
	{
		if (p[i] > max)
			max = p[i];
	}
	return  max;
}

int min_array(int* p, int n, int a, int b)
{
	int i, min = INF;

	for (i = a; i < b; i++)
	{
		if (p[i] < min)
			min = p[i];
	}
	return  min;
}

int count(int* p, int n, int a, int b,int k)
{
	int count = 0, i;

	for (i = a; i < b; i++)
	{
		if (p[i] == k)
			count++;
	}
	return count;
}

int dic_sort(int* p,int a,int *q,int b)
{
	int i;
	for (i = 0; i < MIN(a, b); i++)
	{
		if (p[i] < q[i])
			return 1;
		else if(p[i] > q[i])
			return 0;
	}
	if (a < b)
		return 1;
	else 
		return 0;
}

void swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void insertion_sort(int a[], int n)
{
	int i, j;
	int k;

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d", a[j]);
			if (j < n - 1)
				printf(" ");
		}
		printf("\n");

		k = i;

		while (a[k] < a[k - 1] && k>0)
		{
			swap(&a[k], &a[k - 1]);
			k--;
		}
	}

}

int GCD(int x, int y)
{
	if (x < y)
		swap(&x, &y);

	int z;

	while (y > 0)
	{
		z = x;
		x = y;
		y = z % y;
	}
	return x;
}

int prime(int x)
{
	int i, j;

	for (i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
			return -1;
	}

	return 1;
}

int cnt = 0;

void bubble_sort(int* p, int n)
{
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j=n-1; j > i ; j--)
		{
			if (p[j] < p[j - 1])
			{
				swap(&p[j], &p[j - 1]);
				cnt++;
			}
		}
	}
}

void selection_sort(int* p, int n)
{
	int i, j, min;

	for (i = 0; i < n; i++)
	{
		min = i;
		for (j = i+1; j < n; j++)
		{
			if (p[j] < p[min])
				min = j;
		}
		if (min != i)
		{
			swap(&p[min], &p[i]);
			cnt++;
		}
	}
}

int main()
{
	int n;
	int a[100000];

	scanf("%d", &n);

	int i, j;
	
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	selection_sort(a, n);

	for (i = 0; i < n; i++)
	{
		if (i == n - 1)
			printf("%d\n%d\n",a[i],cnt);
		else
			printf("%d ", a[i]);
	}


}
