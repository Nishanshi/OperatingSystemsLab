flag=0
if [ ! "$1" ]
then
	flag=1
fi

echo $n
if [ $flag -eq 1 ]
then 
	echo $(( (50*50 + 50)/2 ))
	
else
	 echo $(( (n*n + n)/2 ))
fi
