file=test.sh
read -p "Enter the word " word
echo "File before removing $word"
cat $file
grep -v -i $word $file > test
mv test $file
echo "file after removing $word"
cat $file
