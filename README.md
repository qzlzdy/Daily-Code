- [1. ArkNights](#1-arknights)
  - [1.1. 明日方舟限定干员抽取次数概率分布](#11-明日方舟限定干员抽取次数概率分布)
    - [1.1.1. Build](#111-build)
    - [1.1.2. Run](#112-run)
  - [1.2. 干员培养计划表](#12-干员培养计划表)
- [2. DolphinDBPlugin](#2-dolphindbplugin)
- [3. HDOJ](#3-hdoj)
- [4. Minecraft](#4-minecraft)
  - [4.1. Minecraft Mod TerraFirmaCraft锻造辅助计算工具](#41-minecraft-mod-terrafirmacraft锻造辅助计算工具)
    - [4.1.1. Build](#411-build)
    - [4.1.2. Run](#412-run)
- [5. Setu](#5-setu)
  - [5.1. Build](#51-build)
  - [5.2. Usage](#52-usage)
- [6. Trackers](#6-trackers)
  - [6.1. Trackers列表同步脚本](#61-trackers列表同步脚本)
  - [6.2. Run](#62-run)

# 1. ArkNights

## 1.1. [明日方舟](https://ak.hypergryph.com/)限定干员抽取次数概率分布

### 1.1.1. Build

```bash
cd ArkNights
g++ gacha.cpp -o gacha -std=c++23 -O3 -fPIC -Wall -Wpedantic -Werror
```

### 1.1.2. Run

```bash
gacha
```

## 1.2. 干员培养计划表

自用

# 2. DolphinDBPlugin

[DolphinDB](http://dolphindb.com)实习期间工作

# 3. HDOJ

[HDOJ](https://acm.hdu.edu.cn/)OJ源代码

# 4. Minecraft

## 4.1. [Minecraft](https://www.minecraft.net/) Mod [TerraFirmaCraft](https://terrafirmacraft.com/)锻造辅助计算工具

### 4.1.1. Build

```bash
cd Minecraft
g++ forge.cpp -o forge -std=c++23 -O3 -fPIC -Wall -Wpedantic -Werror
```

### 4.1.2. Run

```bash
forge target
```

`target`为目标偏移值

# 5. Setu

[猫猫ちゃん](https://github.com/qzlzdy/Neko-Chan2.git)色图库PC端源代码

## 5.1. Build

```bash
cd Setu
mkdir build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make -j4
```

## 5.2. Usage

`dbinit`初始化色图扩展名数据库

`pretty`用于在去除冗余色图后整理色图编号填补空缺

`encode`对未编号的色图编号

# 6. Trackers

## 6.1. Trackers列表同步脚本

## 6.2. Run

```bash
merge.sh
```
