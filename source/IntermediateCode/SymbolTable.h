/* utf-8 */

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

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
    ConstVariable,
    Array,
} SysYCategory;

typedef enum ScopeType
{ 
    Global,
    Formal,
    Local
} ScopeType;

// Define scope 
struct ScopeItem{
  // private:
  //可能需要增加
    ScopeType stype;
    string name;
    string type; //for example: int void
    SysYCategory category; //for example: Variable Function
    ScopeItem *depictor;
    ScopeItem *next;
    int offset;
    int reg;
  // public:
  //   ScopeItem(ScopeType stype, string name, string type, SysYCategory category);
  //   void setDepictor(ScopeItem *depictor);
  //   void setOffset(int offset);
  //   void setReg(int reg);
  //   ScopeType getStype();
  //   string getName();
  //   string getType();
  //   SysYCategory getCategory();
  //   ScopeItem* getDepictor();
  //   int getOffset();
  //   int getReg();
};

// class Hashtable{
//   private: 
//      //哈希表，具体类型自定
//      hash_map<string, ScopeItem> hmap;
//   public: 
//      Hashtable() {}
//      //返回有多少表项
//      int NumEntries();
//      //加入一个表项
//      void Enter(string key, ScopeItem *si);
//      //移除一个表项
//      void Remove(string key, ScopeItem *si);
//      //展示此表
//      void Display();

// };

ScopeItem* addIntoScope(ScopeType stype, ScopeItem* pre_si, string name, SysYCategory category, string type, ScopeItem* depictor);
ScopeItem* mergeScope(ScopeItem *s1, ScopeItem *s2);

#endif