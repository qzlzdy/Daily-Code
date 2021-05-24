# DolphinDB ORC Plugin

[toc]

## 1 安装

> orc插件不支持windows版本

### 1.1 预编译安装

可以导入DolphinDB安装包中或者当前目录下预编译好的orc插件。

#### Linux

(1) 添加插件所在路径到LIB搜索路径 LD_LIBRARY_PATH

```bash
export LD_LIBRARY_PATH=path_to_orc_plugin/:$LD_LIBRARY_PATH
```

(2) 启动DolphinDB server并导入插件

```
loadPlugin("path_to_orc_plugin/PluginORC.txt")
```

### 1.2 编译安装

可以使用以下方法编译orc插件，编译成功后通过以上方法导入。

#### 在Linux下安装

**安装cmake：**

```bash
sudo apt-get install cmake
```

**安装cyrus-sasl：**

下载源码：https://github.com/cyrusimap/cyrus-sasl/releases/download/cyrus-sasl-2.1.27/cyrus-sasl-2.1.27.tar.gz

```bash
tar -xf cyrus-sasl-2.1.27.tar.gz
cd cyrus-sasl-2.1.27
./configure CFLAGS=-fPIC CXXFLAGS=-fPIC LDFLAGS=-static
cp ./lib/.libs/libsasl2.a path_to_orc_plugin/lib/linux
```

**安装openssl：**

使用httpClient插件中的libcrypto.a

```bash
cp DolphinDBPlugin/httpClient/lib/linux64/libcrypto.a path_to_orc_plugin/lib/linux
```

**安装orc开发包：**

下载源码：https://www.apache.org/dyn/closer.cgi/orc/orc-1.6.7/orc-1.6.7.tar.gz

```bash
tar -xf orc-1.6.7.tar.gz
cd orc-1.6.7
mkdir build
cd build
cmake .. -DBUILD_JAVA=OFF -DCMAKE_POSITION_INDEPENDENT_CODE=ON
make package
tar -xf ORC-1.6.7-Linux.tar.gz
cp ORC-1.6.7-Linux/lib/* path_to_orc_plugin/lib/linux
```

**重新编译libprotobuf.a：**

```bash
cd orc-1.6.7/build/protobuf_ep-prefix/src/
tar -xf v3.5.1.tar.gz
cd protobuf-3.5.1
./autogen.sh
cd cmake 
mkdir build
cd build
cmake .. -DCMAKE_POSITION_INDEPENDENT_CODE=ON
make
cp libprotobuf.a path_to_orc_plugin/lib/linux
```

>执行./autogen.sh后报./autogen.sh: line 50: autoreconf: command not found为正常现象，不影响接下来的步骤

**重新编译libsnappy.a：**

```bash
cd orc-1.6.7/build/snappy_ep-prefix/src/
tar -xf 1.1.7.tar.gz
cd snappy-1.17
mkdir build
cd build
cmake .. -DCMAKE_POSITION_INDEPENDENT_CODE=ON
make
cp libsnappy.a path_to_orc_plugin/lib/linux
```

**重新编译libz.a：**

```bash
cd orc-1.6.7/build/zlib_ep-prefix/src
tar -xf zlib-1.2.11.tar.gz
cd zlib-1.2.11
mkdir build
cd build
cmake .. -DCMAKE_POSITION_INDEPENDENT_CODE=ON
make
cp libz.a path_to_orc_plugin/lib/linux
```

**设置libDolphinDB.so库位置：**

```bash
export LIBDOLPHINDB=path_to_libdolphindb/
```

**编译整个项目：**

```bash
mkdir build
cd build
cmake path_to_orc_plugin/
make
```

## 2 用户接口

### 2.1 orc::extractORCSchema

#### 语法

`orc::extractORCSchema(fileName)`

#### 参数

- `fileName`: orc文件名，类型为string。

#### 详情

生成orc文件中指定数据集的结构，包括两列：列名和数据类型。

#### 例子

`orc::extractORCSchema("userdata1.orc")`

### 2.2 orc::loadORC

#### 语法

`orc::loadORC(fileName,[schema],[column],[rowStart],[rowNum])`

#### 参数

- `fileName`: orc文件名，类型为字符串标量。
- `schema`: 包含列名和列的数据类型的表。若要改变由系统自动决定的列的数据类型，需要在schema表中修改数据类型，并且把它作为`loadORC`函数的一个参数。
- `column`: 读取的列的索引。若不指定，读取所有列。
- `rowStart`: 从哪一行开始读取orc文件。若不指定，默认从文件起始位置读取。
- `rowNum`: 读取行的数量。若不指定，默认读到文件的结尾。

