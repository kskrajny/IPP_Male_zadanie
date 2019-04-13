#!/bin/bash
for f in "$2"/*.in
do
 
valgrind --error-exitcode=15 --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all -q ./"$1" <$f 1>pal.out 2>pal.err;
diff --brief ${f%in}out pal.out &&
diff --brief ${f%in}err pal.err &&
echo "$f dziala" ||
true

done

rm pal.out
rm pal.err
