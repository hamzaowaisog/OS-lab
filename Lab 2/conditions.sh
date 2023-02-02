a=10
b=5
if [ $a == $b ]
then
  echo $a "is equal to" $b
elif [ $a -gt $b ]
then
  echo $a "is greater than" $b
elif [ $a -lt $b ]
then
  echo $a "is less than" $b
else
  echo "paappi paapi chooolo"
fi

