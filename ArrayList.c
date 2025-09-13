#include "ArrayList.h"

typedef struct arraylist {
    PValue array;
    int arraySize;
    int size;
}ArrayList, * PArrayList;

static boolean exploreArray(PArrayList arraylist) {
    if (arraylist == null) return false;
    int newArraySize = arraylist->arraySize * 3 / 2 + 1;
    Value* newArray = (PValue)realloc(arraylist->array, sizeof(Value) * newArraySize);
    if (newArray == null) return false;
    arraylist->array = newArray;
    arraylist->arraySize = newArraySize;
    return true;
}

/*********************************************************************************/

PArrayList newArrayList() {
    PArrayList arraylist = (PArrayList)malloc(sizeof(ArrayList));
    if (!arraylist) return null;
    arraylist->arraySize = 10;
    arraylist->size = 0;
    arraylist->array = (PValue)calloc(10, sizeof(Value));
    return arraylist;
}

//释放动态数组
void ArrayList_free(PArrayList* arraylist) {
    if (arraylist != null && *arraylist != null) {//均非空才释放
        free((*arraylist)->array);
        free(*arraylist);
        *arraylist = null;
    }
}
//添加元素
void ArrayList_add(PArrayList arraylist, Value value) {
    if (arraylist == null) return;
    if (arraylist->size >= arraylist->arraySize) {
        if (!exploreArray(arraylist)) return;
    }
    arraylist->array[arraylist->size] = value;
    arraylist->size++;
}
//移除元素
void ArrayList_delete(PArrayList arraylist, int index) {
    int temp = 0;
    if (arraylist == null) return;
    if (index < 0 || index >= arraylist->size) return;
    arraylist->size--;
    for (temp = index; temp < arraylist->size; temp++) {
        arraylist->array[temp] = arraylist->array[temp + 1];
    }
}
//插入元素，是索引值和下一个的中间插入
void ArrayList_insert(PArrayList arraylist, int index, Value value) {
    int i = 0;
    if (arraylist == null) return;
    if (index >= arraylist->size) ArrayList_add(arraylist, value);
    for (i = arraylist->size; i > index; i--) {
        arraylist->array[i] = arraylist->array[i - 1];
    }
    arraylist->array[index] = value;
    arraylist->size++;
}
//获取动态数组的大小
int ArrayList_size(PArrayList arraylist) {
    return arraylist == null ? -1 : arraylist->size;
}
//获取元素第一次出现的位置
int ArrayList_firstOf(PArrayList arraylist, Value value, type_by type) {
    int i = 0;
    if (!arraylist)return -1;
    for (; i < arraylist->size; i++) {
        switch (type) {
        case type_char: if (value.Character == arraylist->array[i].Character) return i;
        case type_short: if (value.Short == arraylist->array[i].Short) return i;
        case type_int: if (value.Integer == arraylist->array[i].Integer) return i;
        case type_double: if (value.Long == arraylist->array[i].Long) return i;
        case type_long: if (value.Long == arraylist->array[i].Long) return i;
        case type_primary: if (value.primary == arraylist->array[i].primary) return i;
        case type_float: if (value.Integer == arraylist->array[i].Integer) return i;
        }
    }
    return -1;
}
//获取元素最后一次出现的位置
int ArrayList_lastOf(PArrayList arraylist, Value value, type_by type) {
    int i = 0;
    if (!arraylist)return -1;
    for (i = arraylist->size - 1; i >= 0; i--) {
        switch (type) {
        case type_char: if (value.Character == arraylist->array[i].Character) return i;
        case type_short: if (value.Short == arraylist->array[i].Short) return i;
        case type_int: if (value.Integer == arraylist->array[i].Integer) return i;
        case type_double: if (value.Long == arraylist->array[i].Long) return i;
        case type_long: if (value.Long == arraylist->array[i].Long) return i;
        case type_primary: if (value.primary == arraylist->array[i].primary) return i;
        case type_float: if (value.Integer == arraylist->array[i].Integer) return i;
        }
    }
    return -1;
}
//判断动态数组是否为空
boolean ArrayList_isEmipy(PArrayList arraylist) {
    return arraylist == null || arraylist->size == 0;
}
//获取数组元素
Value ArrayList_get(PArrayList arraylist, int index) {
    if (!arraylist) return (Value) { .Integer = -404 };
    if (index < 0 || index >= arraylist->size) return (Value) { .Integer = -404 };
    return arraylist->array[index];
}
