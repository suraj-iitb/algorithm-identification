def selectionSort( nums ):
	cnt = 0
	for i in range( 0, len( nums ) ):
		mini = i
		for j in range( i , len( nums ) ):
			if nums[j] < nums[ mini ]:
				mini = j
		if mini != i:
			cnt += 1
			nums[i], nums[ mini ] = nums[ mini ], nums[i]

	print( " ".join( map( str, nums) ) )
	print( cnt )


n = int( input( ) )
nums = [ int( val ) for val in input( ).split( " " ) ]
selectionSort( nums )
