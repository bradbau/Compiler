cp -r /home/max/CompilerDesignCom/Compiler/source/  /home/max/CompilerDesignCom/UploadFolder/compiler

cd /home/max/CompilerDesignCom/UploadFolder/compiler/
rm -rf source/Optimization
git add .
cur_time="`date +%Y-%m-%d-%H:%m`" 
git commit -m "$cur_time auto update"
git push