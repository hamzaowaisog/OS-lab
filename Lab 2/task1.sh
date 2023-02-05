dis=task5.sh

if [ -f "$dis" ]
then
	echo "$dis passowrds are enabled"
	if [ -w "$dis" ]
	then
		echo "you have permission to edit $dis"
	else
		echo "you do NOT have permissions to edit $dis"
	fi
else
	echo "$dis File does not exist"
fi

