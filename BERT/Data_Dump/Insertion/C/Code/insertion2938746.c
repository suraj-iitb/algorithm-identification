int main()
{
  int i   , j = 0 ,N,A[1000] , v,count =0;
  scanf("%d",&N);

  for( i = 0 ; i < N; i++) scanf("%d",&A[i]);
        for(count =0 ; count < N ; count++) 
        {
            if(count == N - 1) 
            {
                printf("%d",A[count]);
		//printf("test\n");
            break;
            }
            printf("%d ", A[count] );
    }
	if(N >1)printf("\n");
   

   ///////////////////////////////////////ソート本体
  for(i = 1 ; i <N ; i++)
    {
      v = A[i];
      j = i -1 ;

      while( j  >= 0 && A[j] > v)
	{
	  A[ j+1 ] = A[j];
	  j--;
	  A[j+1] = v;

	}
      // //////////////////////////////////////
      for(count =0 ; count < N ; count++)
	{
	  if(count == N -1 )
	    {
	      printf("%d",A[count]);
	      break;
		}
	  printf("%d ", A[count] );
	}
      if(i <N-1)printf("\n");
	
    }
  printf("\n");
}

