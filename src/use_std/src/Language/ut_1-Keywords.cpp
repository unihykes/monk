﻿/***************************************************************************************************
LICENSE:
    Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
   
Author:liu.hao(33852613@163.com)

Time:2018-2

info:

***************************************************************************************************/

#include <mkheaders.h>
#include <gtest/gtest.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//

class ut_Keywords : public testing::Test
{
protected:
    static void SetUpTestCase(){}
    static void TearDownTestCase(){}
    virtual void SetUp(){}
    virtual void TearDown(){}
};

///C++ 关键词 C++ Keywords 
TEST_F(ut_Keywords, Keywords)
{
    /**
    标注(1):C++11 中含义改变或添加新含义。注意：关键词 export 亦为模块 TS 所用。 
    标注(2):C++17 中含义改变。 
    TM TS:实验性特性, 事务性内存技术规范 Transactional Memory Technical Specification, ISO/IEC TS 19841:2015 的一部分 (TM TS) 
    */
    #if 0
        alignas (C++11 起)          do                      reinterpret_cast
        alignof (C++11 起)          double                  register(2)
        and                         dynamic_cast            requires (C++20 起)
        and_eq                      else                    return
        asm                         enum                    short
        atomic_cancel (TM TS)       explicit                signed
        atomic_commit (TM TS)       export(1)               sizeof(1)
        atomic_noexcept (TM TS)     extern(1)               static
        auto(1)                     false                   static_assert (C++11 起)
        bitand                      float                   static_cast
        bitor                       for                     struct(1)
        bool                        friend                  switch
        break                       goto                    synchronized (TM TS)
        case                        if                      template
        catch                       import (模块 TS)        this
        char                        inline(1)               thread_local (C++11 起)
        char16_t (C++11 起)         int                     throw
        char32_t (C++11 起)         long                    true
        class(1)                    module (模块 TS)        try
        compl                       mutable(1)              typedef
        concept (C++20 起)          namespace               typeid
        const                       new                     typename
        constexpr (C++11 起)        noexcept (C++11 起)     union
        const_cast                  not                     unsigned
        continue                    not_eq                  using(1)
        co_await (协程 TS)          nullptr (C++11 起)      virtual
        co_return (协程 TS)         operator                void
        co_yield (协程 TS)          or                      volatile
        decltype (C++11 起)         or_eq                   wchar_t
        default(1)                  private                 while
        delete(1)                   protected               xor
                                    public                  xor_eq
    #endif
}


///C++ 关键词分类
TEST_F(ut_Keywords, Sort)
{
    #if 0
        ///0.去除TM TS, C++20, C++17,asm
        
        //1.常见的不解释:
        bool break case catch char const const_cast continue do double dynamic_cast else enum explicit
        false float for friend goto if int long namespace new operator private protected public
        reinterpret_cast register return short signed static static_cast switch template this throw true try
        typedef typeid typename union unsigned virtual void volatile wchar_t while
        
        ///2.替代运算符, 为了一些欧、非、拉等非英语国家保留的关键字, windows VS对此C++标准不兼容;
        and     and_eq  //用作 && 和&= 的替用 
        bitand  bitor   //用作 &  和|  的替用
        not     not_eq  //用作 !  和!= 的替用 
        or      or_eq   //用作 || 和|= 的替用
        xor     xor_eq  //作为 ^  和^= 的替用
        compl           //用作 ~       的替用 
        
        /// 3.C++11 中含义改变或添加新含义
        auto        class       default     delete          export      extern
        inline      mutable     sizeof      struct          using
        
        ///4.c++11新增
        alignas     alignof     char16_t    char32_t        constexpr
        decltype    noexcept    nullptr     static_assert   thread_local
    #endif
}


///C++11中有修改
TEST_F(ut_Keywords, auto)
{
    /**auto
    auto 自动存储期指定符 (C++11 前)
    auto 指定符 (C++11 起)
    */
    //auto int x = 10;  //C++98在此处等价于int x = 10;表示x变量为当前代码段的局部变量;
                        //C++11 起编译错误:“auto”不能与任何其他类型说明符组合
    auto lambda = [](int x) { return x + 3; };
    
    //for decltype(auto) 
    #ifdef __ENABLE_CXX14__
        auto a = 1 + 2; 
        decltype(auto) c1 = a; //C++14
    #endif
}


