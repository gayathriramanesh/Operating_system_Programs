echo "enter a number"
read n
sum=0
i=1
if [ $n -gt -1 ]
then
while [ $i -le $n ]
do
        sum=$(( $sum + $i ))
        i=$(( $i + 1 ))
done
echo $sum
else
        echo "enter a positive number"

fi