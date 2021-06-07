#include <stdio.h>

#define T_MAX 500
#define S_MAX 10000

int main()
{
	int s[S_MAX];
	int t[T_MAX];
	int i;
	int s_n,t_n;
	int cnt = 0;
	int j;


	scanf("%d",&s_n);
	for(i = 0; i < s_n; i++)
	{
		scanf("%d",&s[i]);
	}
	//printf("s[1] = %d\n",s[1]);

	scanf("%d",&t_n);
	for(i = 0; i < t_n; i++)
	{
		scanf("%d",&t[i]);
	}

	for(i = 0; i < t_n; i++)
	{

		s[s_n] = t[i];
		j = 0;
		while(s[j] != s[s_n])
		{

			j++;
	//					printf("s[j]: %d, s[t_n]: %d, j: %d\n",s[j],s[t_n],j);
		}
		if(j == s_n)
		{
			cnt = cnt;
		}
		else
		{
			//printf("%d %d",j,s_n);
			cnt++;
		}
	}

	printf("%d\n",cnt);


	return 0;
}
