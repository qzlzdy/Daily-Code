# 1. Minecraft

- [1. Minecraft](#1-minecraft)
  - [1.1. `forge.cpp`](#11-forgecpp)
    - [1.1.1. Build](#111-build)
    - [1.1.2. Run](#112-run)
  - [1.2. `minecraft.txt`](#12-minecrafttxt)
  - [1.3. `fission.py`](#13-fissionpy)
  - [1.4. `AdvancedRocketryHelper.py`](#14-advancedrocketryhelperpy)

## 1.1. `forge.cpp`

[Minecraft](https://www.minecraft.net/) Mod [TerraFirmaCraft](https://terrafirmacraft.com/)锻造辅助计算工具。

### 1.1.1. Build

```bash
g++ forge.cpp -o forge -std=c++23 -O3 -fPIC -Wall -Wextra -Wpedantic -Werror
```

### 1.1.2. Run

```bash
./forge target
```

`target`为目标偏移值。

## 1.2. `minecraft.txt`

矿物ID及锻造公式缓存。

## 1.3. `fission.py`

[GregTech 6](https://gregtech.overminddl1.com/)核裂变反应堆计算工具。

## 1.4. `AdvancedRocketryHelper.py`

[高级火箭](http://arwiki.dmodoomsirius.me/AdvancedRocketry/1.12.2/index.html)载荷计算工具。