///C++11中有修改
TEST_F(ut_Keywords, class)
{
    /**class 
    //C++11中,可以定义有作用域枚举, 没有从有作用域枚举项到整数类型的隐式转换，尽管 static_cast 可用于获得枚举项的数值。 
    */
    enum class Color 
    {
        red, 
        green = 20, 
        blue 
    };
    Color r = Color::blue;
    // int n = r; // 错误：无有作用域枚举到 int 的转换
    int n = static_cast<int>(r); // OK, n = 21
}


///C++11中有修改
TEST_F(ut_Keywords, struct)
{
    /**struct
    有作用域枚举类型的声明 (C++11 起)
    同class
    */
    enum struct Color2
    {
        red, 
        green = 20, 
        blue 
    };
    Color2 r2 = Color2::blue;
}


///C++11中有修改
TEST_F(ut_Keywords, default)
{
    /**default
    显式默认化的函数定义：作为令编译器为类生成[特殊成员函数]的显式指令。(C++11 起) 
    特殊成员函数是仅有能被默认化的函数,即使用 = default 替代函数体定义,具体指的是以下几种:
    默认构造函数 
    复制构造函数 
    移动构造函数 (C++11 起) 
    复制赋值运算符 
    移动赋值运算符 (C++11 起) 
    析构函数 
    */
    class A
    {
    public:
        A()=default;
        A(const string& str){}
    private:
    };
    
    A aa1;
    A aa2("str");
    aa2 = aa1;
}


///C++11中有修改
TEST_F(ut_Keywords, delete)
{
    /**delete
    1.因为后随delete的一对方括号始终转译为 delete数组形式，故在delete后的拥有空捕获列表的 lambda 表达式必须用括号环绕。 
    2.表示被删除的函数,若取代函数体使用特殊语法 = delete ; 则函数定义为被删除。调用被删除函数编译错误;
    */
    //delete []{return new int; }(); // 剖析错误
    delete ([]{return new int; })(); // OK
    struct sometype
    {
        void* operator new(std::size_t) = delete;
        void* operator new[](std::size_t) = delete;
    };
    //sometype* p = new sometype; // 编译错误：尝试引用已删除的函数 sometype::operator new
}


///C++11中有修改
TEST_F(ut_Keywords, export)
{
    /**export
    1.用于标注一个模板定义被导出，这允许在其它翻译单元中声明，但不定义同一模板。(C++11 前)
        export template < parameter-list > class-declaration (C++11 前)
        export 是一个可选的修饰符，声明模板为被导出（用于类模板时，它声明所有成员为导出）。
        带有实例化被导出模板的文件不需要包含其定义：有声明就足够了。 
        export 的实现稀少而且在细节上互不一致。 
    2.不使用，并保留该关键词。(C++11 起)
    */
}


///C++11中有修改
template<class T> class ut_Keywords_Y {void mf(){}}; // 模板定义
template class ut_Keywords_Y<int>;              //显式实例化定义
template void ut_Keywords_Y<double>::mf();      //显式实例化定义
extern template class ut_Keywords_Y<string>;    //显式实例化声明
TEST_F(ut_Keywords, extern)
{
    /**extern
    显示模板实例化声明: extern template class|struct template-name < argument-list > ; (C++11 起) 
    显式实例化声明（ extern 模板）跳过隐式实例化的步骤：
        使用其他地方提供的显式实例化定义替代此外情况下产生的隐式实例化（若不存在这种实例化则产生链接错误）。
        这可用于减少编译时间，通过显式声明所有模板实例化于使用模板的源文件中，并在剩余文件中显式定义它。
    */
    //参考template<class T> class ut_Keywords_Y 模版类;
}


///C++11中有修改
namespace mk{
    namespace mk_utLanguage1
    {
        struct A
        {
            int _val;
            A():_val(10){}
        };
    }
    
