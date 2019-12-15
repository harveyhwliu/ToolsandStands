# Protobuf
## 简介
&emsp;&emsp;Google Protocol Buffer( 简称 Protobuf) 是 Google 公司内部的混合语言数据标准，他们用于 RPC 系统和持续数据存储系统。<br/>
&emsp;&emsp;Protocol Buffers 是一种轻便高效的`结构化数据存储格式，可以用于结构化数据串行化，或者说序列化`。它很适合做数据存储或 RPC 数据交换格式。可用于通讯协议、数据存储等领域的语言无关、平台无关、可扩展的序列化结构数据格式。目前提供了 C++、Java、Python 三种语言的 API。<br/>

## 01安装Protobuf
   1. 源码安装Protobuf(https://github.com/protocolbuffers/protobuf/releases)
      1. 网站 http://code.google.com/p/protobuf/downloads/list上可以下载 Protobuf 的源代码,或者是protobuf-2.5.0.tar.gz(已上传到百度云盘，地址： http://pan.baidu.com/s/1pJlZubT)<br/>
      2. 解压缩： tar -zxf protobuf-2.5.0.tar.gz
      3. 进入目录：cd protobuf-2.5.0
      4. 若希望编译成功后输出的目录为/usr/local/protobuf/ 则输入如下两条命令：
         1. ./configure --prefix=/usr/local/protobuf/   # ./configure --prefix=$INSTALL_DIR
         2. make
         3. make check
         4. make install
         5. ldconfig # refresh shared library cache.
         6. 编译成功后将export PATH=/usr/local/protobuf/bin:$PATH加入到环境变量中
         7. 安装后校验：protoc --version命令，如显示libprotoc 2.5.0则安装成功
   2. 直接安装： yum -y install  protobuf-compiler protobuf-static protobuff protobuf-devel

## 02 一个简单的例子
&emsp;&emsp;使用 Protobuf 和 C++ 开发一个十分简单的例子程序，该程序由两部分组成。第一部分被称为 Writer，负责写磁盘，第二部分叫做 Reader负责读磁盘内容，这就实现了最简单的RPC数据交互。<br/>
#### 步骤1：书写 .proto 文件
&emsp;&emsp;proto 文件，定义我们程序中需要处理的结构化数据，在 protobuf 的术语中，结构化数据被称为 Message。proto 文件非常类似 java 或者 C 语言的数据定义，如下：<br/>
```ProtoBuf
package lm;  			//Package Name
message helloworld 		//Message Name
{
	required int32  id = 1;	    //id
	required string str = 2;	//str
	optional int32  op = 3;		//optional file
}
```
&emsp;&emsp;在上例中，package 名字叫做 lm，定义了一个消息 helloworld，该消息有三个成员，类型为 int32 的 id，另一个为类型为 string 的成员 str。opt 是一个可选的成员，即消息中可以不包含该成员。<br/>
#### 步骤2：编译 .proto 文件
&emsp;&emsp;写好 proto 文件之后就可以用 Protobuf 编译器将该文件编译成目标语言了。具体的编译语句为：`protoc -I=$SRC_DIR --cpp_out=$DST_DIR $SRC_DIR/proto_name.proto` <br/>
```ProtoBuf
protoc -I=./ --cpp_out=./ ./conf.proto   #编译proto文件
```
&emsp;&emsp;命令将生成两个文件：conf.pb.cc 和 conf.pb.h,分别定义了C++ 类的实现文件以及其头文件。在生成的头文件中，定义了一个 C++ 类 helloworld，后面的 Writer 和 Reader 将使用这个类来对消息进行操作。诸如对消息的成员进行赋值，将消息序列化等等都有相应的方法。<br/>

#### 步骤3：编写 writer 和 Reader
&emsp;&emsp;如果不采用Protobuf实现的话， 需要让读写者同时了解共享内容的构成，包括分隔符等细节。<br/>
&emsp;&emsp;而采用Protobuf后，需要处理的结构化数据由 .proto 文件描述，经过上一节中的编译过程后，该数据化结构对应了一个 C++ 的类，并定义在 lm.helloworld.pb.h 中。对于本例，类名为 lm::helloworld，它提供了一系列的 get/set 函数用来修改和读取结构化数据中的数据成员，或者叫 field。<br/>
&emsp;&emsp;对于想要读取这个数据的程序来说，也只需要使用类 lm::helloworld 的相应反序列化方法来将这个字节序列重新转换会结构化数据。<br/>

```C++
/*
* Write： 负责把待通信的数据，写到磁盘中
*/

#include <iostream>
#include <fstream>
#include <string>
#include "conf.pb.h"        // 通过对conf.proto文件编译得到的C++类头文件
using namespace std;

int main(void){
    lm::helloworld msg1;    // 定义helloworld 类的对象，set_属性() 用来设置 属性 的值。SerializeToOstream 将对象序列化后写入一个 fstream 流。
    msg1.set_id(100);
    msg1.set_str("hello");

    //write into disck
    fstream output("./log", ios::out | ios::binary);
    if(!msg1.SerializeToOstream(&output)){
        cerr<<"Failed to write msg."<<endl;
        output.close();
        return -1;
    }
    output.close();
    return 0;
}


/*
* Read： 负责把待通信的数据，从磁盘中读出来
*/
#include <iostream>
#include <fstream>
#include <string>
#include "conf.pb.h"            // 通过对conf.proto文件编译得到的C++类头文件
using namespace std;


void ListMsg(const lm::helloworld &msg){    //采用 get 方法读取消息的内部信息，并进行打印输出操作。
   cout<<msg.id()<<endl;
   cout<<msg.str()<<endl;
}

int main(void){
    lm::helloworld msg1;
    fstream input("./log",ios::in | ios::binary);
    if(!msg1.ParseFromIstream(&input)){     //反序列化，生成结构化的数据：helloworld 类的对象
        cerr<<"Failed to parse pb msg."<<endl;
        input.close();
        return -1;
    }
    input.close();
    ListMsg(msg1);
    return 0;
}

```
#### 步骤4：编译运行
```shell script
#编译：
g++ -o write write.cpp conf.pb.cc  -I/usr/local/protobuf/include/ -L/usr/local/protobuf/lib/ -lprotobuf
g++ -o read read.cpp conf.pb.cc  -I/usr/local/protobuf/include/ -L/usr/local/protobuf/lib/ -lprotobuf\n

#运行
./write
./read
```
   - 常见的编译错误：<br/>
      - .proto文件转化成OC文件时：Expected "required", "optional", or "repeated"
         - 原因：因为pb2和pb3的语法不一样，pb3不用在每个参数前加required还是optional，但是pb2是必须要有该参数的。
      - fatal error: google/protobuf/stubs/common.h: No such file or directory
         - 没有找到头文件，使用g++ 的-I 参数：-I/usr/local/protobuf/include/  ,这里就是你安装的路径(上面./configure --prefix=/usr/local/protobuf/)       
      - variable 'std:ofstream' has initializer but incomplete type
         - 原因是因为没有包含fstream这个头文件。在源码中需要  #include <fstream>
      - undefined reference to google protobuf [duplicate]
         - 编译的时候，需要制定protobuf的动态库，-L/usr/local/protobuf/lib/ -lprotobuf
      
         
## 03 参考文献

[ProtoBuf Github](https://code.google.com/p/protobuf/downloads/list)<br/>
[Google Protocol Buffer 的使用和原理](https://www.ibm.com/developerworks/cn/linux/l-cn-gpb/index.html)<br/>
[Protocal Buffers](https://blog.csdn.net/ldxlz224/article/details/101022649)<br/>
