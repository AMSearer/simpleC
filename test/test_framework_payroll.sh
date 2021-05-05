#!/bin/bash

ec="expected"
ac="actual"

rm -Rf ${1}.out  | true

bash -c "gcc -o ${1}.out ${1}.c"

first=`shuf -n1 /usr/share/dict/words`
last=`shuf -n1 /usr/share/dict/words`
num=$(( ($RANDOM % 600) * 6 + 60))
rate=$(( $RANDOM % 20 ))
#rate=`awk -v n=1 -v seed="$RANDOM" 'BEGIN { srand(seed); for (i=0; i<n; ++i) printf("%.2f\n", rand() * 10) }'`

salary=`echo - | awk "{printf \"%.2f\", (${num} / 60.0) * ${rate}}"`

ec="$first $last: $salary"
ac=$(./${1}.out $last $first $num $rate)

if [[ "$2" == "debug" ]]; then
  echo ${ec}
  echo ${ac}
fi

if [[ ${ec} == ${ac} ]]; then
  echo "Test passes"
else
  echo "${1} fails"
  echo "First Name: ${first}"
  echo "Last Name: ${last}"
  echo "Hours (in minutes): ${num}"
  echo "Rate: ${rate}"
  echo "Expected: " ${ec}  
  echo "Actual:   " ${ac}
fi

rm ${1}.out
