#include<iostream>
using namespace std;
int main()
{
	int N, i, j, * sort,flag=1,num=0,temp;
	cin >> N;
	sort = (int*)malloc(sizeof(int) * N);
	for (i = 0; i < N; i++)
		cin >> sort[i];
	for(i=0;i<N&&flag==1;i++)
		for(j=N-1,flag=0;j>i;j--)
			if (sort[j - 1] > sort[j])
			{
				temp = sort[j - 1];
				sort[j - 1] = sort[j];
				sort[j] = temp;
				num++;
				flag = 1;
			}
	for (i = 0; i < N - 1; i++)
		cout << sort[i] << ' ';
	cout << sort[N - 1] << endl;
	cout << num << endl;
	return 0;
}
