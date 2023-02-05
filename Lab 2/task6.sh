function file_count()
{
	local no_file=$(ls -l | wc -l)
	echo "Number of files in the directory is $no_file"
}

file_count
