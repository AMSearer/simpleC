#!/bin/bash

ec="expected"
ac="actual"

rm -Rf ${1}.out  | true
rm rand.txt | true
touch rand.txt

bash -c "gcc -o ${1}.out ${1}.c"

for ((i=0; i<10; i++)); do
  echo $(( $RANDOM % 100 )) >> rand.txt
done

input_file="rand.txt"

ec=$(awk '{s+=$1}END{print s}' ${input_file})
ac=$(./${1}.out ${input_file})

if [[ ${ec} == ${ac} ]]; then
  echo "Test passes"
else
  echo "${1} fails"
  cat ${input_file}
  echo "Expected: " ${ec}  
  echo "Actual:   " ${ac}
fi

rm rand.txt ${1}.out
