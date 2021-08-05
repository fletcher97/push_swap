max=0
for i in {1..100};
do
	COUNT=$2
	LIMIT=$3
	ARG=`seq $COUNT | shuf | paste -sd " "`
	tot=`$1 $ARG | wc -l`
	if [ $max -eq 0 ];
	then
		min=$tot
	fi
	if [ $min -gt $tot ];
	then
		min=$tot
	fi
	if [ $max -lt $tot ];
	then
		max=$tot
	fi
	if [ $tot -gt $LIMIT ];
	then
		echo "Over $LIMIT - Total: $tot - exceeded by: $(( $tot - $LIMIT ))"
	else
		echo "OK"
	fi;
done

echo "Max: $max - Min: $min - Diff: $(( $max - $min ))"
