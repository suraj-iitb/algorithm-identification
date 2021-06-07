#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 65521

typedef struct _data
{
	int val;
	int flag;
	struct _data *next;
} data;

int hashKey(int key)
{
	return key % HASH_SIZE;
}


int add(data **table, int val)
{
	int key = hashKey(val);
	data *p = table[key];
	data *tmp;

	while (p != NULL)
	{
		if (p->val == val) return 1;
		p = p->next;
	}

	if ((tmp = (data*)malloc(sizeof(data))) == NULL) return -1;
	tmp->val = val;
	tmp->flag = 0;
	tmp->next = table[key];
	table[key] = tmp;

	return 0;	
}

data *search(data **table, int val)
{
	int key = hashKey(val);
	data *p = table[key];

	while (p != NULL)
	{
		if (p->val == val) return p;
		p = p->next;
	}
	return NULL;
}

void terminate(data **table)
{
	int i;
	data *p, *next;

	for (i = 0; i < HASH_SIZE; i++)
	{
		p = table[i];
		while (p != NULL)
		{
			next = p->next;
			free(p);
			p = next;
		}
		table[i] = NULL;
	}
}

int main()
{
	data *table[HASH_SIZE];
	data *p;
	int i, n, val, count;

	for (i = 0; i < HASH_SIZE; i++) table[i] = NULL;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &val);
		if (add(table, val) < 0) return -1;
	}

	count = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &val);
		if ((p = search(table,val)) == NULL || p->flag) continue;
		count++;
		p->flag = 1;
	}
	printf("%d\n", count);

	terminate(table);

	return 0;
}
