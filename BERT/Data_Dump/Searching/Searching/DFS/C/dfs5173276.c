#include <stdio.h>
#include <assert.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#define MAX 100

int num;
int timeum = 0; 
int dum[MAX+1], fum[MAX+1];
int Mum[MAX+1][MAX+1] = {0};
int countum[MAX+1] = {0}; 


int main(void)
{
	int ium, jum, uum, kum, vum;

	scanf("%d", &num);

	for( ium=1; ium<num+1; ium++ )
	{
		scanf("%d", &uum);
		scanf("%d", &kum);

		for( jum=1; jum<kum+1; jum++ )
		{
			scanf("%d", &vum);

			Mum[uum][vum] = 1;
		}
	}

	for( ium=1; ium<num+1; ium++ )
	{
		if( countum[ium] == 0 )
		{
			visitum(ium);
		}
	}

	for( ium=1; ium<num+1; ium++ )
	{
		printf("%d %d %d\n", ium, dum[ium], fum[ium]);
	}

	return 0;
}
void visitum(int uum)
{
	int ium;

	timeum++; 

	countum[uum] = 1; 
	dum[uum] = timeum; 

	for(ium=1;ium<num+1;ium++ )
	{
		if( (Mum[uum][ium] == 1) && (countum[ium] == 0) ) 
		{
			visitum(ium); 
		}
	}

	timeum++; 
	countum[uum] = 2; 
	fum[uum] = timeum; 
}


