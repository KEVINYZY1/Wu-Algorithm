#!/bin/sh
#方法一
#tr -s: truncate the string with target string, but only remaining one instance (e.g. multiple whitespaces)
#sort: To make the same string successive so that uniq could count the same string fully and correctly.
#uniq -c: uniq is used to filter out the repeated lines which are successive, -c means counting
#sort -r: -r means sorting in descending order
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{ print $2, $1 }'
#方法二，awk
awk '{
    for(i=1; i<=NF; i++)
        a[$i]++
}
END{
    for(k in a)
        print k, a[k];
}' words.txt | sort -rnk2