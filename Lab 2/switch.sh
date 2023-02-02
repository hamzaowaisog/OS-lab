fruit="Apple"

case "$fruit" in 
	"Apple") echo "Apple is red."
	;;
	"Orange") echo "Orange is orange"
	;;
	"Grape") echo "Grape is green"
	;;
	*) echo "Not a valid fruit"
	;;
esac

