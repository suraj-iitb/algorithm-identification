#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &vec)
{
	int cmp_num = 0;
	int vec_size;
	int tmp;

	vec_size = vec.size();

	for(int i = 1; i <= vec_size-1; i++)
	{
		for(int j = vec_size-1; j >= i; j--)
		{
			if( vec[j] < vec[j-1])
			{
				tmp = vec[j];
				vec[j] = vec[j-1];
				vec[j-1] = tmp;
				cmp_num++;
			}
		}
	}

	for(int i = 0; i < vec_size-1; i++)
	{
		cout << vec[i] << " ";
	}
	cout << vec[vec_size-1] << endl;
	cout << cmp_num << endl;

	return;
}

int main(void)
{
	int n;
	
	cin >> n;
	vector<int> A(n);

	//データ入力
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	bubbleSort(A);

	return 0;
}

