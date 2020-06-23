# dev-zyz
- 内容：符号表&作用域栈接口
- [编译器在线技术文档](https://shimo.im/docs/QGTJKqVGrkrYYkhg)
- /source 源码   /doc 测试文件
- 运行方法
  - 终端进入source文件夹，然后依次执行下面的指令
  - flex SysY.l
  - bison -d SysY.y
  - g++ -o parser SymbolTable.cpp AST.cpp stack.cpp SysY.tab.c lex.yy.c
  - ./parser 测试文件路径