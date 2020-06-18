#include <hash_map>
#include <string>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef enum DecafCategory
{
   
    Variable,
    Function,
    Block,
    Const
} DecafCategory;


// Define scope 
class ScopeItem{
  private:
  //可能需要增加
    char* name;
    char* type;
    int offset;
    int reg;
    DecafCategory category;
    Hashtable *depictor;
  public:
    ScopeItem();
    //设置具体内容!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //SetScopeItem(char* name, char* type,int offset,int reg,DecafCategory category, Hashtable *depictor);
    //各种get方法根据需要定义
};



class Hashtable{

  private: 
     //哈希表，具体类型自定
     hash_map<int,ScopeItem> mmap;
 
   public: 
     Hashtable() {}
     //返回有多少表项
     int NumEntries();
     //加入一个表项
     void Enter(int key, ScopeItem si);
     //移除一个表项
     void Remove(int key, ScopeItem si);
     //展示此表
     void Display();

};