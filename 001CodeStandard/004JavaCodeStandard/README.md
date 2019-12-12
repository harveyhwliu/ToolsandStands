# Java 编码规范V1.0.0  
[TOC]  
## 前言  

与其它的编程规范一样，这里所讨论的不仅仅是编码格式美不美观的问题， 同时也讨论一些约定及编码标准。这份文档主要侧重于我们所普遍遵循的规则， 对于那些不是明确强制要求的，我们尽量避免提供意见。

### 为什么要有编码规范  

编码规范对于程序员而言尤为重要，有以下几个原因：  
- 一个软件的生命周期中，80%的花费在于维护
- 几乎没有任何一个软件，在其整个生命周期中，均由最初的开发人员来维护
- 编码规范可以改善软件的可读性，可以让程序员尽快而彻底地理解新的代码
- 如果你将源码作为产品发布，就需要确任它是否被很好的打包并且清晰无误，一如你已构建的其它任何产品

### 编码规范原则  

本文档中的准则致力于最大限度达到以下原则：  
- 正确性
- 可读性
- 可维护性
- 可调试性
- 一致性
- 美观  

尽管本文档涵盖了许多基础知识，但应注意的是，没有编码规范可以为我们回答所有问题，开发人员始终需要再编写完代码后，对上述原则做出正确的判断。

### 如何使代码简洁
- 为代码写注释文档
- 将代码从逻辑上分段
- 合理的使用空行
- 遵守“30秒规则”，提高代码的可读性
- 书写较短的代码行

### 代码规范等级定义
- **可选（Optional）**：用户可参考，自行决定是否采用；  
- **推荐（Preferable）**：用户理应采用，但如有特殊情况，可以不采用；  
- **必须（Mandatory）**：用户必须采用（除非是少数非常特殊的情况，才能不采用）；

**注：** 未明确指明的则默认为 **必须（Mandatory）**

### 本文档参考  

