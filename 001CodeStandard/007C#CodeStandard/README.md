[TOC]

 

# Unity项目C#编码规范

## 前言

Unity项目C#编码规范（以下称为 *“本规范”*）根据IEG互动娱乐事业群现有Unity项目工程实践积累经验，进行更新修订。本规范主要对C#代码的命名、可读性作出规范，以保障项目代码的易维护性和稳定性，同时也提供一定的代码实践经验条目供参考。

## 目的

为了形成IEG互动娱乐事业群统一的Unity项目C#编码风格，以保障项目代码的易维护性和稳定性，特制定本规范。

## 适用范围

本规范适用于IEG互动娱乐事业群所有使用Unity作为开发环境的软件产品，尤其是筹备期新产品，历史已运营的软件产品可作为参考。

## 总体原则

- 所有使用Unity作为开发环境的软件产品都应遵照本规范的内容进行编码。
- 各项目组可根据实际情况使用，避免写出影响客户端性能、编码效率、不符合大众习惯的代码。
- 本规范尽量以Unity已有C#代码为参考进行建立。
- 如有本规范并无提及的情况，用户也应尽量先以Unity已有C#代码为参考，并酌情合并回本规范。

## 应用说明

### 等级

本规范每条规范，按要求程度分，有以下3个等级属性：

- *可选(Optional)*：用户应该参考，自行决定是否采用；
- *推荐(Preferable)*：用户理应采用，但如有特殊情况，可以不采用；
- *必须(Mandatory)*：用户必须采用（除非是少数非常特殊的情况，才能不采用）；



### 争议部分和历史标准

部分规范存在争议，使用 *有争议(Disputable)* 的属性来表示。

C#由于源自C++，所以可能有相当部分历史C#代码借鉴了C++的代码标准。就此情况，我们设定 *历史(Obsolete)* 规范属性。具体可见**历史规范和有争议部分**一节。

### 术语

### 命名法

本规范用到以下几种命名法：

- *小驼峰式命名法(lower camel case)*：第一个单词以小写字母开始；第二个单词的首字母大写，例如：`firstName`、`lastName`。
- *大驼峰式命名法(upper camel case)*：
  每一个单词的首字母都采用大写字母，例如：`FirstName`、`LastName`。
- *大写蛇形命名法(screaming snake case)*：全大写，每个单词之间用下划线分开。例如`FIRST_NAME`、`LAST_NAME`

