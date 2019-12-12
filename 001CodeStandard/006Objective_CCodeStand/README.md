# OC语言编码规范V1.0

## 1 目的
统一公司的Objective-C编码风格，以保障公司项目代码的易维护性和编码安全性。

## 2 适用范围及推荐等级

| 规则 | 等级 |
| ---- | --- |
| [3.1 格式](#31-格式) | 必须 |
| [3.1.1 代码组织](#311-代码组织) | 必须 |
| [3.1.2 空格](#312-空格) | 必须 |
| [3.1.3 换行](#313-换行) | 必须 |
| [3.2 命名](#32-命名) | 必须 |
| [3.2.1 通用原则](#321-通用原则) | 必须 |
| [3.2.2 前缀](#322-前缀) | 必须 |
| [3.2.3 类和协议名称](#323-类和协议名称) | 必须 |
| [3.2.4 头文件](#324-头文件) | 必须 |
| [3.2.5 文件名](#325-文件名) | 必须 |
| [3.2.6 缩略词](#326-缩略词) | 推荐 |
| [3.2.7 宏定义](#327-宏定义) | 必须 |
| [3.2.8 方法名](#328-方法名) | 推荐 |
| [3.2.9 变量名](#329-变量名) | 必须 |
| [3.2.10 通知和异常](#3210-通知和异常) | 推荐 |
| [3.3 注释](#33-注释) | 推荐 |
| [3.3.1 文件注释](#331-文件注释) | 推荐 |
| [3.3.2 声明部分的注释](#332-声明部分的注释) | 推荐 |
| [3.3.3 实现部分的注释](#333-实现部分的注释) | 推荐 |
| [3.4 函数](#34-函数) | 必须 |
| [3.4.1 基本原则](#341-基本原则) | 必须 |
| [3.4.2 使用nullable及nonnull修饰参数及返回值](#342使用nullable及nonnull修饰参数及返回值) | 必须|
| [3.4.3 nil检查](#343nil检查) | 必须 |
| [3.4.4 点语法](#344-点语法) | 必须 |
| [3.4.5 使用轻量级泛型来记录容器的类型](#3.4.5-使用轻量级泛型来记录容器的类型) | 必须 |
| [3.4.6 字面量语法](#346-字面量语法) | 必须 |
| [3.4.7 异常的使用](#347-异常的使用) | 必须 |
| [3.5 控制结构](#35-控制结构) | 必须 |
| [3.5.1 分支结构](#351-分支结构) | 必须 |
| [3.5.2 BOOL陷阱](#352BOOL陷阱) | 必须 |
| [3.6 类与对象](#36-类与对象) | 必须 |
| [3.6.1 明确指定初始化方法（Designated Initializer）](#361-明确指定初始化方法designated-initializer) | 必须 |
| [3.6.2 重写指定初始化方法](#362-重写指定初始化方法) | 必须 |
| [3.6.3 初始化](#363-初始化) | 必须 |
| [3.6.4 保持公共 API 简单](#364-保持公共-api-简单) | 必须 |
| [3.7 Cocoa相关](#37-cocoa相关) | 必须 |
| [3.7.1 变量生命周期](#371-变量生命周期) | 必须 |
| [3.7.2 视图布局](#372-视图布局) | 必须 |
| [3.7.3 Cell使用](#373-Cell使用) | 必须 |
| [3.7.4 国际化](#374-国际化) | 必须 |

## 3 编码规范

### 3.1 格式

#### 3.1.1 代码组织

- 使用`#pragma mark -`将各protocol实现函数、功能相近的函数分组排放。
- 函数体长度不得超过80行。
- 函数定义前空一行。

#### 3.1.2 空格

- 函数体内代码缩进为4个空格。如果使用`TAB`制表符，请在XCode设置中明确设置`Tab Width`为4个spaces。
- 二元运算符和参数之间要有一个空格，一元运算符、强制类型转换和参数之间不放空格。
``` objc
void *ptr = &value + 10 * 3;
NewType a = (NewType)b;
for (int i = 0; i < 10; i++) {
    doCoolThings();
}
```
- 变量声明或定义：类型和`*`之间有空格，`*`和变量名之间无空格，如：`NString *example1 = @"xxx"`;
- 强制类型转换：类型和`*`之间有空格，如：`NString *a = (NSString *)b;`
- 函数返回类型：类型和`*`之间有空格，反括号`)`和函数名之间无空格，如：`- (NSString *)userName;`
- 函数名之后不要留空格,紧跟左括号`(`。
- `for、if、while`等关键字之后应留一个空格再跟左括号`(`。
- `','`后留空格。如果`';'`不是一行的结束符号，后面要留空格。
- `'{'`如果不是一行的开始，要与前面的语句间隔一个空格。
```objc
char exampleArray[] = {'a', 'b', 'c', 'd'};

if (value) {
    //...
}
```

#### 3.1.3 换行
- 一行代码不应超过150个字符，超过应该换行。
``` objc
// GOOD:
- (void)shortKeyword:(GTMFoo *)theFoo
            longerKeyword:(NSRect)theRect
    someEvenLongerKeyword:(float)theInterval
                    error:(NSError **)theError {
  ...
}

- (id<UIAdaptivePresentationControllerDelegate>)
    adaptivePresentationControllerDelegateForViewController:(UIViewController *)viewController;

- (void)presentWithAdaptivePresentationControllerDelegate:
    (id<UIAdaptivePresentationControllerDelegate>)delegate;
    
    
```

``` objc
//GOOD:
NSArray<NSString*> *sampleArray = @[@"Got some books",
                                    @"and some model objects too",
                                    @"more strings."];

NSDictionary<NSString*, NSString*> *sampleDictionary = @{@"key": @"value",
                                                         @"otherKey": @"otherValue",
                                                         @"some": @"more"};
```
- 函数体起始的大扩号后需要换行

### 3.2 命名

#### 3.2.1 通用原则

命名一定要 **名副其实**，尽可能使用有意义的名称，且和变量真实意义相关。
尽量不要出现没有任何意义的命名。

``` objc
// GOOD:
int startX = 1;
int startY = 3;
CGPoint startPoint = CGPointMake(startX, startY);
```

``` objc
// AVOID:
int a = 1;
int b = 3;
CGPoint point = CGPointMake(a, b);
```

类命名首字母大写，其他命名首字母小写，并且采用驼峰格式分割单词。例如：`QCloudTest`。

#### 3.2.2 前缀

如果代码需要打包成Framework给别的工程使用，或者工程项目非常庞大需要拆分成不同的模块，使用命名前缀是非常有用的。前缀具有规定的格式，它由两个或三个大写字母组成，不使用下划线或“子前缀”。以下是一些示例：

| 前缀 | Cocoa框架 |
| --- | --------- |
| NS | Foundation |
| NS | Application Kit |
| AB | Address Book |
| IB | Interface Builder |

#### 3.2.3 类和协议名称

类命名（包括扩展和协议命名）需要使用首字母大写，大小写混合的方式来界定不同单词。
类的名称应该包含一个名词，该名词能清楚的表明类（或类的对象）的描述或者行为。
跨应用使用的类和协议必须使用合适的前缀（例如：GTMSendMessage）。

协议名不能与类名混淆，即协议名听起来不能像类名。通用的方式是使用动名词来命名协议。例如：

| 命名 | 评论 |
| --- | ----- |
| NSLocking | 好 |
| NSLock | 不好，看上去像是一个类的名称 |

#### 3.2.4 头文件

如何命名头文件很重要。

- 声明一个独立的类或协议 : 将其声明放在一个单独的文件中，该文件的名称是声明的类或协议的名称。
  
| 头文件 | 声明 |
| ------ | ---- |
| NSLocale.h | 类`NSLocale` |

- 声明相关的类和协议，对于一组相关声明（类、类别和协议），将声明放在带有主类、类别或协议名称的文件中。

| 头文件 | 声明 |
| ----- | ---- |
| NSString.h | `NSString`和`NSMutableString`类 |
| NSLock.h | `NSLocking`协议和`NSLock`,`NSConditionLock`,`NSRecursiveLock`类 |

- Framework头文件 : 每个框架都应该有一个以该Framework命名的头文件，它包含Framework中的所有公共头文件。

| 头文件 | 框架 |
| ----- | ----- |
| Foundation.h | Foundation.framework |

- 相关功能和数据类型 : 如果有一组相关的函数、常量、结构和其他数据类型，请将他们声明在适当命名的头文件中，例如UIGraphics.h(UIKit.framework）中声明了所有`UIGrappicsComtext`相关的C函数接口。

#### 3.2.5 文件名

文件的扩展名及其意义如下：

| 扩展名 | 意义 |
| ----- | ------ |
| .h | C/C++/Objective-C的头文件 |
| .hpp | C++头文件 |
| .m | Objective-C实现文件 |
| .mm | Objective-C++实现文件 |
| .c | 纯C的实现文件 |
| .cpp | 纯C++的实现文件 |

类别的扩展名以“被扩展的类名+自定义命名部分组成”。例如NSString+Utils.h。
请使用Xcode默认根据文件名确认语言类型的功能，不要显示制定编译选项（如为.m文件制定使用objective-c++编译器），以免引起误解。

#### 3.2.6 缩略词

命名应该尽可能的清晰和简洁，但在Objective-C中，清晰比简洁更重要。由于Xcode强大的自动补全功能，我们不必担心名称过长的问题。保证只使用比较常见的词词语做缩略词，避免使用冷僻的。

好的示范：

| 缩略词 | 含义和备注 |
| ----- | ----- |
| alloc | 分配 ，拨出 |
| alt | 轮流，交替 |
| app | 应用程序。比如NSApp表示全局程序对象。 |
| calc | 计算 |
| dealloc | 销毁、析构 |
| func | 函数 |
| horiz | 水平的 |
| info | 信息 |
| init | 初始化 |
| max | 最大的 |
| min | 最小的 |
| msg | 消息 |
| nib | Interface Builder文档 |
| pboard | 粘贴板（仅对常量） |
| rect | 矩形 |
| temp | 临时、暂时 |
| vert | 垂直的 |

#### 3.2.7 宏定义

全部字母大写，例如`#define QCLOUD_DEBUG 1`。

#### 3.2.8 方法名

方法和参数名称一般以小写开头，然后使用混合大小写。

返回对象的方法以可以标识对象的名字来命名：

``` objc
// GOOD:
- (Sandwich *)sandwich;      // GOOD.
```

``` objc
// AVOID:

- (Sandwich *)makeSandwich;  // AVOID.
```

getter的名称应与它获取的对象相同，但不应附以前缀get，例如：

``` objc
// GOOD:

- (id)delegate;     // GOOD.
```

``` objc
// AVOID:

- (id)getDelegate;  // AVOID.
```

返回布尔值的getter命名应以is/can/should等开头，但属性名不应包含is/can/should。

``` objc
// GOOD:

@property(nonatomic, getter=isGlorious) BOOL glorious;
- (BOOL)isGlorious;

BOOL isGood = object.glorious;      // GOOD.
BOOL isGood = [object isGlorious];  // GOOD.
```

``` objc
// AVOID:

BOOL isGood = object.isGlorious;    // AVOID.
```

对于多个参数的方法，每个参数应都使用关键词修饰例如：
``` objc
- (void)sendAction:(SEL)aSelector toObject:(id)anObject forAllCells:(BOOL)flag;
````
而不能写成
``` objc
- (void)sendAction:(SEL)aSelector :(id)anObject :(BOOL)flag;
```

#### 3.2.9 变量与属性名

属性名首字母小写，采用驼峰命名法。

文件范围或全局变量使用g作为前缀。

``` objc
// GOOD:

static int gGlobalCounter;
```

- **成员变量名称**
  成员变量应该以下划线为前缀，例如`_usernameTextField`。


- **私有属性**
非必须公开的属性应该声明在类实现文件的延展（匿名的类目）中。
``` objc
@interface NYTAdvertisement ()
@property (nonatomic, strong) GADBannerView *googleAdView;
@property (nonatomic, strong) ADBannerView *iAdView;
@property (nonatomic, strong) UIWebView *adXWebView;
@property (nonatomic, assgin) NSInteger count;
@end
```


- **常量**
  常量（`const`全局和静态变量）应使用驼峰命名法。不要使用`#define`宏来定义常量，如果是整型常量，尽量使用const或者枚举，浮点型常量，使用`const`定义。
  全局和文件范围常量应该具有适当的前缀。

``` objc
// GOOD:

extern NSString* const kQQConstExample;
static NSString* gQQConstExample = @"";
```

``` objc
// GOOD:

extern NSString* const kQQServiceErrorDomain;
```

- **枚举与位掩码**
使用`const`定义浮点型或者单个的整数型常量，如果要定义一组相关的整数常量，应该优先使用枚举。 

枚举使用`NS_ENUM`
``` objc
typedef NS_ENUM(NSInteger, QzoneFeedType) {
    QzoneFeedTypeFriends,
    QzoneFeedTypeHomepage,
    QzoneFeedTypeBlog,
};
```

当用到位掩码时，使用 `NS_OPTIONS` 宏。
``` objc
typedef NS_OPTIONS(NSUInteger, NYTAdCategory) {
    NYTAdCategoryAutos      = 1 << 0,
    NYTAdCategoryJobs       = 1 << 1,
    NYTAdCategoryRealState  = 1 << 2,
    NYTAdCategoryTechnology = 1 << 3
};
```

#### 3.2.10 通知和异常

- **通知**
    通知由`NSString`对象标识，常量标识，其名称以这种方式组成：

    `[Name of associated class] + [Did | Will] + [UniquePartOfName] + Notification`

``` objc
// GOOD:

NSApplicationDidBecomeActiveNotification
NSWindowDidMiniaturizeNotification
NSTextViewDidChangeSelectionNotification
NSColorPanelColorDidChangeNotification
```

- **异常**
    异常名称由全局`NSString`对象标识，以这种方式组成：
    `[Prefix] + [UniquePartOfName] + Exception（每部分首字母大写）`

``` objc
// GOOD:

NSColorListIOException
NSColorListNotEditableException
NSDraggingException
NSFontUnavailableException
NSIllegalSelectorException
```

### 3.3 注释

好的注释让代码可读性更好更易维护，注意代码逻辑发生变化时需要同步修改注释。

#### 3.3.1 文件注释

文件的开始需要有如下注释：

1. 必须包含文件名，作者，创建时间，版权等信息，可以使用Xcode工程的默认模板。
2. 对文件内容的基本描述。

``` objc
// GOOD:

// QQMessageModel.h
// 消息对应的数据结构
// Created by NAME on 2019/07/30
// Copyright (c) 2019年 Tencent. All rights reserved.
//

@interface QQObj : NSObject
@end
```

**注意这里Created by后面的额名字一定要是英文名（企业微信名称），而不是开发机的当前用户名。**

#### 3.3.2 声明部分的注释

函数接口应加以注释，以描述函数功能以及其他模块，文件的关系。
属性，成员变量，协议等的声明必要时要加上注释。

``` objc
// GOOD:

/**
 * A delegate for NSApplication to handle notifications about app
 * launch and shutdown. Owned by the main app controller.
 */
@interface MyAppDelegate : NSObject {
  /**
   * The background task in progress, if any. This is initialized
   * to the value UIBackgroundTaskInvalid.
   */
  UIBackgroundTaskIdentifier _backgroundTaskID;
}

/** The factory that creates and manages fetchers for the app. */
@property(nonatomic) QQSessionFetcherService *fetcherService;

@end
```

如果已经在文件头部详细描述了接口，可以直接说明 “完整的描述请参见文件头部”。另外，对外暴露的所有接口都应该有注释来解释它的作用、参数、返回值。
对外暴露的接口应该在注释中说明线程安全性。如果类的实例可以被多个线程访问，记得注释多线程条件下的使用规则。

#### 3.3.3 实现部分的注释

重要或复杂逻辑必须加上注释。

``` objc
// GOOD:

// Set the property to nil before invoking the completion handler to
// avoid the risk of reentrancy leading to the callback being
// invoked again.
CompletionHandler handler = self.completionHandler;
self.completionHandler = nil;
handler();
```

行尾注释应与代码分开至少2个空格。

``` objc
// GOOD:

[self doSomethingWithALongName];  // Two spaces before the comment.
[self doSomethingShort];          // More spacing to align the comment.
```

### 3.4 函数与方法

#### 3.4.1 基本原则

- 函数体长度不要超过80行，小函数要比大函数可阅读性，可复用性强。

- 参数个数越少越好，多于6个参数时建议考虑重构。

- 函数的功能应在命名中体现，不能出现函数名中不包含的功能。

- 调用时参数可以在同一行，或者每行一个参数，以冒号对齐：

``` objc
// GOOD:
[myObject doFooWith:arg1
               name:arg2
              error:arg3];
```

对于参数过多的函数，建议使用每行一个参数的形式。

- 函数的边界（参数的要求、返回值的范围、是否返回为空）要在注释中写明，且在代码中明确检查，包括断言及`if`判断。

``` objc
// GOOD:
- (void)sendArgs:(NSDictionary *)args {
    NSAssert(args, @"args is nil");
}
```

#### <span id='342使用nullable及nonnull修饰参数及返回值'>3.4.2使用 `nullable` 及 `nonnull` 修饰参数及返回值</span>

接口应使用可空性注释进行修饰，以描述应该如何使用接口以及它的行为方式。

可以使用区域设置（ `NS_ASSUME_NONNULL_BEGIN` 和 `NS_ASSUME_NONNULL_END`）或可空性变量修饰符修饰参数。推荐使用 `_Nullable` 和 `_Nonnull` 关键字而不是 `__nullable` 和 `__nonnull`。

对于Objective-C方法和属性，推荐使用上下文相关的非下划线关键字，例如 `nonnull` 和 `nullable`。

``` objc
// GOOD:

/** A class representing an owned book. */
@interface GTMBook : NSObject

/** The title of the book. */
@property(readonly, copy, nonnull) NSString *title;

/** The author of the book, if one exists. */
@property(readonly, copy, nullable) NSString *author;

/** The owner of the book. Setting nil resets to the default owner. */
@property(copy, null_resettable) NSString *owner;

/** Initializes a book with a title and an optional author. */
- (nonnull instancetype)initWithTitle:(nonnull NSString *)title
                               author:(nullable NSString *)author
    NS_DESIGNATED_INITIALIZER;

/** Returns nil because a book is expected to have a title. */
- (nullable instancetype)init;

@end

/** Loads books from the file specified by the given path. */
NSArray<GTMBook *> *_Nullable GTMLoadBooksFromFile(NSString *_Nonnull path);
```

``` objc
// AVOID:
NSArray<GTMBook *> *__nullable GTMLoadBooksFromTitle(NSString *__nonnull path);

```

#### <span id="343nil检查">3.4.3 `nil` 检查</span>

避免给对象发消息前进行 `nil` 检查。对 `nil` 发送任何消息都是可以的。

``` objc
// GOOD:
[dataSource moveItemAtIndex:1 toIndex:0];  // GOOD.
```
``` objc
// AVOID:
if (dataSource) {  // AVOID.
  [dataSource moveItemAtIndex:1 toIndex:0];
}
```

#### 3.4.4 点语法

始终使用点语法来访问或者修改OC类的属性，访问其他OC方法时首选方括号方式。

```
>// GOOD:
view.backgroundColor = [UIColor orangeColor];
[UIApplication sharedApplication].delegate;

// AVOID:
[view setBackgroundColor:[UIColor orangeColor]];
UIApplication.sharedApplication.delegate;
```

#### 3.4.5 使用轻量级泛型来记录容器的类型

- 使用Xcode 7及以上版本的所有项目都应该使用Ojective-C轻量级泛型表示法来表明容器包含的对象。
``` objc
@property (nonatomic, copy) NSArray<Location *> *locations;
@property (nonatomic, copy, readonly) NSSet<NSString *> *identifiers;

NSMutableArray<Location *> *mutableLocations = [otherObject.locations mutableCopy];
```
- 如果类型比较复杂，请考虑使用typedef来保持可读性。
``` objc
typedef NSSet<NSDictionary<NSString *, NSData *>> *> TimeZoneMappingSet;
TimeZoneMappingSet *timeZoneMappings = [TimeZoneMappingSet setWithObject:...];
```
- 如果类型不确定，使用id来声明。
``` objc
@property (nonatomic, copy) NSArray<id> *unknowns;
```

#### 3.4.6 字面量语法

当创建`NSString`， `NSDictionary`，`NSArray`，和 `NSNumber` 类的不可变实例时，都应该使用字面量。要注意 `nil` 值不能传给 `NSArray` 和 `NSDictionary` 字面量，这样做会导致崩溃。

``` objc
// GOOD:
NSArray *names = @[@"Brian", @"Matt", @"Chris", @"Alex", @"Steve", @"Paul"];
NSDictionary *productManagers = @{@"iPhone" : @"Kate", @"iPad" : @"Kamal", @"Mobile Web" : @"Bill"};
NSNumber *shouldUseLiterals = @YES;
NSNumber *buildingZIPCode = @10018;
// AVOID:
NSArray *names = [NSArray arrayWithObjects:@"Brian", @"Matt", @"Chris", @"Alex", @"Steve", @"Paul", nil];
NSDictionary *productManagers = [NSDictionary dictionaryWithObjectsAndKeys: @"Kate", @"iPhone", @"Kamal", @"iPad", @"Bill", @"Mobile Web", nil];
NSNumber *shouldUseLiterals = [NSNumber numberWithBool:YES];
NSNumber *buildingZIPCode = [NSNumber numberWithInteger:10018];
```

#### 3.4.7 异常的使用

可以使用 `@try/@catch/@finally/@throw` 来进行异常处理。此外，也可以通过返回值（`nil`, `NULL`, `NO` 或者 `错误码`）或者传递一个 `NSError` 对象来返回错误。鉴于使用异常的代价较高（安装包、退堆栈带来的性能开销，此外还可能引发内存泄露），条件允许时，应该优先使用 `NSError` 对象或者返回错误码形式，但对于第三方组件的代码，在使用时，应使用 `@try/@catch` 进行异常保护。
对于后台返回的数据以及文件中读取的数据，应进行足够的校验与异常保护。包括但不限于对数据类型、长度进行校验，使用 `@try/@catch` 进行序列化，反序列化过程的保护等。

### 3.5 控制结构

#### 3.5.1 分支结构

- `if-else`结构不能超过四层。

- 条件分支中最快路径代码要放在最前面，可以有多个`return`。

``` objc
// GOOD:
- (void)someMethod {
    if (![someOther boolValue]) { 
        return;
    }
    //Do something important 
}
```

``` objc
// AVOID:
- (void)someMethod { 
    if ([someOther boolValue]) {
        //Do something important
    }
}
```

- 所有的`for`,`if`等语法结构主体都必须用花括号，即使主体代码只有一行。

```objc
// GOOD:
if (!error) {
    return success;
}
```

```objc
// AVOID:
if (!error)
    return success;
```

```objc
// AVOID:
if (!error) return success;
```

#### <span id ='352BOOL陷阱'>3.5.2 `BOOL` 陷阱</sapn>

- 将常规整数值转换为 `BOOL`，请使用三元运算符返回 `YES` 或 `NO` 值。
  对 `BOOL` 使用逻辑运算符 (`&&`, `||` 和 `!` ) 是可以的，其返回值可以安全转换为  `BOOL` ，无需三元运算符。

``` objc
// GOOD:
- (BOOL)isBold {
  return ([self fontTraits] & NSFontBoldTrait) ? YES : NO;
}

- (BOOL)isValid {
  return [self stringValue] != nil;
}

- (BOOL)isEnabled {
  return [self isValid] && [self isBold];
}
```

``` objc
// AVOID:
- (BOOL)isBold {
  return [self fontTraits] & NSFontBoldTrait;  // AVOID.
}

- (BOOL)isValid {
  return [self stringValue];  // AVOID.
}
```

- 永远不要直接将 `BOOL` 变量与 `YES` 比较，返回值可能不如你所愿。`BOOL`定义为`signed char`，因此它可能具有除 `YES` (`1`) 和 `NO` (`0`) 之外的值。也没有必要将BOOL值与NO比较，使用`if`以及`!`进行判断会使代码更为直观。

``` objc
// GOOD:
BOOL great = [foo isGreat];
if (great) {         // GOOD.
  // ...be great!
}

if (![someObject boolValue]) {
  //...
}
```

``` objc
// AVOID:
BOOL great = [foo isGreat];
if (great == YES) {  // AVOID. 永远别这么做
  // ...be great!
}

if ([someObject boolValue] == NO) { //AVOID
  
}
```

- 因为 `nil` 解析为 `NO`，没有必要在判断条件中将对象与`nil`进行比较。
```
// GOOD:
if (!someObject) {

}

// AVOID:
if (someObject == nil) {

}
```

### 3.6 类与对象

#### 3.6.1 明确指定初始化方法（Designated Initializer）

对于需要继承你的类的人来说，明确指定初始化方法十分重要。这样他们就可以只重写一个初始化方法（可能是几个）来保证他们的子类的初始化方法会被调用。这也有助于将来别人调试你的类时，理解初始化代码的工作流程。

#### 3.6.2 重写指定初始化方法

当你写子类的时候，如果需要`init..` 方法，记得重载父类的指定构造函数。如果你没有重载父类的指定构造函数，你的构造函数有时可能不会被调用，这会导致非常隐秘而且难以解决的 bug。

#### 3.6.3 初始化

1. 不要在`init`方法中，将成员变量初始化为`0`或者`nil`, 毫无必要。
2. 保持`init`函数简洁，不要让`init`函数成为千行的大函数，当超过80行的时候，需要拆分重构。

``` objc
// GOOD:
- (void)commonInit {
    _rightAppendImageView = [UIImageView new];
    [self.contentView addSubView:_rightAppendImageView];
}

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier {
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (!self) {
        return self;
    }
    [self commonInit];
    return self;
}
```

#### 3.6.4 保持公共 API 简单

保持类简单，避免 “厨房水槽（kitchen-sink）” 式的 API。如果一个函数压根没必要公开，就不要这么做。用私有类别保证公共头文件整洁。

``` objc
// GOOD:

//QQFoo.m
#import "QQFoo.h"

@interface QQFoo (PrivateDelegateHandling)
- (NSString *)doSomethingWithDelegate;  //Declare private method
@end

@implementation QQFoo (PrivateDelegateHandling)

...

- (NSString *)doSomethingWithDelegate {
    // Implement this method
}

...

@end
```

### 3.7 Cocoa相关

#### 3.7.1 变量生命周期

每个变量都有其生命周期。

1. 局部变量，建议在变量声明真的时候进行初始化，在小灰的时候将变量释放并置空
2. 实例变量，建议在对象初始化`init`的时候进行初始化，在销毁`dealloc`的时候将变量释放并置空。

#### 3.7.2 视图布局

- 避免在界面布局中使用**magic number**，应使用能够说明用途的常量。

``` objc
// AVOID:
CGFloat delta = [[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0 ? 0.0f : -14.0f;
CGSize tipsNumSize = CGSizeZero;
numFrame = CGRectMake(245 + delta,
                        (self.frame.size.height - tipsNumSize.height)/2.0,
                        tipsNumSize.width,
                        tipsNumSize.height);
```

- 建议在界面布局时适用相对布局，例如：

1. 使用目标`view`在父`view`中的相对位置
2. 使用目标`view`与相关`view`中的相对位置
3. 使用目标`view`与相邻`view`中的相对位置


- 当访问一个 `CGRect` 的 `x`，`y`， `width`， `height` 时，应该使用`CGGeometry` 函数代替直接访问结构体成员。苹果的 `CGGeometry` 参考中说到：
> All functions described in this reference that take CGRect data structures as inputs implicitly standardize those rectangles before calculating their results. For this reason, your applications should avoid directly reading and writing the data stored in the CGRect data structure. Instead, use the functions described here to manipulate rectangles and to retrieve their characteristics.

```objc
// GOOD:
CGRect frame = self.view.frame;
CGFloat x = CGRectGetMinX(frame);
CGFloat y = CGRectGetMinY(frame);
CGFloat width = CGRectGetWidth(frame);
CGFloat height = CGRectGetHeight(frame);
// AVOID:
CGRect frame = self.view.frame;
CGFloat x = frame.origin.x;
CGFloat y = frame.origin.y;
CGFloat width = frame.size.width;
CGFloat height = frame.size.height;
```

#### 3.7.3 Cell使用

使用`UITableViewCell`、`UICollectionViewCell`等具有复用逻辑的视图时，要重复考虑`Cell`被复用的情况，在适当的时机对重用的`Cell`进行清除操作。

建议使用`UITableViewCell`、`UICollectionViewCell`等实现功能的时候，优先考虑子类化。尽量避免在`delegate`中为`Cell`添加`View`。子类化更有利于`Cell`重用和对`Cell`内新添加子`View`的布局。

``` objc
// GOOD:
@interface QQSettingCell : UITableViewCell

@property (nonatomic, strong, readonly) UIImageView * rightAppendImageView;

@end

@implementation QQSettingCell

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (!self) {
        return self;
    }
    _rightAppendImageView = [UIImageView new];
    [self.contentView addSubview:_rightAppendImageView];
    return self;
}

- (void)layoutSubviews
{
    [super layoutSubviews];
    CGSize rightImageSize = _rightAppendImageView.image.size;
    _rightAppendImageView.frame = CGRectMake(CGRectGetWidth(self.frame) - rightImageSize.width,
                                             (CGRectGetHeight(self.frame) - rightImageSize.height) / 2.0,
                                             rightImageSize.width,
                                             rightImageSize.height);
}

@end
```

``` objc
// AVOID:
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString* const settingCellId = @"settingCellId";
    UITableViewCell * cell = [tableView dequeueReusableCellWithIdentifier:settingCellId];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:settingCellId];
    }
    static int gSettingCellSubViewTag = 90001;
    [cell.contentView removeAllSubViews];
    UIImageView * rightAppendingView = [UIImageView new];
    [cell.contentView addSubview:rightAppendingView];
    return cell;
}
```

#### 3.7.4 国际化

需要在 UI 上展示的字符串不能直接在代码中 hard code 中文，需要使用相应的国际化接口和 `Localizable.strings` 配置。

``` objc
// GOOD:
titleLabel.text =  NSLocalizedString(@"Q_切换摄像头",@"");
```

``` objc
// AVOID:
titleLabel.text = @"切换摄像头";
```
