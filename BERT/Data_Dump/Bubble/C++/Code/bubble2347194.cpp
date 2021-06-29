#include <iostream>
using namespace std;
void Swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main(void)
{

    int N, a[100],d=0, i, j;
	cin >> N;
    for (i = 0; i < N; i++)
        cin >> a[i];
	for (i = 0 ; i<N-1 ; i++)
		for (j =N-1; j >i ; j --)
			if(a[j]< a[j-1])
			{
				Swap(a[j], a[j-1]);
				d++;
			}
	for (i = 0; i < N; i++)
	{
		if(i<N-1)
			cout << a[i] << " ";
		else
			cout<< a[i];
	}
	cout<<endl;
	cout<<d<<endl;
    return 0;
}
