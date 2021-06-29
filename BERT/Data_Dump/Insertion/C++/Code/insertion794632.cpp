#include <iostream>
using namespace std;

int *createList(int num)
{
	int i, *list = new int[num];
	for (i = 0; i < num; i++)
		cin >> list[i];
	return list;
}

void traceList(int num, int *list)
{
	int i;
	for (i = 0; i < num - 1; i++)
		cout << list[i] << " ";
	cout << list[num - 1] << endl;
}

void insertionSort(int num, int *list)
{
	int i, j, key;

	for (j = 1; j < num; j++)
	{
		traceList(num, list);
		
		key = list[j];
		i = j - 1;
		while (i >= 0 && list[i] > key)
		{
			list[i + 1] = list[i];
			i -= 1;
		}
		list[i + 1] = key;
	}
	traceList(num, list);
}

int main()
{
	int num, *list;
	cin >> num;
	list = createList(num);
	insertionSort(num, list);
	delete [] list;
	return 0;
}
