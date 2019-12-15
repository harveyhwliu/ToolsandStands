## 01 高级应用话题：  
#### 1. 嵌套 Message
&emsp;&emsp;一旦拥有嵌套能力，消息的表达能力就会非常强大。嵌套实现了复杂json的特性，如下：<br/>
```Protobuf
package lm;  		//Package Name
message person 		//Message Name
{
	required string name = 1; 
	required int32 id = 2;        // Unique ID number for this person. 
 	optional string email = 3; 
 	enum PhoneType { 
   		MOBILE = 0; 
   		HOME = 1; 
   		WORK = 2; 
 	} 
 
 	message PhoneNumber { 
   		required string number = 1; 
   		optional PhoneType type = 2 [default = HOME]; 
 	} 
 	repeated PhoneNumber phone = 4; 
}
```
&emsp;&emsp;在 Message person 中，定义了嵌套消息 PhoneNumber，并用来定义 person 消息中的 phone 域。这使得人们可以定义更加复杂的数据结构。<br/>

#### 2. Import Message
&emsp;&emsp;在一个 .proto 文件中，还可以用 Import 关键字引入在其他 .proto 文件中定义的消息，这可以称做 Import Message，或者 Dependency Message。<br/>
```C++
import common.header; 
 
message youMsg{ 
 required common.info_header header = 1; 
 required string youPrivateData = 2; 
}
```
&emsp;&emsp;其中 ,common.info_header定义在common.header包内。Import Message 的用处主要在于提供了方便的代码管理机制，类似 C 语言中的头文件。您可以将一些公用的 Message 定义在一个 package 中，然后在别的 .proto 文件中引入该 package，进而使用其中的消息定义。<br/>

## 02 实战话题 - 嵌套 Message：  
&emsp;&emsp;嵌套Message的举例如下：<br/>
#### 步骤1：书写 .proto 文件
&emsp;&emsp;编写conf.proto文件，person类有属性：name,id，email和phone,其中phone是装有相同元素类型的数组，每个元素都是PhoneNumber<br/>
```ProtoBuf
package lm;  		//Package Name
message person 		//Message Name
{
	required string name = 1; 
	required int32 id = 2;        // Unique ID number for this person. 
 	optional string email = 3; 
 	enum PhoneType { 
   		MOBILE = 0; 
   		HOME = 1; 
   		WORK = 2; 
 	} 
 
 	message PhoneNumber { 
   		required string number = 1; 
   		optional PhoneType type = 2 [default = HOME]; 
 	} 
 	repeated PhoneNumber phone = 4; 
}

```

#### 步骤2：编译 .proto 文件
&emsp;&emsp;写好 proto 文件之后就可以用 Protobuf 编译器将该文件编译成目标语言了。具体的编译语句为：`protoc -I=$SRC_DIR --cpp_out=$DST_DIR $SRC_DIR/proto_name.proto` <br/>
```ProtoBuf
protoc -I=./ --cpp_out=./ ./conf.proto   #编译proto文件
#待编译的文件为conf.proto，他存放在当前目录下。--cpp_out参数则指示编译工具我们需要生成目标语言是C++，输出目录是当前目录。
#在本例中，生成的目标代码文件名是conf.pb.h和conf.pb.cc。
```
&emsp;&emsp;命令将生成两个文件：conf.pb.cc 和 conf.pb.h,分别定义了C++ 类的实现文件以及其头文件。在生成的头文件中，定义了一个 C++ 类 helloworld，后面的 Writer 和 Reader 将使用这个类来对消息进行操作。诸如对消息的成员进行赋值，将消息序列化等等都有相应的方法。<br/>

#### 步骤3：编写 writer 和 Reader
&emsp;&emsp;直接上代码：<br/>

```C++
/*
* Write： 负责把待通信的数据，写到磁盘中
*/

#include <iostream>
#include <fstream>
#include <string>
#include "conf.pb.h"
using namespace std;

int main(void){
    lm::person msg1;
    //msg1.set_name("harvey");  //这里先定义name 还是先定义id无区别(不会导致 结构化数据的序列化和反序列化的失败)
    msg1.set_id(1);
    msg1.set_name("harvey");
    msg1.set_email("2580205897@qq.com");
    
    //联系方式1   
    lm::person::PhoneNumber *phoneNumber = msg1.add_phone();    //这里和基础的不一样，看下proto编译的目标文件conf.pb.h中的定义就知道了
    phoneNumber->set_number("18888888888");
    phoneNumber->set_type(lm::person::MOBILE);                  //这里是枚举类型
    
    //联系方式2
    phoneNumber = msg1.add_phone();                             //再增加一个联系方式
    phoneNumber->set_number("88888888");
    phoneNumber->set_type(lm::person::WORK);
    
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
#include "conf.pb.h"
using namespace std;


void ListMsg(const lm::person &msg){
   cout<<msg.id()<<endl;            //取出并打印一些基础的数据
   cout<<msg.name()<<endl;
   cout<<msg.id()<<endl;
   cout<<msg.email()<<endl;
   int phone_size = msg.phone_size();   //针对Protobuf中repeated字段，需要先通过  pb对象.属性_size 来获取属性的个数(大小)
   for(int i =0;i<phone_size;i++){      //遍历所有 的 repeated 对象属性
       lm::person::PhoneNumber phone = msg.phone(i);    //取出具体的嵌套的属性对象
       cout<<phone.number()<<endl;                      //最后拿出结果来
       cout<<phone.type()<<endl;
   }
}

int main(void){
    lm::person msg1;
    fstream input("./log",ios::in | ios::binary);
    if(!msg1.ParseFromIstream(&input)){                 //反序列化
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

## 03 参考文献
[ProtoBuf Github](https://code.google.com/p/protobuf/downloads/list)<br/>
[Google Protocol Buffer 的使用和原理](https://www.ibm.com/developerworks/cn/linux/l-cn-gpb/index.html)<br/>
[Protocal Buffers](https://blog.csdn.net/ldxlz224/article/details/101022649)<br/>
