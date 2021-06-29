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

		for (int i = 0; i < arraySize; i++)
		{
			dataArray[i] = 0;
		}
	}

	~Array()
	{
		delete[] dataArray;
	}

	int& operator [](int n)
	{
		return dataArray[n];
	}

	Array(const Array& ob)
	{
		this->arraySize = ob.arraySize;
		
		for (int i = 0; i < arraySize; i++)
		{
			this->dataArray[i] = ob.dataArray[i];
		}
	}

	void ShowArray();

	void InsertionSort();
};

//昇順に挿入ソートする
void Array::InsertionSort()
{
	for (int i = 1; i < arraySize; i++)
	{
		int target = i;

		while (target >= 1 && dataArray[target -1] > dataArray[target])
		{			
			int temp = dataArray[target];

			dataArray[target] = dataArray[target - 1];
			dataArray[target - 1] = temp;

			target--; 
		}

		ShowArray();
	}
}

//要素間は空白で区切り、配列の中身を表示する
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
	//■入力ストリームからデータ取得
	int N;
	cin >> N;

	Array array1(N);

	for (int i = 0; i < N; i++)
	{	
		cin >> array1[i];
	}

	//■配列に格納されたデータの初期状態を表示
	array1.ShowArray();

	//■昇順に挿入ソート
	array1.InsertionSort();

	return 0;
}
