#include <stdio.h>

#define T_MAX 50000
#define S_MAX 100000

int main()
{
	int s[S_MAX];
	int t[T_MAX];
	int i;
	int s_n,t_n;
	int cnt = 0;
	int j;
	int m,r,l;
	int roop = 0;


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
		r = s_n-1;
		l = 0;
		m = (r+l)/2;
		s[s_n] = t[i];

		while( l < r)
		{
			//roop++;
		//	printf("l: %d, r: %d, s[m]: %d, s[s_n]: %d\n",l,r,s[m],s[s_n]);
			if(s[m] < s[s_n])
			{
					l = m+1;
			}
			else if(s[m] > s[s_n])
			{
					r = m;
			}
			else break;
			m = (r+l)/2;
		}

		//printf("r: %d, l: %d, roop:%d\n",r,l,roop);
	//	printf("s[m]: %d, key = %d\n",s[m],s[s_n]);
		if(s[m] == s[s_n])cnt++;

	}
	printf("%d\n",cnt);


}
