echo "enter the no of terms"
read no
x=0
y=1
i=2
echo $x
echo $y
while [ $i -lt $no ]
do
z=$(($x+$y))
echo $z
x=$y
y=$z
i=$(($i+1))
done