主要参考如下文档，其余还参考公司内部KM规范，Effective Java书籍等。
- [Sun Code Conventions for the Java Programming Language](https://www.oracle.com/technetwork/java/codeconvtoc-136057.html "Sun Code Conventions for the Java Programming Language")
- [Google Java Style Guide](https://google.github.io/styleguide/javaguide.html "Google Java Style Guide")
- [OpenJDK Java Style Guidelines V6](http://cr.openjdk.java.net/~alundblad/styleguide/index-v6.html "OpenJDK Java Style Guidelines V6")
- [Alibaba-Java-Coding-Guidelines](https://alibaba.github.io/Alibaba-Java-Coding-Guidelines/ "Alibaba-Java-Coding-Guidelines")

## 源文件  
### 基础
#### 文件名   

源文件以其最顶层的类名来命名，大小写敏感，文件扩展名为.java。  
Java字节码文件，文件扩展文件.class。

#### 文件编码  

源文件编码格式为**UTF-8**。  

#### 文件长度

单个源文件最大长度**2000**行。	

#### 特殊字符  

##### 空白字符  

除了在行结束使用换行符，空格是源文件中唯一允许出现的空白字符。
1.字符串中的非空格空白字符，使用转义字符。
2.不允许行前使用tab缩进，如果使用tab缩进，必须设置1个tab为4个空格。

##### 特殊转义字符  

对于具有特殊意义转义字符(\b, \t, \n, \f, \r，", '及\)，不允许使用相应的八进制(比如\012)或Unicode(比如\u000a)转义。  
正例  
```
String content = "input your name: \n";
```  
反例  
```
String content = "input your name: \\u000a";
```

##### 非ASCII字符  

非ASCII字符，是使用实际的Unicode字符(比如μ)，还是使用等价的Unicode转义符(比如\u03bc)，取决于哪个能让代码更易于阅读和理解。
正例  
```
String content = "μtest";
String content = "\u03bctest"; // "μtest"
```
反例
```
String content = "\u03bctest"
```

> Tip: 在使用Unicode转义符或是一些实际的Unicode字符时，需要做些注释给出解释，这有助于阅读和理解。    
#### 垃圾清理

对从来没有用到的或者被注释的方法、变量、类、配置文件、动态配置属性等要坚决从系统中清理出去，避免造成过多垃圾。


### 结构  

源文件内容按顺序地包含如下信息，且每个部分之间用一个空行隔开： 
- 许可证或版权信息
- package语句
- import语句
- 类和接口声明

#### 许可证或版权信息<sup>  *推荐*  </sup> 

许可证与版权信息需放在源文件的起始位置。
例如：
```
/**
 * Tencent is pleased to support the open source community by making Tars available.
 *
 * Copyright (C) 2016 THL A29 Limited, a Tencent company. All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
 * in compliance with the License. You may obtain a copy of the License at
 *
 * https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software distributed
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
 * CONDITIONS OF ANY KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations under the License.
 */

```

#### package语句 

package语句不换行，行长度限制并不适用于package语句。	 

#### import语句   

##### import不要使用通配符 

通配符导入使得不清楚实际需要导入什么，如果具有多个通配符，也可能导致引入的新类名字冲突。

正例  
```
import java.util.Collections;
```
反例
```
import java.util.*
```

##### import不要换行 

列限制并不适用于import语句,每个import语句语句应独立成行。  

##### 顺序和间距<sup>  *推荐*  </sup>   

import语句可分为以下几组，按照这个顺序，每组由一个空行分隔：  
1.所有的静态导入独立成组
2.第三方的包。每个顶级包分别为一组，字典序。例如：com, junit, org, sun  
3.java imports  
4.javax imports

每组内不空行，组内按字典序排列。例如：
```
import static java.lang.System.out; 

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.dao.EmptyResultDataAccessException;

import java.util.Date;

import javax.annotation.Resource;
import javax.sql.DataSource;

```

#### 类、接口声明  

##### 只有一个顶级类声明

每个顶级类都在一个与它同名的源文件中。

##### 类成员顺序<sup>  *推荐*  </sup>    

类的成员顺序对易学性有很大的影响，但这也不存在唯一的通用法则。不同的类对成员的排序可能是不同的。最重要的一点，每个类应该以某种逻辑去排序它的成员，维护者应该要能解释这种排序逻辑。比如， 新的方法不能总是习惯性地添加到类的结尾，因为这样就是按时间顺序而非某种逻辑来排序的。    

类属性和类方法不要交叉放置，不同存取范围的属性或者方法也尽量不要交叉放置。推荐顺序：
- 静态成员变量
- 非静态成员变量
- 构造函数
- 方法

##### 重载方法：不应该分开 

当一个类有多个构造函数，或是多个同名方法，这些函数/方法应该按顺序出现在一起，中间不要放进其它函数/方法。


## 格式  

> 术语说明：块状结构(block-like construct)指的是一个类，方法或构造函数的主体,数组初始化中的初始值可被选择性地视为块状结构。

### 大括号  

#### 使用大括号 

所有可以使用大括号的地方，都要把大括号加上。例如大括号与if, else, for, do, while语句一起使用时，即使只有一条语句(或是空)，也应该把大括号写上。  

#### 非空块：K & R 风格 

对于非空块和块状结构，大括号遵循[Kernighan和Ritchie风格](https://en.wikipedia.org/wiki/Indentation_style#K&R_style)；
- 左大括号前不换行
- 左大括号后换行
- 右大括号前换行
- 如果右大括号是一个语句、函数体或类的终止，则右大括号后换行; 否则不换行。例如，如果右大括号后面是else或逗号，则不换行。

示例：
```
return () -> {
    while (condition()) {
        method();
    }
};

return new MyClass() {
    @Override
    public void method() {
        if (condition()) {
            try {
                something();
            } catch (ProblemException e) {
                recover();
            }
        } else if (otherCondition()) {
            somethingElse();
        } else {
            lastThing();
        }
    }
};
```


#### 空块：可以用简洁版本<sup>  *推荐*  </sup>   

一个空的块状结构里什么也不包含，大括号可以简洁地写成{}，不需要换行。如果它是一个多块语句的一部分(if/else 或 try/catch/finally) ，即使大括号内没内容，右大括号也要换行。
例如：  
```
void doNothing() {}
``` 

### 块缩进：4个空格	 

每当开始一个新的块，缩进增加4个空格（不能使用\t字符来缩进）。当块结束时，缩进返回先前的缩进级别。缩进级别适用于代码和注释。

### 一行最多一个语句 

每个语句后要换行，不能多个语句写在同一行。	

### 行长度限制<sup>  *推荐*  </sup>   

单行字符数限制不超过120个，超出需要换行。
例外：
- package和import语句；
- 不满足字符限制条件的，如java doc 中的长url等;
- 注释中需要复制使用的命令行脚本

### 长行断行

我们并没有全面，确定性的准则来决定在每一种情况下如何自动换行。很多时候，对于同一段代码会有好几种有效的自动换行方式，当一个表达式因太长等原因不适于单行放置的时候，可以根据下面的规则来进行分割：
- 第二行相对第一行缩进4个空格，从第三行开始，不再继续缩进，参考示例。 
- 运算符与下文一起换行。 
- 方法调用的点符号与下文一起换行。 
- 方法调用时，多个参数，需要换行时，在逗号后进行。 
- 在括号前不要换行，见反例。

正例：
```
StringBuffer sb = new StringBuffer();
  // 超过120个字符的情况下，换行缩进4个空格，点号和方法名称一起换行
 sb.append("zi").append("xin")...
                .append("huang")...
                .append("huang")...
                .append("huang");
```
反例：
```
StringBuffer sb = new StringBuffer();  
// 超过120个字符的情况下，不要在括号前换行  
sb.append("zi").append("xin")...append      
("huang");    
// 参数很多的方法调用可能超过120个字符，不要在逗号前换行  
method(args1, args2, args3, ... 
, argsX);
```

### 空白

#### 空行

以下情况需要使用一个空行：  
- 类中连续的成员之间：字段，构造函数，方法，嵌套类，静态初始化块，实例初始化块。  
例外：两个连续字段之间的空行是可选的，用于字段的空行主要用来对字段进行逻辑分组。  
- 在函数体内，语句的逻辑分组间使用空行，如同逻辑、不同语义、不同业务的代码之间插入一个空行分隔开来以提升可读性
- 类中的第一个成员前或最后一个成员后的空行是可选的(既不鼓励也不反对这样做，视个人喜好而定)。
- 要满足本文档中其他节的空行要求(如import语句) 

#### 行内空格

除了文字，注释和Javadoc用到单个空格，其他空格只存在以下几种场景： 
- 分隔任何保留字与紧随其后的左括号(()(如if, for catch等)；  
- 分隔任何保留字与其前面的右大括号(})(如else, catch)；
- 在任何左大括号前({)，两个例外：  
    - `@SomeAnnotation({a, b})`(不使用空格)  
    - `String[][] x = {{"foo"}}`;(大括号间没有空格) 
- 在任何二元或三元运算符的两侧。
- 泛型中的&，如：`<T extends Foo & Bar>`；
- catch中的|，如`catch (FooException | BarException e)`；
- foreach 中的冒号
- lambda表达式中的方向: `(String str) -> str.length()`；
- 在, : ;及右括号后；
- 语句后做注释，则双斜杠(//)两边都要空格；
- 类型和变量之间：`List<String> list`；
- 数组初始化中，大括号内的空格是可选的，即`new int[] {5, 6}`和`new int[] { 5, 6 }`都是可以的。

注意：这一原则不影响一行开始或者结束时的空格。只针对行内部字符之间的隔开。

#### 水平对齐<sup>  *可选*  </sup> 

**术语说明**：水平对齐指的是通过增加可变数量的空格来使某一行的字符与上一行的相应字符对齐。
 
对齐可增加代码可读性，但它为日后的维护带来问题。考虑未来某个时候，我们需要修改一堆对齐的代码中的一行。 这可能导致原本很漂亮的对齐代码变得错位。很可能它会提示你调整周围代码的空白来使这一堆代码重新水平对齐(比如程序员想保持这种水平对齐的风格)， 这就会让你做许多的无用功，增加了reviewer的工作并且可能导致更多的合并冲突。  
以下示例先展示未对齐的代码，然后是对齐的代码：
```
private int x; // this is fine
private Color color; // this too

private int   x;      // permitted, but future edits
private Color color;  // may leave it unaligned
```

结论：没有必要增加若干空格来使某一行的字符与上一行对应位置的字符对齐。


#### 用小括号来限定组<sup>  *推荐*  </sup>  
除非作者和reviewer都认为去掉小括号也不会使代码被误解，或是去掉小括号能让代码更易于阅读，否则我们不应该去掉小括号。我们没有理由假设读者能记住整个Java运算符优先级表,如：
`int value = (1 << (3 + 2)) & 7;`

### 特殊结构	

#### 枚举类

枚举常量间用逗号隔开，换行可选。  
没有方法和文档的枚举类可写成数组初始化的格式：
```
private enum Suit { CLUBS, HEARTS, SPADES, DIAMONDS }
```
由于枚举类也是一个类，因此所有适用于其它类的格式规则也适用于枚举类。

#### 变量声明

- 每次只声明一个变量,不要使用组合声明，比如`int a, b`;  
- 需要时才声明，并尽快进行初始化,不要在一个代码块的开头把局部变量一次性都声明了，而是在第一次需要使用它时才声明。 局部变量在声明时最好就进行初始化，或者声明后尽快进行初始化。

#### 数组 

数组初始化可以写成块状结构，比如，下面的写法都是OK的：
```
new int[] { 1, 2 }

new int[] {
  0, 1, 2, 3
}

new int[] {
  0,
  1,
  2,
  3
}

new int[] {
  0, 1,
  2, 3
}

```

#### switch语句<sup>  *推荐*  </sup> 

**术语说明**：switch块的大括号内是一个或多个语句组。每个语句组包含一个或多个switch标签(case FOO:或default:)，后面跟着一条或多条语句。

##### 缩进

与其它块状结构一致，switch块中的内容缩进为4个空格。每个switch标签后新起一行，再缩进4个空格，写下一条或多条语句。  

##### 继续向下执行的注释

Fall-through注释，在一个switch块内，每个语句组要么通过break, continue, return或抛出异常来终止，要么通过一条注释来说明程序将继续执行到下一个语句组， 任何能表达这个意思的注释都是OK的(典型的是用// fall through)。这个特殊的注释并不需要在最后一个语句组(一般是default)中出现。

##### default 需要存在

每个switch语句都包含一个default语句组，即使它什么代码也不包含。  

正例：
```
switch (input) {
    case 1:
    case 2:
        prepareOneOrTwo();
        // fall through
    case 3:
        handleOneTwoOrThree();
        break;
    default:
        handleLargeNumber(input);
}
```
#### 注解

- 注解紧跟在文档块后面，应用于类、方法和构造函数，注解独占一行,推荐此种格式;
    ```
    @Override
    @Nullable
    public String getNameIfPresent() { ... }
    ```
- 单个的注解可以和方法签名的第一行出现在同一行;
    ```
    @Override public int hashCode() { ... }
    ```
- 应用于字段的注解紧随文档块出现，应用于字段的多个注解允许与字段出现在同一行;
    ```
    @Partial @Mock DataLoader loader;
    ```
参数和局部变量注解没有特定规则,

#### 注释  

代码注释的基本原则：
- 注释应能使代码更加明确
- 避免注释部分的过度修饰
- 保持注释部分简单、明确
- 在编码以前就应开始写注释
- 注释应说明设计思路而不是描述代码的行为

注释与其周围的代码在同一缩进级别。  
它们可以是`/* ... */`风格，也可以是`// ...`风格。对于多行的 `/* ... */ `注释，后续行必须从`*`开始， 并且与前一行的`*`对齐。以下示例注释都是OK的。
```
/*
 * Here is a block comment.
 */


if (condition) {
    /* Handle the condition. */
    ...
}


if (foo > 1) {

    // Do a double-flip.
    ...
}
else {
    return false;          // Explain why here.
}
//if (bar > 1) {
//
//    // Do a triple-flip.
//    ...
//}
//else {
//    return false;
//}

```

#### 修饰符<sup>  *推荐*  </sup> 

类和成员的修饰符如果存在，则按Java语言规范中推荐的顺序出现。  
```
public protected private abstract static final transient volatile synchronized native strictfp
```

#### java doc 注释<sup>  *可选*  </sup> 

参见[java doc 编写规范](https://www.oracle.com/technetwork/java/javase/documentation/index-137868.html)，这里做如下要求：
-  除了第一个段落，每个段落第一个单词前都有标签`<p>`，并且它和第一个单词间没有空格;
- 标准的Javadoc标记按以下顺序出现：@param, @return, @throws, @deprecated, 前面这4种标记如果出现，描述都不能为空。 当描述无法在一行中容纳，连续行需要至少再缩进对齐；
- 对于简单明显的方法如getFoo，Javadoc是可选的。这种情况下除了写“Returns the foo”，确实也没有什么值得写了。如果一个方法重载了超类中的方法，那么Javadoc也是并非必需的；
```

 /**
  * Returns an array containing all of the elements in this queue, in
  * proper sequence; the runtime type of the returned array is that of
  * the specified array.  If the queue fits in the specified array, it
  * is returned therein.  Otherwise, a new array is allocated with the
  * runtime type of the specified array and the size of this queue.
  *
  * <p>If this queue fits in the specified array with room to spare
  * (i.e., the array has more elements than this queue), the element in
  * the array immediately following the end of the queue is set to
  * {@code null}.
  *
  * <p>Suppose {@code x} is a queue known to contain only strings.
  * The following code can be used to dump the queue into a newly
  * allocated array of {@code String}:
  *
  *  <pre> {@code String[] y = x.toArray(new String[0]);}</pre>
  *
  * Note that {@code toArray(new Object[0])} is identical in function to
  * {@code toArray()}.
  *
  * @param a the array into which the elements of the queue are to
  *          be stored, if it is big enough; otherwise, a new array of the
  *          same runtime type is allocated for this purpose
  * @return an array containing all of the elements in this queue
  * @throws ArrayStoreException if the runtime type of the specified array
  *         is not a supertype of the runtime type of every element in
  *         this queue
  * @throws NullPointerException if the specified array is null
  */
```

## 命名  

命名只能允许，字符、数字、下划线、美元符号，代码中的命名均不能以下划线或美元符号开始，也不能以下划线或美元符号结束。  
反例：
```
_name $name name_  name$ 
```

### 包名  

包名全部小写，连续的单词只是简单地连接起来，不使用下划线。

### 类名  

- 类名都以UpperCamelCase风格编写。  
- 类名通常是名词或名词短语，接口名称有时可能是形容词或形容词短语。  
- 测试类的命名以它要测试的类的名称开始，以Test结束。例如，HashTest或HashIntegrationTest。
- 抽象类推荐命名使用Abstract或Base开头
- 异常类命名使用Exception结尾  

领域模型推荐命名规约参考：
- 数据对象：xxxDO，xxx即为数据表名。
- 数据传输对象：xxxDTO，xxx为业务领域相关的名称。
- 展示对象：xxxVO，xxx一般为网页名称。
- POJO是DO/DTO/BO/VO的统称，禁止命名成xxxPOJO

###  方法名 

方法名都以lowerCamelCase风格编写,方法名通常是动词或动词短语，并能够准确表达业务语义。  

### 常量名  

常量名命名模式为CONSTANT_CASE，全部字母大写，用下划线分隔单词,力求语义表达完整清楚，不要嫌名字长;  
每个常量都是一个静态final字段，但不是所有静态final字段都是常量;

### 非常量成员变量

非常量字段名以lowerCamelCase风格编写。这些名字通常是名词或名词短语。	

### 参数名

参数名以lowerCamelCase风格编写。参数应该避免用单个字符命名。	

### 局部变量名

局部变量名以lowerCamelCase风格编写,除了临时变量和循环变量，不允许使用单字符命名,即使局部变量是final和不可改变的，也不应该把它视为常量，自然也不能用常量的规则去命名它。

### 泛型变量名

类型变量可用以下两种风格之一进行命名：
- 单个的大写字母，后面可以跟一个数字(如：E, T, X, T2)。
- 类命名方式，后面加个大写的T(如：RequestT, FooBarT)，。

## 异常处理

### 异常捕获
- Java 类库中定义的可以通过预检查方式规避的RuntimeException异常不应该通过catch 的方式来处理，比如：NullPointerException，IndexOutOfBoundsException等等。 说明：无法通过预检查的异常除外，比如，在解析字符串形式的数字时，不得不通过catch NumberFormatException来实现。
    正例：
    ```
    if (obj != null) {...} 
    ```
    反例：
    ```
    try { 
        obj.method();
    } catch (NullPointerException e) {
        doSome();
    }
    ```
- catch时请分清稳定代码和非稳定代码，稳定代码指的是无论如何不会出错的代码。对于非稳定代码的catch尽可能进行区分异常类型，再做对应的异常处理。
- finally块必须对资源对象、流对象进行关闭，有异常也要做try-catch，如果JDK7及以上，可以使用try-with-resources方式。
- 捕获异常是为了处理它，不要捕获了却什么都不处理而抛弃之，如果不想处理它，请将该异常抛给它的调用者。最外层的业务使用者，必须处理异常，将其转化为用户可以理解的内容。

### 异常规约

- 不要在finally块中使用return，finally块中的return返回后方法结束执行，不会再执行try块中的return语句。
- 异常不要用来做流程控制，条件控制，异常设计的初衷是解决程序运行中的各种意外情况，且异常的处理效率比条件判断方式要低很多。

## 日志规约 <sup>  *可选*  </sup>  

- 应用中不可直接使用日志系统（Log4j、Logback）中的API，而应依赖使用日志框架SLF4J中的API，使用门面模式的日志框架，有利于维护和各个类的日志处理方式统一。
    ```
    import org.slf4j.Logger;
    import org.slf4j.LoggerFactory;
    private static final Logger logger = LoggerFactory.getLogger(Abc.class); 
    ```
- 日志文件推荐至少保存15天，因为有些异常具备以“周”为频次发生的特点。
- 谨慎地记录日志。生产环境禁止输出debug日志；有选择地输出info日志；如果使用warn来记录刚上线时的业务行为信息，一定要注意日志输出量的问题，避免把服务器磁盘撑爆，并记得及时删除这些观察日志。大量地输出无效日志，不利于系统性能提升，也不利于快速定位错误点。记录日志时请思考：这些日志真的有人看吗？看到这条日志你能做什么？能不能给问题排查带来好处？
- 异常信息应该包括两类信息：案发现场信息和异常堆栈信息。如果不处理，那么通过关键字throws往上抛出。

## 编程实践

### 正则表达式需预编译

在使用正则表达式时，利用好其预编译功能，可以有效加快正则匹配速度。 不要在方法体内定义：Pattern pattern = Pattern.compile(规则);

### 需要 Map 的主键和取值时，应该迭代 entrySet()

需要 Map 的主键和取值时，应该迭代 entrySet()，当循环中只需要 Map 的主键时，迭代 keySet() 是正确的。但是，当需要主键和取值时，迭代 entrySet() 才是更高效的做法，比先迭代 keySet() 后再去 get 取值性能更佳。      
正例
```
Map<String, String> map = ...;
for (Map.Entry<String, String> entry : map.entrySet()) {
    String key = entry.getKey();
    String value = entry.getValue();
    ...
}
```
反例
```
Map<String, String> map = ...;
for (Map.Entry<String, String> entry : map.entrySet()) {
    String key = entry.getKey();
    String value = entry.getValue();
    ...
}
```
### 应该使用Collection.isEmpty()检测空

应该使用Collection.isEmpty()检测空，使用 Collection.size() 来检测空逻辑上没有问题，但是使用 Collection.isEmpty()使得代码更易读，并且可以获得更好的性能。任何 Collection.isEmpty() 实现的时间复杂度都是 O(1) ，但是某些 Collection.size() 实现的时间复杂度可能是 O(n) 。  
正例
```
if (collection.isEmpty()) {
    ...
}
```
反例
```
if (collection.size() == 0) {
    ...
}
```
### 字符串拼接使用 StringBuilder 

一般的字符串拼接在编译期 java 会进行优化，但是在循环中字符串拼接， java 编译期无法做到优化，所以需要使用 StringBuilder 进行替换。

正例
```
String a = "a";
String b = "b";
String c = "c";
String s = a + b + c; // 没问题，java编译器会进行优化
StringBuilder sb = new StringBuilder();
for (int i = 0; i < 10; i++) {
    sb.append(i);  // 循环中，java编译器无法进行优化，所以要手动使用StringBuilder
}
```
反例
```
String s = "";
for (int i = 0; i < 10; i++) {
    s += i;
}
```

### 长整型常量后添加大写 L

在使用长整型常量值时，后面需要添加 L ，必须是大写的 L ，不能是小写的 l ，小写 l 容易跟数字 1 混淆而造成误解。  
正例
```
long value = 1L;
long max = Math.max(1L, 5L);
```
反例
```
long value = 1l;
long max = Math.max(1L, 5);
```
### 不要使用魔法值

当你编写一段代码时，使用魔法值可能看起来很明确，但在调试时它们却不显得那么明确了。这就是为什么需要把魔法值定义为可读取常量的原因。但是，-1、0 和 1不被视为魔法值。  
正例
```
private static final int MAX_COUNT = 100;
for (int i = 0; i < MAX_COUNT; i++){
    ...
}
if (count == MAX_COUNT) {
    ...
}
```
反例
```
for (int i = 0; i < 100; i++){
    ...
}
if (a == 100) {
    ...
}
```

### 建议使用 try-with-resources 语句

Java 7 中引入了 try-with-resources 语句，该语句能保证将相关资源关闭，优于原来的 try-catch-finally 语句，并且使程序代码更安全更简洁。  
正例
```
private void handle(String fileName) {
    try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
        String line;
        while ((line = reader.readLine()) != null) {
            ...
        }
    } catch (Exception e) {
        ...
    }
}
```
反例
```
private void handle(String fileName) {
    BufferedReader reader = null;
    try {
        String line;
        reader = new BufferedReader(new FileReader(fileName));
        while ((line = reader.readLine()) != null) {
            ...
        }
    } catch (Exception e) {
        ...
    } finally {
        if (reader != null) {
            try {
                reader.close();
            } catch (IOException e) {
                ...
            }
        }
    }
}
```

### 公有静态常量应该通过类访问
虽然通过类的实例访问公有静态常量是允许的，但是容易让人它误认为每个类的实例都有一个公有静态常量。所以，公有静态常量应该直接通过类访问。  
正例
```
public class User {
    public static final String CONST_NAME = "name";
    ...
}

String nameKey = User.CONST_NAME;
```
反例
```
public class User {
    public static final String CONST_NAME = "name";
    ...
}

User user = new User();
String nameKey = user.CONST_NAME;
```

### 禁止使用构造方法 BigDecimal(double)
BigDecimal(double) 存在精度损失风险，在精确计算或值比较的场景中可能会导致业务逻辑异常。  
正例
```
BigDecimal recommend1 = new BigDecimal("0.1");
BigDecimal value = BigDecimal.valueOf(0.1D); // 0.1
```
反例
```
BigDecimal value = new BigDecimal(0.1D); // 0.100000000000000005551115...
```
### 返回空数组和空集合而不是 null

返回 null ，需要调用方强制检测 null ，否则就会抛出空指针异常。返回空数组或空集合，有效地避免了调用方因为未检测 null 而抛出空指针异常，还可以删除调用方检测 null 的语句使代码更简洁。  
正例
```
public static Result[] getResults() {
    return new Result[0];
}

public static List<Result> getResultList() {
    return Collections.emptyList();
}

public static Map<String, Result> getResultMap() {
    return Collections.emptyMap();
}

public static void main(String[] args) {
    Result[] results = getResults();
    for (Result result : results) {
        ...
    }

    List<Result> resultList = getResultList();
    for (Result result : resultList) {
        ...
    }

    Map<String, Result> resultMap = getResultMap();
    for (Map.Entry<String, Result> resultEntry : resultMap) {
        ...
    }
}


```
反例
```
public static Result[] getResults() {
    return null;
}

public static List<Result> getResultList() {
    return null;
}

public static Map<String, Result> getResultMap() {
    return null;
}

public static void main(String[] args) {
    Result[] results = getResults();
    if (results != null) {
        for (Result result : results) {
            ...
        }
    }

    List<Result> resultList = getResultList();
    if (resultList != null) {
        for (Result result : resultList) {
            ...
        }
    }

    Map<String, Result> resultMap = getResultMap();
    if (resultMap != null) {
        for (Map.Entry<String, Result> resultEntry : resultMap) {
            ...
        }
    }
}
```

### 优先使用常量或确定值来调用 equals 方法

对象的 equals 方法容易抛空指针异常，应使用常量或确定有值的对象来调用 equals 方法。当然，使用 java.util.Objects.equals() 方法是最佳实践。
正例
```
public void isFinished(OrderStatus status) {
    return OrderStatus.FINISHED.equals(status);
}

public void isFinished(OrderStatus status) {
    return Objects.equals(status, OrderStatus.FINISHED);
}
```
反例
```
public void isFinished(OrderStatus status) {
    return status.equals(OrderStatus.FINISHED); // 可能抛空指针异常
}
```
### 所有的相同类型的包装类对象之间值的比较，全部使用equals方法比较

对于Integer var = ? 在-128至127范围内的赋值，Integer对象是在IntegerCache.cache产生，会复用已有对象，这个区间内的Integer值可以直接使用==进行判断，但是这个区间之外的所有数据，都会在堆上产生，并不会复用已有对象，这是一个大坑，推荐使用equals方法进行判断。

### 高度注意Map类集合K/V能不能存储null值的情况

| 集合类            | Key          | Value        | Super       | 说明                   |
|-------------------|--------------|--------------|-------------|------------------------|
| Hashtable         | 不允许为null | 不允许为null | Dictionary  | 线程安全               |
| ConcurrentHashMap | 不允许为null | 不允许为null | AbstractMap | 锁分段技术（JDK8:CAS）  |
| TreeMap           | 不允许为null | 允许为null   | AbstractMap | 线程不安全             |
| HashMap           | 允许为null   | 允许为null   | AbstractMap | 线程不安全             |

由于HashMap的干扰，很多人认为ConcurrentHashMap是可以置入null值，而事实上，存储null值时会抛出NPE异常。