    //当你需要管理多个版本的类库的时候，可以用inline修饰namespace，来达到指定默认版本的目的，
    inline namespace mk_utLanguage2
    {
        struct A
        {
            int _val;
            A():_val(23){}
        };
    }
}
namespace mk_lan1 = mk::mk_utLanguage1;//命名空间别名
namespace mk_lan2 = mk::mk_utLanguage2;//命名空间别名
TEST_F(ut_Keywords, inline)
{
    /**inline
    当你需要管理多个版本的类库的时候，可以用inline修饰namespace，来达到指定默认版本的目的，
    */
    //A a1;     //编译错误: 未声明的标识符
    mk::mk_utLanguage1::A a2;//使用mk_utLanguage1
    cout<<a2._val<<endl;
    mk::A a3;   //默认使用 mk_utLanguage2
    cout<<a3._val<<endl;
    mk::mk_utLanguage2::A a4;//显示指定 mk_utLanguage2
    cout<<a4._val<<endl;
}


///C++11中有修改
TEST_F(ut_Keywords, mutable)
{
    /**mutable
    移除以[=]捕获参数 const 限定的 lambda 声明器 (C++11 起) 
        在调用时执行 lambda 表达式体。
        访问变量时，访问其被捕获的副本（对于以复制捕获的实体）或原对象（对于以引用捕获的实体）。
        除非于 lambda 表达式使用关键词 mutable ，
        否则函数调用表达式为 const 限定，且以复制捕获的对象从此operator() 的内部不可修改。
        函数调用运算符非 volatile 限定且非虚。 
    */
    {
        int a = 1, b = 1, c = 1;
        auto m1 = [a, &b, &c]() {
            //a = 4;              //编译错误:“a”: 无法在非可变 lambda 中修改 通过复制捕获
            b = 4; c = 4;
            std::cout << "mutable testA" << a << b << c << endl;
        };
        m1();
        std::cout << "mutable testB"<<  a << b << c << endl;
    }
    {
        int a = 1, b = 1, c = 1;
        auto m1 = [a, &b, &c]() mutable {
            a = 4; 
            b = 4; c = 4;
            std::cout << "mutable testA" << a << b << c << endl;
        };
        
        m1();
        std::cout << "mutable testB"<<  a << b << c << endl;
    }
}

//for common_type_t
#ifdef __ENABLE_CXX14__
///C++11中有修改 sizeof
template<typename... Ts>
constexpr auto make_array(Ts&&... ts)-> std::array<std::common_type_t<Ts...>, sizeof...(ts)>
{
    return { std::forward<Ts>(ts)... };
}
TEST_F(ut_Keywords, sizeof)
{
    /**sizeof
    查询形式参数包中的元素数量,返回 std::size_t 类型常量 sizeof...( parameter_pack ) (C++11 起) 
    */
    auto arr = make_array(1, 2, 3);
    for (auto i : arr) {
        std::cout << i <<endl;
    }
}
#endif

///C++11中有修改 using
template<class T> using Vec = vector<T, std::allocator<T>>;//模版特化
TEST_F(ut_Keywords, using)
{
    /**using
    类型别名与别名模板声明 (C++11 起) 
    类型别名是指代先前定义类型的名称（同 typedef ）。 
    别名模版是指代一族类型的名称。别名模板是特化时等价于以别名模板实参替换 type-id 中形参的结果。 
    */
    using func = void (*) (int, int);// 类型别名，等同于 typedef void (*func)(int, int);
    Vec<int> v; // 别名模版, Vec<int> 同 vector<int, Alloc<int>>
}



///C++11中新增
TEST_F(ut_Keywords, alignas)
{
    //alignas:指定类型或对象的对齐要求。
    struct alignas(8) S {};
}


///C++11中新增
TEST_F(ut_Keywords, alignof)
{
    //alignof:查询类型的对齐要求。 
    struct S1 {};
    MK_PRINT_MSG("alignof(S1) = %d", alignof(S1));
    
    struct alignas(8) S2 {};
    MK_PRINT_MSG("alignof(S2) = %d", alignof(S2));
}


