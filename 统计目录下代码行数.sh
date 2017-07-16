#!/bin/bash
# Author: Wu zhenzhong.
#Date & Time: 2017-01-11 20:55:30
#Description: 统计目录下所有文件的代码行数.

#熟悉find、xargs和wc的用法
#注意print0和-0，分隔符是‘\0‘，都是为了把多行输出改成一行输出
find . -maxdepth 2 -type f -name "*.cc" -print0 | xargs -0 wc -l >> fuck
find . -maxdepth 2 -type f -name "*.h" -print0 | xargs -0 wc -l >> fuck
find . -maxdepth 2 -type f -name "*.sql" -print0 | xargs -0 wc -l >> fuck
find . -maxdepth 2 -type f -name "*.sh" -print0 | xargs -0 wc -l >> fuck

#awk处理fuck
awk '
BEGIN{
    sum=0
}
$2==total
{
    sum+=$1;
}
END{
    print "你已经完成了%d行代码，加油！\n", sum;
}
' fuck

rm ./fuck