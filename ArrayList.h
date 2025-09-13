#ifndef __ARRAYLIST_C_TOWEN_H__
#define __ARRAYLIST_C_TOWEN_H__

#include <stdlib.h>

#ifndef null
#define null ((void*)0)
#endif //null

#ifndef __BOOLEAN_C__
#define true 1
#define false 0
typedef char boolean;
#endif //__BOOLEAN_C__

// other structure from towen can use this union
#ifndef __TYPE_SELFMAKE_C__

typedef union values{
    char Character;
    short Short;
    int Integer;
    long Long;
    float Float;
    double Double;
    void* primary;
}Value,*PValue;

// types define
#define type_char 0x01
#define type_short 0x02
#define type_int 0x04
#define type_long 0x08
#define type_float 0x14
#define type_double 0x18
#define type_primary 0x00

typedef char type_by;

#endif //__TYPE_SELFMAKE_C__

typedef struct arraylist ArrayList, * PArrayList;

//获得新数组指针
PArrayList newArrayList();
//释放动态数组
void ArrayList_free(PArrayList* arraylist);
//添加元素
void ArrayList_add(PArrayList arraylist, Value value);
//移除元素
void ArrayList_delete(PArrayList arraylist, int index);
//插入元素，是索引值和下一个的中间插入
void ArrayList_insert(PArrayList arraylist, int index, Value value);
//获取动态数组的大小
int ArrayList_size(PArrayList arraylist);
//获取元素第一次出现的位置
int ArrayList_firstOf(PArrayList arraylist, Value value,type_by type);
//获取元素最后一次出现的位置
int ArrayList_lastOf(PArrayList arraylist, Value value,type_by type);
//判断动态数组是否为空
boolean ArrayList_isEmipy(PArrayList arraylist);
//获取元素
Value ArrayList_get(PArrayList arraylist, int index);


#endif //__ARRAYLIST_C_TOWEN_H__
