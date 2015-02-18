filename1=$1
filename2=$2

y=$(cat $filename1 >> $filename2)
echo $y
