#include<iostream>
using namespace std;
int main()
{
	int N,*sort,i,j,k,v;
	cin >> N;
	sort = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
		cin >> sort[i];
	for (i = 0; i < N; i++)
	{
		v = sort[i];
		k = i-1;
		while (k>=0&&sort[k]>v)
		{
			sort[k + 1] = sort[k];
			k--;
		}
		sort[k + 1] = v;
		for (j = 0; j < N-1; j++)
			cout << sort[j]<<' ';
		cout << sort[N-1] << endl;
	}
	return 0;
}
