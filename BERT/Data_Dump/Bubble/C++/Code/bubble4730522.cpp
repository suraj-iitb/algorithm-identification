#include <iostream>

using namespace std;

class Array
{
	int* dataArray;
	int arraySize;

public:

	Array(int arraySize)
	{
		this->arraySize = arraySize;

		dataArray = new int[arraySize];
	}

	Array(const Array& ob);
	
	~Array()
	{
		delete[] dataArray;
	}


	int& operator [](int index)
	{
		return dataArray[index];
	}


	int BubbleSort();

	void ShowArray();

};

Array::Array(const Array& ob)
{
	this->arraySize = ob.arraySize;

	for (int i = 0; i < arraySize; i++)
	{
		this->dataArray[i] = ob.dataArray[i];
	}
}

int Array::BubbleSort()
{
	int count = 0;

	for (int i = 0; i < arraySize - 1; i++)
	{
		for (int j = arraySize - 1; i < j ; j--)
		{
			if (dataArray[j -1] > dataArray[j])
			{
				int temp = dataArray[j - 1];

				dataArray[j - 1] = dataArray[j];
				dataArray[j] = temp;

				count++;
			}
		}
	}

	return count;
}

void Array::ShowArray()
{
	for (int i = 0; i < arraySize; i++)
	{
		if (i > 0)
		{
			cout << " ";
		}
		cout << dataArray[i];
	}

	cout << endl;
}

int main()
{
	int dataSize;
	cin >> dataSize;

	Array data(dataSize);

	for (int i = 0; i < dataSize; i++)
	{
		cin >> data[i];
	}

	int count = data.BubbleSort();

	data.ShowArray();

	cout << count << endl;
}

