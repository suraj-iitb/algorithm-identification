def trace( nums ):
	output = []
	for num in nums:
		output.append( str( num ) )
		output.append( " " )
	output.pop( )
	print( "".join( output )  )

n = int( input( ) )
nums = [ int( val ) for val in input( ).split( " " ) ]
trace( nums )

for i in range( 1, len( nums ) ):
	key = nums[i]
	j = i - 1
	while 0 <= j and key < nums[j]:
		nums[ j+1 ] = nums[j]
		j -= 1
	nums[ j+1 ] = key
	trace( nums )
