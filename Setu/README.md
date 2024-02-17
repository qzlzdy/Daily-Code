# 1. Setu

[猫猫ちゃん](https://github.com/qzlzdy/Neko-Chan2.git)色图库PC端源代码

- [1. Setu](#1-setu)
  - [1.1. Build](#11-build)
  - [1.2. Usage](#12-usage)

## 1.1. Build

```bash
mkdir build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make -j4
```

## 1.2. Usage

`dbinit`初始化色图扩展名数据库

`pretty`用于在去除冗余色图后整理色图编号填补空缺

`encode`对未编号的色图编号