///C++11中新增
TEST_F(ut_Keywords, char16_t)
{
    char16_t x = u'A';
    MK_PRINT_MSG("x =0x%04x", x);
}


///C++11中新增
TEST_F(ut_Keywords, char32_t)
{
    char32_t x = u'A';
    MK_PRINT_MSG("x =0x%08x", x);
}

///C++11中新增 constexpr
constexpr int factorial(int n) 
{
    //阶乘:n*(n-1)*(n-2)*...
    return n <= 1? 1 : (n * factorial(n - 1)); 
}
TEST_F(ut_Keywords, constexpr)
{
    /**constexpr 
    const expression的简写,常量表达式,
    constexpr 指定符声明可以在编译时求得函数或变量的值。
    然后这些变量和函数（若给定了合适的函数参数）可用于仅允许编译时常量表达式之处。
    */
    cout<<factorial(4)<<endl; // 在编译时计算:4*3*2*1
}


///C++11中新增
TEST_F(ut_Keywords, decltype)
{
    struct A { double x; };
    const A* a = new A();
    MK_PRINT_MSG("a = %p", a);
    
    /**检查实体的声明类型或表达式的类型及值分类。
    若参数为无括号的 id 表达式或无括号的类成员访问表达式，则 decltype 产生以此表达式命名的实体的类型。
    若对象名称被括号括着，则它被当做通常的左值表达式，从而 decltype(x) 和 decltype((x)) 通常是不同的类型。 
    decltype 在声明难以或不可能以标准记号声明的类型时适用，例如 lambda 相关类型或依赖于模板形参的类型。 
    */
    decltype(a->x) y;       // y 的类型是 double （声明类型）
    decltype((a->x)) z = y; // z 的类型是 const double& （左值表达式）
    
    auto f = [](int a, int b) -> int{return a * b;};
    decltype(f) g = f; // lambda 的类型是独有且无名的
    int i = f(2, 2);
    int j = g(3, 3);
    MK_PRINT_MSG("i =%d, j = %d", i, j);
}


///C++11中新增
void ut_Keywords_f0();
void ut_Keywords_f1() noexcept; // 函数 f1() 不抛出
void ut_Keywords_f2() noexcept(true);//等价于f1
void ut_Keywords_f3() noexcept(false);//函数可能抛出异常
TEST_F(ut_Keywords, noexcept)
{
    /**
    noexcept 运算符:noexcept 运算符进行编译时检查，若表达式声明为不抛出任何异常则返回 true 。
                    noexcept 运算符不对 expression 求值。
    noexcept 指定符:指定函数是否抛出异常。 
    */
    cout<< noexcept(ut_Keywords_f0()) <<endl;
    cout<< noexcept(ut_Keywords_f1()) <<endl;
    cout<< noexcept(ut_Keywords_f2()) <<endl;
    cout<< noexcept(ut_Keywords_f3()) <<endl;
    
}


///C++11中新增
template<class F, class A> 
void Fwd(F f, A a){f(a);}

void g(int* i){std::cout << "Function g called\n";}
TEST_F(ut_Keywords, nullptr)
{
    /**关键词 nullptr 指代指针字面量。
    它是 std::nullptr_t 类型的纯右值。
    存在从 nullptr 到任何指针类型及任何指向成员指针类型的隐式转换。
    同样的转换对于任何空指针常量，空指针常量包含 std::nullptr_t 的值，还有宏 NULL 。 
    */
    g(NULL);           // 良好
    g(0);              // 良好
    Fwd(g, nullptr);   // 良好
    //Fwd(g, NULL);    // 错误：不存在函数 g(int)
}


///C++11中新增
//#include <type_traits>
template <class T>
struct ut_Keywords_D
{
    //强制要求T提供默认构造
    static_assert(std::is_default_constructible<T>::value,"ut_Keywords_D requires default-constructible");
    void show(){MK_PRINT_MSG("test static_assert");}
};
 