详可见[驼峰命名法](https://zh.wikipedia.org/wiki/%E9%A7%9D%E5%B3%B0%E5%BC%8F%E5%A4%A7%E5%B0%8F%E5%AF%AB)、[Snake case](https://en.wikipedia.org/wiki/Snake_case)。

## 一、命名规范

### 规范汇总

为便于理解，先将本规范的一些重要规范以示例形式，总结如下：

```c#
// MyComponent.cs
// 文件名和最重要的类名一致

/// <summary>
/// 类名，大驼峰式
/// </summary>
public class MyComponent : MonoBehaviour
{
    /// <summary>
    /// private/protected变量，m_开始、后接小驼峰式
    /// </summary>
    private int m_privateVar1;
    /// <summary>
    /// public属性，小驼峰式
    /// </summary>
    public int property1 { get { return m_privateVar1; } }
    /// <summary>
    /// public变量，小驼峰式
    /// </summary>
    public int publicVar2;

    /// <summary>
    /// private/protected static变量，ms_开始、后接小驼峰式
    /// </summary>
    private static int ms_privateStaticVar;

    /// <summary>
    /// public static变量，小驼峰式
    /// </summary>
    public static int publicStaticVar;

    /// <summary>
    /// 常量，大驼峰式
    /// </summary>
    public const int ConstantValue = 2;

    /// <summary>
    /// 枚举类名，大驼峰式
    /// </summary>
    public enum MyEnum
    {
        /// 枚举值，大驼峰式
        Enum1,
        Enum2
    }

    /// <summary>
    /// 函数，大驼峰式
    /// </summary>
    void HelloWorld()
    {// 大括号换行
        // 宏，大写蛇形式
        #if MY_DIRECTIVE
        // if, for, while等keyword和开括号之间有空格
        if (var1 > 0)
        {
            for (int i = 0; i < 10; ++i)
            {
                Debug.Log("Hello World");
            }
        }
        #endif
    }
}
```

### 1.1   变量名、变量类型、常量、静态变量  

所有文件、类、变量等命名都须用英文拼写。一般情况不使用汉语拼音、不使用数字命名。  
函数名、变量名、类名都必须具有描述性。  
尽量不用缩写，如用，要保证在项目之外用，别人也能知道缩写的含义。

#### 1.1.1       变量名

描述：变量命名须一目了然，与功能相符。  

级别：必须(Mandatory)  

例子：`enablePool`、`serverNum`。

#### 1.1.2       变量类型

描述：变量命名不需加类型前缀，小驼峰式命名。  

级别： 必须(Mandatory)   

例子：`count`、`passTime`、`enable`。  

#### 1.1.3       成员变量

描述：使用`m_`作为前缀，后接小驼峰变量名。  

级别：推荐(Preferable)  

例子：`int m_poolCount = 1`; 

#### 1.1.4       常量

描述：大驼峰命名。  

级别： 推荐(Preferable)  

例子：`const int PoolMaxCount = 1;`

#### 1.1.5       静态变量

描述：使用`s_`作为前缀，后接小驼峰式命名。  

级别：推荐(Preferable)    

例子：`static bool s_enablePool = false;`

### 1.2   类型命名

#### 1.2.1       类、结构体

描述：大驼峰命名，命名与功能相符，若以单独文件保存，则文件命名与类名、结构体名相同。  

级别： 必须(Mandatory)  

例子：`public class CoreEntry : MonoBehaviour {}`，同时该文件命名为CoreEntry.cs

#### 1.2.2       枚举

描述：枚举类型及其枚举值，皆为大驼峰式命名。  

级别： 必须(Mandatory)  

例子： 

```c#
public enum GameEvent
{
    BeginLoadScene = 1,
    OnAfterLoadScene,
}
```

#### 1.2.3    宏

描述：大写蛇形命名法。

级别： 必须(Mandatory)  

例子：

```c#
#if BEHAVIAC_RELEASE
    //to do
#endif
```

### 1.3   其它命名

#### 1.3.1       函数

描述：大驼峰命名，命名与功能相符。 

级别： 必须(Mandatory)  

例子：`CreateMonster()`、`ReleaseActorPool()`。

#### 1.3.2       接口

描述：以大写字母`I`（Interface）开头，后接大驼峰命名。并以相同名称实现。  

级别： 必须(Mandatory)  

例子：

```c#
public interface IComponent //声明
{
}

public class Component: IComponent //实现
{
}
```

#### 1.3.3       公共属性（Property）读/写

描述：应将实际变量私有化，并对外访问的属性采用小写驼峰命名法。对外可访问的属性不应再以`Set`/`Get`开头。  

级别： 推荐(Preferable)  

例子：

```c#
private int m_poolCount = 0;
public int poolCount 
{
    set 
    {
        m_poolCount = value;
    }
    get 
    {
        return m_poolCount;
    }
}
```

注：有争议。在C#标准中，属性采用大驼峰命名法，但在Unity实际实现中，属性采用小驼峰命名法（如[`GameObject.transform`](https://docs.unity3d.com/ScriptReference/GameObject-transform.html)、[`Renderer.isVisible`](https://docs.unity3d.com/ScriptReference/Renderer-isVisible.html)）。本规范采用Unity的实际实现。  

#### 1.3.4       文件

描述：大驼峰命名，命名与功能相符。建议和该文件中最重要的类名一致。  

级别： 必须(Mandatory)  

例子：TimeTool.cs

#### 1.3.5       命名空间

描述：命名应简单，大驼峰命名。可用简写，此时可以出现全大写情况。  

级别： 必须(Mandatory)    

例子：`namespace Tencent`、`namespace WWISE`。

#### 1.3.6       文件夹

描述：大驼峰命名。根据模块功能、分类命名，不应与系统自带文件夹命名类似或难以区分。  

级别： 必须(Mandatory)    

例子：FrameLogic、ManagerLogic、Components等。

#### 1.3.7       数组、列表、字典

描述：大驼峰命名，以Array、List、Dic结尾，命名与功能相符。  

级别：可选(Optional)  

例子：`BulletArray[]`、`AliveMonsterList`、`MapDic`。

## 二、代码规范

### 2.1   代码外观

#### 2.1.1       缩进

描述：一个Tab为4个空格。  

级别： 必须(Mandatory)      

#### 2.1.2       空行

描述：空行用于方便代码阅读，或逻辑上进行分块，以下情况建议使用空行：

1. 接口、类、枚举定义之间。
2. 函数与函数之间。
3. 函数中变量声明与使用之间。
4. 函数中不同的逻辑之间。
5. 函数中的return与其它语句之间。
6. 注释与它注释的语句间不空行，但与其它语句间需空行。  

级别： 必须(Mandatory)      

#### 2.1.3       空格

描述：以下情况建议使用空格。

1. 关键字和左括符“`(`”之间，如：`while (true)`、`if (true)`。
2. 函数名和左括符“`(`”之间不应使用空格。
3. 函数多个参数间用逗号隔开，每个逗号后应加一个空格。
4. 除`.`之外，二元操作符都用空格与操作数隔开，一元操作符、`++`及`--`不需要空格， 如：

```c#
a = a + 1;
b = a++;
```

5. 语句中表达式之间，如：

```c#
for (int i = 1; i < 10; i++)
```

级别： 必须(Mandatory)      

#### 2.1.4      文件格式

描述：代码文件必须以**UTF-8 without BOM**格式进行存储，换行方式需遵循当前工作平台的定义，这些都可以通过正确设定版本管理软件的配置以提供更好的兼容性。

级别： 必须(Mandatory)      

#### 2.1.5       花括号

描述：建议按照以下规范使用：

1. 左花括号“`{`”放于关键字或函数名的下一行并与之对齐，如：

```c#
void CreateActor ()
{
    if (true)
    {
    }
}
```

2. 左花括号要与对应的右花括号对齐，且单独成一行，不与其它语句并列在一行。
3. 函数多个参数间用逗号隔开，每个逗号后应加一个空格。
4. `if`、`while`语句后要加`{}`，即使`{}`号中只有一条语句。

级别： 必须(Mandatory)      

#### 2.1.6      注释

描述：建议按照以下规范使用：

1. 在类、接口、函数前应使用标准[C# XML文档注释格式](https://docs.microsoft.com/en-us/dotnet/csharp/codedoc)。VS中输入`///`可生成。也可补全作者、时间，如：

```c#
/// <summary>
/// ClassA的用途解释
/// </summary>
public class ClassA
{
    /// <summary>
    /// M1的用途解释
    /// </summary>
    public void M1()
    {
    }

    /// <summary>
    /// M2的用途解释
    /// </summary>
    /// <param name="i">i的解释</param>
    /// <param name="i2">i2的解释</param>
    /// <returns>返回值解释</returns>
    public int M2(int i, int i2)
    {
        return 0;
    }
}

```

2. 函数内注释使用单行注释，临时的、有争议的、待改进的代码处也需要注释：

```c#
public float GetTime()
{
    //该变量用于xxx
    int iServerNum = 0;
}

```

级别： 推荐(Preferable)

#### 2.1.7      全局命名空间

描述：禁止在全局命名空间声明类型  

级别： 必须(Mandatory)      

例子：

```c#
using System.Text;
using UnityEngine;

namespace MyNameSpace // <- 必须将ClassA声明在MyNameSpace里
{
    public class ClassA : ScriptableObject
    {
    }
}

```

#### 2.1.8       变量声明

描述：一行只做一个变量声明。 

级别： 必须(Mandatory)      

例子：

```c#
int level; 
int size; //正确

int count, total; //错误

```

#### 2.1.9       隐式类型变量

描述：变量定义时应明确类型，最好不使用var声明变量。  

级别：可选(Optional)  

例子：  

```c#
var strVar = "this is var.";

```

#### 2.1.10      路径

描述：使用Unix风格的路径，即使用`/`而非`\\`作为目录分隔符；目录路径结尾包含`/`以避免不必要的字符串拼接

级别：推荐

例子： 文件路径 `dir1/dir2/file.xml`
            目录路径 `dir1/dir2/`
            

#### 2.1.11      region的使用

描述：合理使用#region来进行代码分段与描述，提高可读性

级别：可选(Optional)

例子：  

```c#
#region 加载配置文件
#endregion

#region 根据配置加载资源
#endregion

```

## 三、代码实践

除了代码命名、代码规范外，我们也就在项目中实际编码时，所要关注的点进行讲解。

### 3.1    字符串、装箱

描述：

1. 避免字符串相加操作，优先使用`StringBuilder`实现字符串连接。
2. 避免使用`ToLower()`、`ToUpper()`来消除大小写敏感，调用次数较多时，GC内存分配较多，直接进行字符串比对即可。
3. 若必须使用`String.Format`进行连接，应显式对值类型进行`ToString()`转换，避免装箱操作。如：

```c#
Debug.LogError(String.Format("Count: {0}", count)); //值类型，有装箱
Debug.LogError(String.Format("Count: {0}", count.ToString())); //避免装箱

```



级别： 推荐(Preferable)  

### 3.2       bool条件判断

描述：应将开销较小、更易满足的条件往前放，`&&`左边条件不满足则右边判断全部跳过，`||`左边条件满足则右边判断全跳过，条件较多时，应分行书写，如

```c#
    if (enabled && null != ActorPool.GetActor(objID))
    {
        //enabled为缓存池开关，若为false，则右侧代码不会执行，提升性能
    }
    
    if (poolCount > 0 || null != ActorPool.GetActor(objID))
    {
        //poolCount 为缓存池数量，若为true，则右侧代码不会执行，提升性能
    }
    
    if (poolCount > 0 || 
        ActorPool.HasActor(objID) || 
        null != ActorPool.GetActor(objID))
    {
        //条件较多时，分行书写，便于理解
    }

```

级别： 推荐(Preferable)   

### 3.3 需cache好delegate的变量

描述：函数转为Delegate时，
每个`MyDelegate myDelegate = MyMethod;`
实际上都等于`MyDelegate myDelegate = new MyDelegate(MyMethod);`，
所以对于函数转为Delegate，如频率较高，都应cache好方法对应的Delegate。  

级别： 推荐(Preferable)    

例子：

```c#
void Awake()
{
    m_method = Method; // 一次GC Alloc
}

void Update()
{
    m_dispatcher.AddListener(MyEvent.One, m_method); // 无GC Alloc
    m_dispatcher.RemoveListener(MyEvent.One, m_method); // 无GC Alloc

    // m_dispatcher.AddListener(MyEvent.One, Method); // 每次都GC Alloc
    // m_dispatcher.RemoveListener(MyEvent.One, Method); // 每次都GC Alloc
}

void Method()
{

}

```

### 3.4 注意值类型的泛型

描述：最好避免定义新的值类型/枚举类型的泛型，而使用少数几个公用的泛型。否则，在当前版本IL2CPP，会每一个不同值类型的容器，都会额外占用对应的代码段、内存。  
引用类型的泛型无此限制。

级别： 推荐(Preferable)    

例子：

```c#
public enum MyEnum1 { One, Two }
public enum MyEnum2 { A, B }

// 为了节省代码段和内存，不要定义枚举相关的泛型容器。
// private Dictionary<MyEnum1, object> myDict1; // <- 在代码段出现一遍整个MyEnum1容器的代码
// private Dictionary<MyEnum2, object> myDict2; // <- 在代码段再出现一遍整个MyEnum2容器的代码

// 请定义成这样更可能重用的泛型容器
private Dictionary<int, object> myDict1; 
private Dictionary<int, object> myDict2;

```

### 3.5 注意struct应重写实现几个重要函数

描述：struct重写掉`Equals()`、`GetHashCode()`、`ToString()`是为防止struct的这些函数的默认实现带来的反射性能损耗，从而提高性能；  
实现`IEquatable`是为了防止调用默认`Equals(object o)`所带来的装箱，从而避免GC Alloc。

级别： 推荐(Preferable)    

例子：

```c#
public struct BaseTimerUserData : IEquatable<BaseTimerUserData>
{
    public int intParam;

    public BaseTimerUserData(int intParam)
    {
        this.intParam = intParam;
    }

    /// 如你的struct不需要比较，则直接Equals()简单返回false。
    /// 如你的struct需要比较，则Equals()需你手动比较成员变量间的比较。
    /// 这能避免默认实现的反射逻辑，从而提高效率
    public override bool Equals(object obj)
    {
        if(obj is BaseTimerUserData)
        {
            return Equals((BaseTimerUserData)obj);
        }
        else
        {
            return false;
        }
    }

    /// 实现IEquatable<>，从而防止装箱
    public bool Equals(BaseTimerUserData other)
    {
        return intParam == other.intParam;
    }

    /// 如你的struct不需放在Dictionary，则直接GetHashCode()返回0。
    /// 如你的struct需放在Dictionary，则GetHashCode()需你手动提供hash算法
    /// 这能避免默认实现的反射逻辑，从而提高效率
    public override int GetHashCode()
    {
        return 0;
    }

    /// 这能避免默认实现的反射逻辑，从而提高效率
    public override string ToString()
    {
        return intParam.ToString();
    }
}

```

### 3.6 注意泛型容器的GC Alloc

描述：`Dictionary<TKey, TValue>`的`TKey`、`List<T>`的`T`，如是没有实现`IEquatable<T>`的值类型或Enum时，必须为容器构造函数里传入Custom Comparer。否则，在查询时，这些值类型装箱会带来GC alloc。

级别： 必须(Mandatory)

例子：

```c#
//Enum未实现IEquatable接口，直接将其作为Dictionary的Key使用时会发生装箱
public enum MyEnum
{
    ME0,
    ME1,
    COUNT
}

public class MyEnumComparer : IEqualityComparer<MyEnum>
{
    public bool Equals(MyEnum x, MyEnum y)
    {
        return x == y;
    }

    public int GetHashCode(MyEnum obj)
    {
        return (int)obj;
    }

    public static MyEnumComparer Instance = new MyEnumComparer();
}

public Dictionary<MyEnum, int> enumDict = new Dictionary<MyEnum, int>(MyEnumComparer.Instance);

```

### 3.7   List元素过多时，考虑使用Dictionary存储

描述：若该List不关心排序，主要用于查询，元素过多时List查询效率明显降低，此时使用Dictionary查询效率更高。

级别： 推荐(Preferable)  



### 3.8   尽量避免使用goto语句

描述：特殊情况下，goto语句可方便的实现代码跳转，但若使用不当，会使代码结构难以理解，故应尽量避免。

级别： 推荐(Preferable)  

### 3.9  关于LINQ

描述：禁止使用LINQ，可读性较差，不易理解，GC内存分配较大。 

级别： 必须(Mandatory)  

### 3.10  成员变量初始化

描述：成员变量声明时，尽可能赋予初始值，但是要避免对实例方法的引用
            **注意：对于字符串成员变量，尽量初始化为string.Empty，避免不小心产生null reference**

级别：推荐(Preferable) 

例子：

```c#
class A
{
    MyClass a = null; //推荐
    MyClass b = new MyClass(); //推荐
    string str1 = string.Empty; //推荐
    
    MyClass c; //未赋值，不推荐
    MyClass d = MyManager.GetInstance().CreateMyClass(); //构造时引用实例函数，容易引起空引用或时序问题，不推荐
    string str2; //未赋值，不推荐
}


```

### 3.11 struct与class

描述：频繁使用的小数据类型尽量声明为struct

级别： 必须(Mandatory)    

例子：

```c#
//推荐
struct Vector3I
{
    int x;
    int y;
    int z;
}

//不推荐，频繁产生大量GC
//必须的情况下，应当使用对象池管理
class Vector3I
{
    int x;
    int y;
    int z;
}

```

### 3.12 避免Dictionary重复查询

描述：合理使用Dictionary.TryGetValue方法，避免产生两次查询

级别：推荐(Preferable)

例子：

```c#
Dictionary<int, Mesh> dic;
void Update()
{
    Mesh mesh = null;
    
    //推荐，一次性出结果
    if (dic.TryGetValue(i, out mesh)) 
    {
        //do something
    }

    //不推荐，产生了两次查询
    if (dic.ContainKey(i))
    {
        Mesh mesh = dic[i];
    }
}

```

### 3.13 避免XmlNode.Count/ChildNodes[]/Attributes的开销

描述：C#的XmlNode中，Count函数、ChildNodes[]、Attributes内部实现都是遍历，开销很大，尽可能避免不必要的多次调用

级别：推荐(Preferable)

例子：

```c#
//推荐
foreach (XmlNode childNode in rootNode.ChildNodes) {}

//不推荐
for (int i=0; i<rootNode.ChildNodes.Count; i++)
{
    XmlNode childNode = rootNode.ChindNodes[i];
}


```

### 3.14 使用XML作为配置文件时，避免将XmlNode直接缓存

描述：直接存储XmlNode会占用更多内存，可将XmlNode中需要的数据用自定义结构缓存

级别：推荐(Preferable)

例子：

```c#
//不推荐
private Dictionary<string, XmlNode> UIConfigXml = new Dictionary<string, XmlNode>(); (缓存XmlNode)

//推荐
public struct UIConfigNode
{
    public string atlas;
    public string path;
}

private Dictionary<string, UIConfigNode> UIConfigXml = new Dictionary<string, UIConfigNode>(); (仅缓存XmlNode中需要的数据)


```

**以下为Unity中的代码实践**

### 3.15       生命周期函数

描述：

1. 基本的生命周期函数要严格确保大小写、拼写正确，如：

```c#
void Awake()
{
}
    
void OnEnable() //容易漏掉On
{
}

void Start() //容易加上On
{
}

void OnDestroy() //容易写为OnDestory
{
}

```

2. 未使用的生命周期函数不要声明，尤其是`Update()`、`LateUpdate()`等高频函数，只要声明了，即便是空函数，Unity也会执行。

级别： 必须(Mandatory)

### 3.16       Update/FixedUpdate/LateUpdate函数

描述：禁止写空`Update()`函数，禁止在Update函数中进行一些明显有问题的操作。比如禁止使用`new`操作符、禁止无条件限制使用字符串拼接。 

级别： 推荐(Preferable)  

例子：

```c#
void Update()
{
    //空Update函数
}

void Update()
{
    foreach (string str in StringArray)
    {
        // Unity<=5.4版本时，foreeach会产生GC Alloc
    }
}

void Update()
{
    int[] NumArray = new int[10]; //Update中每帧New一个数组
}

void Update()
{
    Debug.LogError("PoolCount:" + poolCount); //每帧都进行字符串连接
}

void Update()
{
    MyComponent = gameObject.GetComponent<MyComponent>(); //开销很大
}

```

### 3.17 避免不合理的空引用保护

描述：不合理的空引用保护会把错误隐藏掉，将错误渗透到更叶子节点的逻辑，使得开发者将难以发现错误根本原因。另，`UnityEngine.Object`的`operator ==()`被引擎重载，执行效率事实上比`GetComponent()`更差（可参见[本文](https://blogs.unity3d.com/2014/05/16/custom-operator-should-we-keep-it/)）。  
所以应避免不合理的空引用保护。  
如有不得不进行保护的情况，则必须加上错误日志。  

级别： 必须(Mandatory)  

例子：

```c#
public class MyComponent : MonoBehaviour
{
    private Camera m_mainCam;

    void Awake()
    {
        // 假设当前上下文，m_mainCam理应合法，
        m_mainCam = Camera.main;

        // 则不建议进行“不必要”的空保护，而是直接使用
        m_mainCam.fieldOfView = 60.0f;

        // 如果真要就未知异常进行空保护，则必须加上错误日志
        if(null != m_mainCam)
        {
            m_mainCam.fieldOfView = 60.0f;
        }
        else
        {
            Debug.LogError("Main Camera异常为空");
        }
    }
}

```

### 3.18 在Unity5.4及更老版本禁止`foreach`语句

描述：Unity5.4及更老版本中存在bug，导致`foreach`会产生GC Alloc，故应禁止。  

级别： 必须(Mandatory) 

### 3.19   错误日志

描述：错误日志用来定位问题，使用的时候需要遵守以下规则：

1. 准确使用Log级别，特别注意不要把一般性的Log打印为Error及以上级别。
2. 不要输出无意义Log以及通过信息无法查找打印代码的Log。比如`"bbbbbbb"`，`"asdfgfhgh"`，或者只打印一个数字，通过数字无法查找哪里打印的Log。
3. 打印Log时需考虑输出频率，不要出现高频Log。  

级别： 推荐(Preferable)  

### 3.20   平台相关

描述：需在不同平台生效的代码，严格用宏限定，如：

```c#
#if UNITY_ANDROID
    //Android平台代码
#elif UNITY_IOS
    //iOS平台代码
#endif

```

级别： 必须(Mandatory)  

### 3.21   函数裁剪

描述：通常项目为节约内存占用，StrippingLevel会设置为Strip Byte Code，API兼容级别为.Net 2.0 subset，若要使用一些裁掉的类，需在link.xml中手动添加，如：

```xml
<linker>
    <assembly fullname="System">
        <type fullname="System.Net.HttpRequestCreator" preserve="all"/>
    </assembly>
    <assembly fullname="mscorlib">
        <namespace fullname="System.Security.Cryptography" preserve="all"/>
    </assembly>
    <assembly fullname="Mono.Security">
        <namespace fullname="Mono.Security.Protocol.Tls" preserve="all"/>
        <namespace fullname="Mono.Security.X509" preserve="all"/>
    </assembly>
    <assembly fullname="UnityEngine">
        <namespace fullname="UnityEngine" preserve="all"/>
    </assembly>  
</linker>

```

级别：推荐(Preferable)

### 3.22   插件接入

描述：禁止私自接入第三方组件。如需接入，需经项目组确认无版权问题后充分测试方可接入。

级别： 必须(Mandatory)  

### 3.23 使用协程注意GC Alloc

描述：使用协程时，尽量为`YieldInstruction`的协程对象（比如`WaitForSeconds`）进行cache。防止多次创建对象。

级别： 推荐(Preferable)  



### 3.24 避免使用`SendMessage()`

描述：如过分滥用`SendMessage()`，会造成性能降低。应该设计其他方式取代，比如接口。

级别： 推荐(Preferable)  

### 3.25   避免使用静态变量引用Unity资源

描述：使用静态变量引用的资源，若不手动解除引用则资源不会被释放，若被“遗忘”，会造成不必要的内存占用。

级别：推荐(Preferable)

例子：

```c#
private static GameObject m_goSceneObject = null;

void Start()
{
    m_goSceneObject = Resources.Load("SceneObject", typeof(GameObject)) as GameObject;
}

void OnDestroy()
{
    //未手动解除引用，导致m_goSceneObject无法被释放
}

```

### 3.26 保持属性的实现足够轻量

描述： 属性中的实现逻辑应保持轻量，即我们建议不要在属性中实现或调用复杂逻辑。如不得不执行复杂逻辑，则建议将属性改为`Set`/`Get`开头的大写驼峰式函数，以提示使用者要注意调用的消耗。

级别：推荐(Preferable)

例子：

```c#
private int m_poolCount = 0;
public void SetPoolCount() 
{
    m_poolCount = value;
    DoSomeHeavyTask(); // <- 因为需要执行比较大量的计算逻辑，所以建议将属性改为函数
}
public int GetpoolCount()
{
    return m_poolCount;
}


```

## 四、历史规范和有争议部分

C#由于源自C++，所以可能有相当部分历史C#代码借鉴了C++的代码标准。就此情况，我们设定 *历史（Obsolete）* 规范属性，并在本节进行描述。

注意，历史规范仅适用于已存在的项目。针对新项目，不应采取本节所描述的规范标准，而应采用上述新的标准。



#### 4.1.1       变量类型

描述：变量命名需加类型前缀，前缀小写，变量名首字母大写。  

注意：历史、有争议     

例子：`iCount`、`fPassTime`、`bEnable`。  

说明：类型前缀详见《变量命名前缀表》。  

#### 4.1.2       常量

要求：使用`c_`作为前缀，后面接变量类型和变量名。

注意：历史、有争议  

例子：`const int c_iPoolMaxCount = 1`;  

说明：`c_`为前缀，`i`为变量类型，`PoolMaxCount`为变量名。  

#### 4.1.3       枚举

要求：大写蛇形命名法。  

注意：历史、有争议  

例子：  

```c#
// 枚举：
public enum GameEvent
{
    BEGIN_LOAD_SCENE = 1,
    AFTER_LOAD_SCENE,
}

```

### 4.2  变量命名前缀表

根据变量的类型在变量前添加类型对应的前缀。

| **前　　缀**      | **类　　型**                                       |
| ----------------- | -------------------------------------------------- |
| `g_`              | 全局变量                                           |
| `s_`              | 静态变量                                           |
| `c_`              | 常量类型                                           |
| `b`               | `bool`                                             |
| `by`              | `byte`                                             |
| `f`               | `float`                                            |
| `d`               | `double`                                           |
| `c`               | `char`                                             |
| `i`               | `int`                                              |
| `l`               | `long`                                             |
| `str`             | `string`                                           |
| `s`               | `short`                                            |
| `u`               | 无符号整型                                         |
| `go`、`tf`        | GameObject、Transform（Unity，以首字母为简称）     |
| `lb`、`sp`、`tx`  | UILabel、UISprite、UITexture（NGUI，约定常见几种） |
| `tx`、`sp`、`img` | Text、Sprite、Image（UGUI，约定常见几种）          |

## 五、致谢

本规范是互动娱乐事业群各位技术同仁齐心共建的成果，是共同智慧的结晶，在此要对以下诸位表示诚挚的感谢：

主要起草人：blisswang(王洪福);jianweili(李建伟);alexxiong(熊智敏);donaldwu(吴东);michellwei(魏喜磊);stjzhuo(卓越);bingxiaoliu(刘冰啸);kaedeyu(郁晟);adamwang(王毅)。