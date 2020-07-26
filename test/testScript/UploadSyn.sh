cp /home/max/CompilerDesignCom/Compiler/source/GrammarTree/* /home/max/CompilerDesignCom/UploadFolder/compiler/
cp /home/max/CompilerDesignCom/Compiler/source/IntermediateCode/* /home/max/CompilerDesignCom/UploadFolder/compiler/
cp /home/max/CompilerDesignCom/Compiler/source/ObjectCode/* /home/max/CompilerDesignCom/UploadFolder/compiler/
cp /home/max/CompilerDesignCom/Compiler/source/SymbolTable/* /home/max/CompilerDesignCom/UploadFolder/compiler/
cp /home/max/CompilerDesignCom/Compiler/source/SysY.l /home/max/CompilerDesignCom/UploadFolder/compiler/
cp /home/max/CompilerDesignCom/Compiler/source/SysY.y /home/max/CompilerDesignCom/UploadFolder/compiler/

git add .
cur_time="`date +%Y-%m-%d-%H:%m`" 
git commit -m "$cur_time auto update"
git push