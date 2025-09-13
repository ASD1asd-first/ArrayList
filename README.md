# C 语言动态数组库（ArrayList）

一个轻量级、跨平台的动态数组实现，基于 C99 标准开发，提供灵活的元素管理功能，适合作为基础数据结构集成到各类 C 语言项目中。

## 项目简介

本项目实现了一个通用的动态数组（ArrayList），支持自动扩容、元素增删改查等核心操作，兼容多种基础数据类型（int、float、double、指针等）。代码结构简洁，无第三方依赖，可轻松移植到 Windows、Linux、macOS 等平台。

- **开发语言**：C99
- **构建工具**：CMake 3.28+
- **许可证**：MIT License
- **核心优势**：
  - 自动动态扩容（初始容量 10，扩容策略：原容量 × 3/2 + 1）
  - 类型无关设计（通过 union 支持多类型存储）
  - 完整的内存管理接口（避免内存泄漏）
  - 简洁 API，易于上手使用

## 核心功能

| 函数名                | 功能描述             | 关键参数                | 返回值说明              |
|----------------------|----------------------|------------------------|------------------------|
| `newArrayList()`     | 创建动态数组实例      | 无                      | 数组指针 (`PArrayList`) |
| `ArrayList_free()`   | 释放数组内存          | 数组指针的地址（`PArrayList*`）| 无               |
| `ArrayList_add()`    | 在末尾添加元素        | 数组指针、待添加元素（`Value`）| 无               |
| `ArrayList_delete()` | 根据索引删除元素       | 数组指针、元素索引         | 无                  |
| `ArrayList_insert()` | 在指定索引插入元素     | 数组指针、索引、待插入元素  | 无                  |
| `ArrayList_get()`    | 获取指定索引的元素     | 数组指针、索引             | 元素值（`Value`）    |
| `ArrayList_size()`   | 获取当前元素数量       | 数组指针                  | 元素个数（int）      |
| `ArrayList_firstOf()`| 查找元素首次出现的索引 | 数组指针、目标元素、元素类型 | 索引（未找到返回 -1）|

## 快速开始

### 环境要求

- 编译器：GCC 4.8+、Clang 3.4+ 或 MSVC 2015+
- 构建工具：CMake 3.28 及以上

### 编译步骤

1. 克隆项目到本地：

   ```batch
   git clone <仓库地址>
   cd <项目目录>
   ```

2. 构建项目：

   ```batch
   # 创建构建目录
   mkdir build && cd build
   
   # 生成构建文件（以 Linux 为例）
   cmake ..
   
   # 编译
   make
   ```

3. 运行示例程序：

   ```bash
   ./ArrayList  # Linux/macOS
   # 或在 Windows 下运行生成的可执行文件
   ```

### 使用示例

```c
#include <stdio.h>
#include "ArrayList.h"

int main() {
    // 创建动态数组
    PArrayList arr = newArrayList();
    if (!arr) {
        printf("数组创建失败\n");
        return 1;
    }

    // 添加元素
    Value val;
    for (int i = 0; i < 5; i++) {
        val.Integer = 10 + i;  // 存储 int 类型元素
        ArrayList_add(arr, val);
    }

    // 打印元素
    printf("数组元素：\n");
    for (int i = 0; i < ArrayList_size(arr); i++) {
        printf("索引 %d: %d\n", i, ArrayList_get(arr, i).Integer);
    }

    // 释放内存
    ArrayList_free(&arr);
    return 0;
}
```

**输出结果**：

``` plaintext
数组元素：
索引 0: 10
索引 1: 11
索引 2: 12
索引 3: 13
索引 4: 14
```

## 项目结构

``` plaintext
├── ArrayList.c       # 核心实现（动态扩容、元素操作等）
├── ArrayList.h       # 头文件（结构体定义、函数声明）
├── CMakeLists.txt    # 构建配置文件
├── main.c            # 示例代码（演示 API 使用）
├── LICENSE           # MIT 许可证
└── README.md         # 项目说明文档
```

## 注意事项

1. **内存管理**：使用完毕后必须调用 `ArrayList_free()` 释放内存，否则会导致内存泄漏。
2. **类型匹配**：调用查找函数（`firstOf`/`lastOf`）时，需指定正确的元素类型（如 `type_int`），否则会匹配失败。
3. **索引范围**：所有涉及索引的操作，需确保索引在 `[0, 元素数量-1]` 范围内，否则会触发边界检查并忽略操作。
*提醒:想针对结构体类型变量使用可以考虑使用结构体指针适配本ArrayList的指针类型存储并间接访问结构体变量*

## 许可证

本项目基于 MIT 许可证开源，详情参见 [LICENSE](LICENSE) 文件。
