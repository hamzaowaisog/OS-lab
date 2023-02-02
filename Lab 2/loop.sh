read -p "Enter number :" num

for (( i = 1; i <= 10 ; i++))
do
	echo "$num * $i = $((i*num))"
done

