read -p "Enter the number" num
count_even=0
count_odd=0
for ((i=0 ; i<=num ; i++))
do
	if [ $((i%2)) == 0 ]
	then
		echo "$i is even"
		((count_even++))
	else
		echo "$i is odd"
		((count_odd++))
	fi
done

echo "Number of evens are $count_even"
echo "Number of odds are $count_odd"

