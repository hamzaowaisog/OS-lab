season="summer"

case "$season" in 
	"summer") echo "June July August"
	;;
	"winter") echo "December January February"
	;;
	"autumn") echo "september october november"
	;;
	"spring") echo "march april may"
	;;
	*) echo "No season exist"
	;;
esac
