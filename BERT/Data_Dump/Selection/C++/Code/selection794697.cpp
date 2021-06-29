#include <iostream>
using namespace std;

int *createList(int num)
{
	int i, *list = new int[num];
	for (i = 0; i < num; i++)
		cin >> list[i];
	return list;
}

void selectionSort(int num, int *list)
{
	int i, j, mini, temp, swaps = 0;
	for (i = 0; i < num; i++)
	{
		mini = i;
		for (j = i; j < num; j++)
			if (list[j] < list[mini]) mini = j;
		if (i != mini)
		{
			temp = list[i];
			list[i] = list[mini];
			list[mini] = temp;
			swaps++;
		}
	}
	for (i = 0; i < num - 1; i++)
		cout << list[i] << " ";
	cout << list[num - 1] << endl;
	cout << swaps << endl;
}

int main()
{
	int num, *list;
	cin >> num;
	list = createList(num);
	selectionSort(num, list);
	return 0;
}
