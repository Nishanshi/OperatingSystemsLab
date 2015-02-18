echo "enter a string"
read string
y=$(echo $string|rev)

len=${#string}
flag=0
for (( i=1;i<=$len;i++ ))
do
	if test ${string:$i:1} = ${y:$i:1}
	then 
		continue
	else
		flag=1
		break
	fi	
done	

if [ $flag -eq 0 ]
then 
	echo "plaindrome"
else
	echo "no palindrome"
fi	 
