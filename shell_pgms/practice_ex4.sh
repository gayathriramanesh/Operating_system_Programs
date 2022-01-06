echo "enter a no"
read no
temp=$no
sum=0
c=0
while [ $temp -gt $c ]
do
b=$(($temp%10))
cube=$(($b*$b*$b))
sum=$(($sum+$cube))
temp=$(($temp/10))
done
if [ $sum == $no ]
then
echo "it is an armstrong number"
else 
echo "no"
fi