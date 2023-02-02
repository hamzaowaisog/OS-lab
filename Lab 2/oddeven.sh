read -p "Enter number1 : " num1

if [ $((num1%2))  == 0 ]
then
  echo "$num1 is even"
else
  echo "$num1 is odd"
fi

