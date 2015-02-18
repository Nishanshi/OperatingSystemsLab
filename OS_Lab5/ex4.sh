y=$(ls -l|tr -s " "|cut -d' ' -f 5|sort -nr|head -n1)
echo $y
