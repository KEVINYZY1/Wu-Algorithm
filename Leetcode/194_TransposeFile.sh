#!/bin/sh
#输入的文件file.txt是按照行列矩阵形式排放内容，将其内容行列沿对角线对调，即转置
awk '
{ 
    for (i = 1; i <= NF; i++)  {
        a[NR, i] = $i
    }
}
NF > p { p = NF }
END {    
    for (j = 1; j <= p; j++) {
        str = a[1, j]
        for (i = 2; i <= NR; i++){
            str = str " " a[i, j]
        }
        print str
    }
}' file.txt