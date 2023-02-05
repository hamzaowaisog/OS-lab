read -p "Enter the number to find its factorial " num
while [ $num -lt 0 ]
do 
	read -p "Negative number not accepted " num
done
if [ $num == 0 ]
then 
	echo "Factorial of number is 1"
else 
	for ((i=num ; i>=1 ; i--))
	do
		num=$((num * i))
	done
	echo "Factorial of number is $num"
fi
	
