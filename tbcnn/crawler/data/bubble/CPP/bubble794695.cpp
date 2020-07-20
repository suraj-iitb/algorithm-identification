#include <iostream>
using namespace std;

int *createList(int num)
{
	int i, *list = new int[num];
	for (i = 0; i < num; i++)
		cin >> list[i];
	return list;
}

void bubbleSort(int num, int *list)
{
	int i, j, temp, swaps = 0;
	for (i = 0; i < num; i++)
	{
		for (j = num - 1; j >= 0; j--)
		{
			if (list[j] < list[j - 1])
			{
				temp = list[j];
				list[j] = list[j - 1];
				list[j - 1] = temp;
				swaps++;
			}
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
	bubbleSort(num, list);
	return 0;
}
