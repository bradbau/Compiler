
CompileAndDump(){
    #-march=armv7-a

    FileName=$2
    FileNameNoExtention=${FileName%.*}
    constC="c"
    if [ "${FileName#*.}" = "$constC" ]
    then
        echo ${FileName#*.}=="c"    
        echo "compiling "$FileName
        #gcc $1"/"$2 -I /home/pi/CompilerContest/lib -L /home/pi/CompilerContest/lib -l sysy -o $1"/"$FileNameNoExtention".bin" -march=armv7-a
        #objdump -s -D -t $1"/"$FileNameNoExtention".bin" > $1"/"$FileNameNoExtention".s"
        # -O1
        #gcc $1"/"$2 -I /home/pi/CompilerContest/lib -L /home/pi/CompilerContest/lib -l sysy -o $1"/"$FileNameNoExtention"_O1.bin"  -march=armv7-a
        #objdump -s -D -t $1"/"$FileNameNoExtention"_O1.bin" > $1"/"$FileNameNoExtention"_O1.s"

        # -S
        gcc $1"/"$2 -I /home/pi/CompilerContest/lib -L /home/pi/CompilerContest/lib -l sysy -s   -march=armv7-a  #-o $1"/"$FileNameNoExtention"_O1.asm"
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

root_dir="/home/max/CompilerDesignCom/Compiler/test/testCase"


CompileAndDump $root_dir"/functional_test" "00_arr_defn2.c"

#apply $root_dir CompileAndDump
