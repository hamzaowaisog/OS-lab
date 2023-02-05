read -p "Enter the Height :" height
read -p "Enter the breadth :" breadth
read -p "Enter the length :" length

area_tri=$((breadth*height/2))
area_sq=$((length*length))
area_rec=$((length*breadth))

echo "Area of triangle is $area_tri cm^2"
echo "Area of square is $area_sq cm^2"
echo "Area of rectangle is $area_rec cm^2"

