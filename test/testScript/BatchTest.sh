
run(){
    compiler_dir="/home/max/CompilerDesignCom/Compiler/source/compiler"
    FileName=$2
    echo ${FileName#*.}
    constSY="sy"
    if [ "${FileName#*.}" = "$constSY" ]
    then
         #生成输出文件名
        FilePathRoot=$2
        echo "running " $FilePathRoot
        FileNameNoExtention=${FileName%.*}
        irFileName=${FileNameNoExtention}".ir"
        irFileNameRoot=${irFileName}
        outFileName=${FileNameNoExtention}".s"

        touch $irFileNameRoot

        $compiler_dir -S -o $outFileName $FilePathRoot > $irFileNameRoot 2>&1
        echo "return value" $?
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
            echo "reading" $FilePathRoot
            #处理这个文本，输出一个.c文件，并添加头文件
            
            $2 $1 $FilePathRoot 
            #$2 ${FilePathRoot}
        fi  
    done
}

root_dir="/home/max/CompilerDesignCom/Compiler/test/testCase"


#CompileAndDump $root_dir"/functional_test" "00_arr_defn2.c"

apply $root_dir run
