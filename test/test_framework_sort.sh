#!/bin/bash

ec="expected"
ac="actual"

rm -Rf ${1}.out  | true
rm -Rf multilines.txt expected.txt result.txt | true

bash -c "gcc -o ${1}.out ${1}.c"
touch multilines.txt

lines=$(( $RANDOM % 10 + 5))
unsorted=()
for ((i=0; i<$lines; i++)); do
  nums=$(( $RANDOM % 5 + 2))
  tmp=""
  for ((j=0; j<$nums; j++)); do
    val=$(( $RANDOM % 100))
    unsorted+=($val)
    tmp="$tmp$val "
  done
  echo $(echo -e "${tmp}" | sed -e 's/[[:space:]]*$//')  >> multilines.txt
done

readarray -t sorted < <(for n in "${unsorted[@]}"; do echo "$n"; done | sort -n)
exp=""
for n in "${sorted[@]}"; do
  exp="$exp$n "
done
echo $(echo -e "${exp}" | sed -e 's/[[:space:]]*$//')  >> expected.txt

ec="Files expected.txt and result.txt are identical"
./${1}.out multilines.txt > result.txt
ac=$(diff -s expected.txt result.txt)

if [[ ${ec} == ${ac} ]]; then
  echo "Test passes"
else
  echo "Original file:"
  cat multilines.txt
  echo "Expected sorted result:"
  cat expected.txt
  echo "Your sorted result:"
  cat result.txt
  echo "Expected: " ${ec}  
  echo "Actual:   " ${ac}
fi

rm -Rf ${1}.out multilines.txt expected.txt result.txt
