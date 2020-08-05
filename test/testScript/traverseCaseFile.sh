#!/bin/bash

GenerateStdC() {
    FileName=$2
    echo ${FileName#*.}
    if [ ${FileName#*.}="sy" ]
    then
         #生成输出文件名
        FilePathRoot=$1"/"$2
        echo $FilePathRoot
        FileNameNoExtention=${FileName%.*}
        StdCFileName=${FileNameNoExtention}".c"
        StdCFileNameRoot=$1"/"${StdCFileName}

        #生成输出文件
        cp $FilePathRoot $StdCFileNameRoot
        #添加头文件
        sed -i '1 i #include"sylib.h"' $StdCFileNameRoot
    fi
   

}


apply() {
    #参数表 $1 文件路径 $2 对文件应用的函数
    for element in `ls $1`
    do  
        FilePathRoot=$1"/"$element
        if [ -d $FilePathRoot ]
        then 
            apply $FilePathRoot $2
        else
            #echo $FilePathRoot
            #处理这个文本，输出一个.c文件，并添加头文件
            $2 $1 $element
            #$2 ${FilePathRoot}
        fi  
    done
}

root_dir="/home/pi/CompilerContest/testCase"
#apply $root_dir GenerateStdC
apply $root_dir GenerateStdC
#GenerateStdC /home/pi/CompilerContest/testCase/functional_test 00_arr_defn2.sy