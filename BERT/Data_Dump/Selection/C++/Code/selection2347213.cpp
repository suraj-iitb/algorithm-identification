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

    int N, a[100],d=0, i, j,min;
	cin >> N;
    for (i = 0; i < N; i++)
        cin >> a[i];
	for (i=0; i<N-1 ; i++)
		{		min = i;
			for(j = i+1; j <N ; j++)
				if (a[j ] < a[min]) 
					min = j;
			if (min!=i)  
			{
                 Swap(a[min],a[i]);
					d++;
			}
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