struct ut_Keywords_str
{
    ut_Keywords_str() = delete;//删除默认构造函数
};
TEST_F(ut_Keywords, static_assert)
{
    /**
    进行编译时断言检查。 
    static_assert ( bool_constexpr , message )
        :bool_constexpr 按照语境转换成 bool 类型的表达式 
        :message 若 bool_constexpr 为 false 则会出现的字符串字面量 
        若 bool_constexpr 返回 true ，则此声明没有效果,否则发布一个编译时错误
    */
    ut_Keywords_D<int> val_1;
    val_1.show();
    //ut_Keywords_D<ut_Keywords_str> val_2; // 编译错误
}


///C++11中新增
#include <thread>
thread_local unsigned int ut_Keywords_global = 0;
static thread_local unsigned int ut_Keywords_global_static = 10;
class ut_Keywords_X
{
public:
    //thread_local int _val;//编译错误: thread_local 仅对命名空间和块范围内的静态成员和变量有效
    static thread_local int _val_static; //A thread-local static class data member
};
thread_local int ut_Keywords_X::_val_static = 100;

void ut_Keywords_fun()
{
    //全局
    ++ut_Keywords_global;
    cout<<"global = " << ut_Keywords_global <<endl;
    
    //全局+static
    ++ut_Keywords_global_static;
    cout<<"global_static = " << ut_Keywords_global_static <<endl;
    
    //类成员变量,
    //编译错误,类的非static成员变量不能是thread_local
    //ut_Keywords_X x;
    //++x._val;
    //cout<<"cls_val = " << x._val <<endl;
    
    //类static成员变量
    ++ut_Keywords_X::_val_static;
     cout<<"cls_val_static = " << ut_Keywords_X::_val_static <<endl;
    
    //函数内部局部变量
    thread_local int local = 1000;  //A thread-local local variable
    local++;
    cout << "fun_local = "<<local <<endl<<endl;
}

TEST_F(ut_Keywords, thread_local)
{
    /**thread_local 线程局部变量
    线程局域存储期指定符 (C++11 起) 
    thread_local 关键词只对声明于命名空间作用域的对象、声明于块作用域的对象及静态数据成员允许。
    它指示对象拥有线程存储期。
    
    它能与 static 或 extern 结合，以分别指定内部或外部链接（除了静态数据成员始终拥有外部链接），
    但附加的 static 不影响存储期。
    
    对象在线程开始时分配，而在线程结束时解分配。每个线程拥有其自身的对象实例。
    唯有声明为 thread_local 的对象拥有此存储期。 
    thread_local 能与 static 或 extern 一同出现，以调整链接。 
    
    声明为thread_local的本地变量在线程中是持续存在的，
    不同于普通临时变量的生命周期，它具有static变量一样的初始化特征和生命周期，虽然它并没有被声明为static。
    */
    
    ut_Keywords_fun();//global = 1, global_static = 11, cls_val_static = 101, fun_local = 1001
    ut_Keywords_fun();//global = 2, global_static = 12, cls_val_static = 102, fun_local = 1002
    ut_Keywords_fun();//global = 3, global_static = 13, cls_val_static = 103, fun_local = 1003
    
    std::thread t1(ut_Keywords_fun);
    t1.join(); //global = 1, global_static = 11, cls_val_static = 101, fun_local = 1001
    std::thread t2(ut_Keywords_fun);
    t2.join();//global = 1, global_static = 11, cls_val_static = 101, fun_local = 1001
    std::thread t3(ut_Keywords_fun);
    t3.join();//global = 1, global_static = 11, cls_val_static = 101, fun_local = 1001
}


///C++98不常用关键字
TEST_F(ut_Keywords, volatile)
{
    /**volatile
    防止优化编译器把变量从内存装入CPU寄存器中
    volatile的意思是让编译器每次操作该变量时一定要从内存中真正取出，而不是使用已经存在寄存器中的值
    */
    volatile int i = 0x10;
    int a = i;
    MK_PRINT_MSG("i = %d", a);
    //do something
    int b = i;
    MK_PRINT_MSG("i = %d", b);
    
    //这个语句用来测试空循环的速度的, 但是编译器肯定要把它优化掉，根本就不执行
    for ( int i=0; i<100000; i++); 
    //如果添加volatile,它就会执行了
    for ( volatile int i=0; i<100000; i++); 
}




