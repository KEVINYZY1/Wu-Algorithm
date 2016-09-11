#!/bin/sh
#打印一个文件中的第10行
#方法一，使用head和tail取出第10行。其中注意tail -n +10 的意思是取出文件第10行到文件末尾
head -n 10 file.txt | tail -n +10
#方法二，使用sed，-n是指安静模式
sed -n '10p' file.txt
#方法三，使用awk
awk 'NR==10 {print $0}' file.txt 
