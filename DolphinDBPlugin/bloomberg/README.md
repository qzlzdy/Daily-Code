# DolphinDB Bloomberg Plugin

DolphinDB的bloomberg插件可以从服务器中读取数据并且加载到DolphinDB的内存表或者是分布式表中。

## 1 预编译安装

``` shell
loadPlugin("/path/to/bin/linux64/PluginBloomberg.txt");
```

## 2 编译安装

### 2.1 编译环境搭建

``` shell
# 对于ubuntu用户来说
sudo apt install cmake
# 对于Centos用户来说
sudo yum install cmake

# 下载BLPAPI,并解压
# 需要到BLPAPI的官网下载，此处提供一个c++api的下载链接
wget https://bloomberg.bintray.com/BLPAPI-Experimental-Generic/blpapi_cpp_3.15.0.1-linux.tar.gz
tar -xvf blpapi_cpp_3.15.0.1-linux.tar.gz
```

### 2.2 编译安装

```shell
# 编译安装
cd bkoomberg
mkdir build
cd build
cmake .. -DBLPAPI_DIR=/path/to/your/BLPAPI
make
```

### 2.3 将编译结果移动到bin/linux64文件夹中

``` shell
mv build/libPluginBloomberg.so bin/linux64
mv PluginBloomberg.txt bin/linux64
```

## 3 用户接口

### 3.1 订阅消息

#### 句法

``` shell
conn=blp::subscribe(ipaddress, port, service, appname, handler, subname, subindex )
```

#### 参数

- 'ipaddress' 是要连接的服务器的ip地址字符串
- 'port'是要连接的服务器的端口号
- 'service'是订阅的服务的名字字符串，例如"//blp/mktdata"
- 'appname‘是应用的名字
- 'handler'是一个表格或者是只接收一个输入参数的函数
- 'subname'是要订阅的商品的名字字符串向量，例如["XAG BGN Curncy"]
- 'subindex'是要订阅的商品的属性的字符串向量，例如["LAST_PRICE","TIME"]

#### 详情

通过subscribe函数能够创建一个后台订阅的线程，并返回这个线程的句柄，能够用于之后停止线程。

### 3.2 获取正在订阅数据线程的信息

#### 句法

``` shell
blp::getSubscribeStat()
```

#### 详情

将现在后台运行的所有线程的信息打印出来，包括id，用户名，ip地址及端口号，服务名称，应用名称以及线程创建的时间

### 3.3 取消订阅

#### 句法

``` shell
blp::unsubscribe(connection or connection ID)
```

#### 参数

- 'connection' ，可以使subscribe函数返回的线程句柄，可以是getSubscribeStat中查到的id，也可以是id的字符串

#### 详情

停止connection参数所对应的线程



## Appendix

``` shell
loadPlugin("/path/to/PluginBloomberg.txt");
tab =  table(100:0,`name`price`time,[STRING,FLOAT,TIME]);
conn = blp::subscribe("127.0.0.1",8194,"//blp/mktdata","DOLPHINDB:DEV",tab,["XAG BGN Curncy"],["LAST_PRICE","TIME"]);
blp::getSubscribeStat();
blp::unsubscribe(conn);
```

