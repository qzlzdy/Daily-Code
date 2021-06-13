# RabbitMQ

[toc]

## 1 预编译安装

## 2 编译安装

### 2.1 安装AMQP-CPP

```bash
git clone git@github.com:CopernicaMarketingSoftware/AMQP-CPP.git
cd AMQP-CPP
make static
cp src/libamqpcpp.a.[version] /path/to/PluginRabbitMQ/lib/libamqpcpp.a
cp -r include/* /path/to/PluginRabbitMQ/include/
```

### 2.2 安装libevent

```bash
git clone git@github.com:libevent/libevent.git
cd libevent
mkdir build
cd build
cmake .. -DEVENT__LIBRARY_TYPE=STATIC -DCMAKE_POSITION_INDEPENDENT_CODE=ON
make
make verify
cp lib/libevent.a /path/to/PluginRabbitMQ/lib/
cp -r ../include/event2 /path/to/PluginRabbitMQ/include/event2
```

### 2.3 安装Protocol Buffer

```bash
git clone git@github.com:protocolbuffers/protobuf.git
cd protobuf
git submodule update --init --recursive
cd cmake
mkdir build
cd build
mkdir release
cd release
cmake ../.. -DCMAKE_BUILD_TYPE=Release -Dprotobuf_BUILD_SHARED_LIBS=OFF -DCMAKE_POSITION_INDEPENDENT_CODE=ON
make
make check
cp libprotobuf.a /path/to/PluginRabbitMQ/lib/
cp -r src/google /path/to/PluginRabbitMQ/include/google
```

### 2.4 使用CMake编译

```bash
cd /path/to/PluginRabbitMQ
mkdir build
cd build
cp /path/to/DolphinDB/libDolphinDB.so ./
cmake ..
make
```

## 3 用户接口

### 3.1 connectHost

#### 3.1.1 语法

```bash
connection(host, [port=5672], [username='guest'], [password='guest'], [vhost='/'])
```

####  3.1.2 参数

`host`：主机，字符串标量

`port`：端口号，数值类型，默认为`5672`

`username`：用户名，字符串标量，默认为`guest`

`password`：密码，字符串标量，默认为`guest`

`vhost`：虚拟主机，字符串标量，默认为`/`

#### 3.1.3 详情

使用给定信息连接RabbitMQ，返回表示连接的对象。

#### 3.1.4 例子

```bash
conn = rabbitmq::connection('localhost', 5672, 'guest', 'guest', '/')
```

### 3.2 connectAMQP

#### 3.2.1 语法

```bash
connectionAMQP(amqpURI)
```

#### 3.2.2 参数

`amqpURI`：AMQP协议地址，字符串标量

#### 3.2.3 详情

使用AMQP地址连接RabbitMQ，返回表示连接的对象。

#### 3.2.4 例子

```shell
conn = rabbitmq::connectionAMQP('amqp://guest:guest@localhost:5672')
```

### 3.3 channel

#### 3.3.1 语法

```bash
channel(connection)
```

#### 3.3.2 参数

`connection`：RabbitMQ连接

#### 3.3.3 详情

使用指定连接创建Channel，返回表示Channel的对象

#### 3.3.4 例子

```bash
ch = rabbitmq::channel(conn)
```

### 3.4 declareQueue

#### 3.4.1 语法

```shell
declareQueue(channel, [name], [flags])
```

#### 3.4.2 参数

`channel`：表示Channel的对象

`name`：声明的队列名，字符串标量，可选参数

`flags`：队列标志，字符串向量，可为空。支持的取值：`durable`，`autodelete`，`passive`，`exclusive`

#### 3.4.3 详情

声明队列

#### 3.4.4 例子

```bash
rabbitmq::declareQueue(ch, 'test', ['exclusive'])
```

### 3.5 publish

#### 3.5.1 语法

```bash
publish(channel, exchange, routingKey, message, [format＝'default'])
```

#### 3.5.2 参数

`channel`：表示Channel的对象

`exchange`：字符串标量

`routingKey`：字符串标量

`message`：要发送的信息

`form`：指定信息格式，字符串标量

**计划支持的form取值**

| form       | 取值              |
| ---------- | ----------------- |
| default    | DolphinDB默认格式 |
| bytestream | 字节流            |
| protobuf   | protocol buffer   |

#### 3.5.3 详情

以指定方式发布DolphinDB对象

#### 3.5.4 例子

```bash
rabbitmq::publish(ch, "", "test", "Hello World")
```

### 3.6 declareExchange

#### 3.6.1 语法

```bash
declareExchange(channel, [name], [type='fanout'], [flags])
```

#### 3.6.2 参数

`channel`：表示Channel的对象

`name`：字符串标量

`type`：字符串标量，支持的取值：`fanout`，`direct`，`topic`，`headers`，`consistent_hash`，默认为`fanout`

`flags`：字符串向量，可为空。支持的取值：`durable`，`autodelete`，`passive`，`internal`

#### 3.6.3 详情

声明Exchange

#### 3.6.4 例子

```bash
rabbitmq::declareExchange(ch, 'test-exchange', 'fanout', ['autodelete'])
```