#### 详情

将orc文件数据加载为DolphinDB数据表的内存表。支持的数据类型，以及数据转化规则可见数据类型章节。

#### 例子

`orc::loadORC("userdata1.orc")`

>  请注意：DolphinDB中不支持下划线开头的列名。若orc文件中含有以下划线开头的列名，系统自动增加字母"Z"作为前缀。

### 2.3 orc::loadORCEx

#### 语法

`orc::loadORCEx(dbHandle,tableName,[partitionColumns],fileName,[schema],[column],[rowStart],[rowNum],[transform])`

#### 参数

- `dbHandle`与``tableName`: 若要将输入数据文件保存在分布式数据库中，需要指定数据库句柄和表名。
- `partitionColumns`: 字符串标量或向量，表示分区列。当分区数据库不是SEQ分区时，我们需要指定分区列。在组合分区中，`partitionColumns`是字符串向量。
- `fileName`: orc文件名，类型为字符串标量。
- `schema`: 包含列名和列的数据类型的表。若要改变由系统自动决定的列的数据类型，需要在schema表中修改数据类型，并且把它作为`loadORC`函数的一个参数.
- `column`: 读取的列索引。若不指定，读取所有列。
- `rowStart`: 从哪一行开始读取orc文件。若不指定，默认从文件起始位置读取。
- `rowNum`: 读取行的数量。若不指定，默认读到文件的结尾。
- `tranform`: 一元函数，并且该函数接受的参数必须是一个表。如果指定了`transform`参数，需要先创建分区表，再加载数据，程序会对数据文件中的数据执行`transform`参数指定的函数，再将得到的结果保存到数据库中。

#### 详情

将orc文件数据转换为DolphinDB数据库的分布式表，然后将表的元数据加载到内存中。支持的数据类型,以及数据转化规则可见数据类型章节。

#### 例子

```
db = database("dfs://db1", RANGE, 0 500 1000)
orc::loadORCEx(db,`tb,`id,"userdata1.orc")
```

- 指定`transform`将将数值类型表示的日期和时间(比如:20200101)转化为指定类型(比如:日期类型)

```
dbPath="dfs://db2"
db=database(dbPath,VALUE,2020.01.01..2020.01.30)
dataFilePath="userdata1.orc"
schemaTB=orc::extractORCSchema(dataFilePath)
update schemaTB set type="DATE" where name="date"
tb=table(1:0,schemaTB.name,schemaTB.type)
tb1=db.createPartitionedTable(tb,`tb1,`date);
def i2d(mutable t){
    return t.replaceColumn!(`date,datetimeParse(t.date),"yyyy.MM.dd"))
}
t = orc::loadORCEx(db,`tb1,`date,dataFilePath,datasetName,,,,i2d)
```

### 2.4 orc::orcDS

#### 语法

`orc::orcDS(fileName,chunkSize,[schema],[skipRows])`

#### 参数

- `fileName`: orc文件名，类型为字符串标量。
- `chunkSize`: 每个数据源包含的行数。
- `schema`: 包含列名和列的数据类型的表。若要改变由系统自动决定的列的数据类型，需要在schema表中修改数据类型，并且把它作为`loadORC`函数的一个参数。
- `skipRows`: 从文件头开始忽略的行数，默认值为0。

#### 详情

根据输入的文件名创建数据源列表,数量由文件中的行数与chunkSize决定。

#### 例子

```
>ds = orc::orcDS("userdata1.parquet", 1000)
>size ds;
1
>ds[0];
DataSource< loadORC("userdata1.orc", , 0, 1000) >
```

### 2.5 orc::saveORC

#### 语法

`orc::saveORC(table, fileName)`

#### 参数

- `table`: 要保存的内存表
- `fileName`: 保存的orc文件名，类型为字符串标量

#### 详情

将DolphinDB内存表保存为orc格式文件。

#### 例子

`orc::saveORC(tb, "example.orc")`

## 3 支持的数据类型

系统根据ORC的数据类型做数据的类型转换。

| Type in ORC | Type in DolphinDB |
| ----------- | ----------------- |
| boolean     | BOOL              |
| tinyint     | CHAR              |
| smallint    | SHORT             |
| int         | INT               |
| bigint      | LONG              |
| float       | FLOAT             |
| double      | DOUBLE            |
| string      | STRING            |
| char        | STRING            |
| varchar     | STRING            |
| binary      | not support       |
| timestamp   | NANOTIMESTAMP     |
| date        | DATE              |
| struct      | only top level    |
| list        | not support       |
| map         | not support       |
| union       | not support       |

