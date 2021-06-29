#include <iostream>
using namespace std;

int b[105];

int main(void)
{
	int n, flag, mini, swa;
	
	scanf("%d", &n);
	flag = 0;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
	}
	
	for(int i = 0; i < n; i++)
	{
		mini = i;
		for(int j = i; j < n; j++)
		{
			if(b[j] < b[mini])
			mini = j;
		}
		if(i != mini)
		{
		    swa = b[mini];
		    b[mini] = b[i];
		    b[i] = swa;
		    flag++;
		}
	}
	
	for(int i = 0; i < n; i++)
	{
	    printf("%d", b[i]);
	    if(i != n-1) printf(" ");
	}
	
	printf("\n");
	printf("%d\n", flag);
	
	return 0;
}
