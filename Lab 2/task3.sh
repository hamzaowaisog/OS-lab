read -p "Enter the file name or directory name " file

if [[ -d $file ]]
then
	echo "$file is a directory"
elif [[ -f $file ]]
then 
	echo "$file is a regular file"
else
	echo "$file is an another type of file"
fi

