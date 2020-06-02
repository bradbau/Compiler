#include <hash_map>
#include <string>
#include<stdio.h>
#include<stdlib.h>
#include <string>
using namespace std;

typedef enum SysYCategory
{ 
    Variable,
    Function,
    Block,
    Const,
    Array,
    Main  //Add type Main so that the Depictor struct can be removed
} SysYCategory;

typedef enum ScopeType
{ 
    Global,
    Formal,
    Local
} ScopeType;

// Define scope 
class ScopeItem{
  private:
  //可能需要增加
    ScopeType stype;
    string name;
    string type; //for example: int void
    SysYCategory category; //for example: Variable Function
    Hashtable *depictor;
    Hashtable *selfptr; //point to the hashtable which this item belongs to
    int offset;
    int reg;
  public:
    ScopeItem(ScopeType stype, string name, string type, SysYCategory category);
    void setDepictor(Hashtable *depictor);
    void setOffset(int offset);
    void setReg(int reg);
    ScopeType getStype();
    string getName();
    string getType();
    SysYCategory getCategory();
    Hashtable* getDepictor();
    int getOffset();
    int getReg();
};

class Hashtable{
  private: 
     //哈希表，具体类型自定
     hash_map<int,ScopeItem> hmap;
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