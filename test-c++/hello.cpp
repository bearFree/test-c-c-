#include <iostream>
#include <string.h>
#include <time.h>
#include <fstream>
#include <cmath>
#include <iomanip>


/**
 * 无论读写都要包含<fstream>头文件
 */
using namespace std;
using std::setw;

char buf[1024];


#define WIDTH 2
#define HEIGHT 3

void savefile()
{
    ofstream out("/Users/sunny/Desktop/Algorithm/test-c++/abc.txt");
    out << 3 << '\t' << "abc" << endl;
    out.close( );
}

string message;
void readfile()
{
    ifstream infile;
    infile.open("wifi_yellow4.png", ios::binary);
    
    if (infile.is_open()) {
        
//        ofstream out("/Users/sunny/Desktop/Algorithm/test-c++/abc.txt");
//        out << 3 << '\t' << "abc" << endl;
//        out.close( );
        
        ofstream out("save_image.png",ios::binary);
        filebuf* pbuf = infile.rdbuf();
        out << pbuf;
        
        cout<<"品牌："<<"brand"<<endl;
        
        out.close();
    }

    infile.close();
    
}

/* c++ 类 关键字：class
 * public:    公开  通过 .运算符访问
 * private：  私有
 * protected: 保护 子类可以访问
 * 成员和类的默认访问修饰符是 private。
 * 类继承的方式：public，private，protected
 *
 * 友元 函数， frient 关键字
 * 使用场景：类之间的数据共享：允许其他类的函数访问类的私有变量和保护变量
 * 优点：提高速率，表达简单  缺点：破坏封装机制，应减少使用
 * 可以访问类的所有成员。需要在类内部定义。友元函数不是成员函数
 * 友元可以使一个函数 -- 友元函数，也可以是一个类 -- 友元类
 *
 * 内联函数 inline 关键字 // 需放置在 函数定义之前而非函数声明
 * 使用场景：写在头文件中，在每个调用点上“内联地”展开。旨在替换函数调用的开销，提高速率
 * C++ 不建议使用宏， “用函数内联取代宏” 宏：预处理器在进行宏代码替换会产生边际效应，切宏代码不可调试
 * 内联函数在 debug可调试，release 则为展开替换函数调用
 *
 * this 指针 等同 OC self，java this
 *
 *
 *
 *
 */
class Box       // 类定义
{
public:
    double length;
    string name;
    int    height;
    
    Box();              // 构造函数 实例化类时调用，用于成员变量初始化
    Box(string nam);    // 构造函数可以带参
    Box(const Box &obj) // 拷贝构造函数
    ~Box();             // 这是析构函数声明,每次删除所创建的对象时执行
    
    frient void printName(Box box);  // 友元函数
    
    void oxName(void);
    
private:
    string color;
    
protected:
    double width;
};

// 请注意：printWidth() 不是任何类的成员函数
void printName(Box box)
{
    /* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
    cout << "Width of box : " << box.width <<endl;
}

Box::~Box(void)
{
    cout << "Object is being deleted" << endl;
}

Box::Box(void)
{
    cout << "Object is being created" << endl;
}

Box::Box(const Box &obj)
{
    cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
    ptr = new int;
    *ptr = *obj.ptr; // 拷贝值
}

// 使用初始化列表来初始化字段：
Box::Box(string nam, double length, int height):name(nam),length(length),height(height)
{
    
}
// 等同于下面
Box::Box(string nam, double length, int height)
{
    name = nam;
    length = length;
    height = height;
}

class SmallBox:Box      // 类继承
{
public:
    void setSmallWidth(double wid);
    double getSmallWidth(void);
};

double SmallBox::getSmallWidth()
{
    return width;
}

void SmallBox::setSmallWidth(double wid)
{
    width = wid;
}

enum color{red,blue,green}rad;

int main(){
    
//    readfile();
    
    /**
     * << 输出运算符， >> 输入运算符
     * iostream C++ IO标准库
     * istream：cin ostream：cout cerr clog
     * :: 作用域运算符
     * typedef 为现有类型创建别名    typedef int qwer; typedef char Line[81]; Line类型就代表81个元素的字符数组
     * sizeof() 返回变量的大小 sizeof(intA): 4
     * c++  rand(), srand();
     * setw(13)  格式化输出    #include <iomanip>
     */
    cout << "Hello World!" << endl;
    
    cout << "sin(d):" << sin(200.374) << endl;

    cout << "Element" << setw( 13 ) << "Value" << endl;
    
    
    /* c字符串操作函数
     * strcpy(s1,s2) 复制字符串 s2 到字符串 s1。
     * strcat(s1,s2) 连接字符串 s2 到字符串 s1 的末尾。
     * strlen(s1)    返回字符串 s1 的长度。
     * strcmp(s1,s2) 如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回小于 0；如果 s1>s2 则返回大于 0。
     * strchr(s1,ch) 返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
     * strstr(s1,s2) 返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。
     */
    
    char str1[6] = "Hello";
    char str2[7] = "World!";
    char str3[6] = "qwer";
    cout << "strstr &:" << str1 + 1 << endl;
//    strcpy(str1,str2);
//    strcat(str1,str2);
//    strlen(str3);
//    if (strcmp(str1,str2) == 0) {
//        cout << "str1 == str2" << endl;
//    }
    
//    char chindx[3] = "el";
//    char *zz = strstr(str1,"l");
//    char *zz1 = strchr(str1,1);
//
//    cout << "strstr " << zz << endl;
//    cout << "strchr " << zz1 << endl;
    
    /* String 类
     *
     *
     */
//    string string1 = "Hello";
//    string string2 = "World!";
//    string string3;
//
//    string1.append(" world");
//
//    cout << string1 << endl;
    
    /* 引用和c指针
     * c++ 通过使用引用来替代指针，会使 C++ 程序更容易阅读和维护。
     * 便于传递参数
     */
    int za = 4;
    int *sdf = &za;
    int& sdg = za; // 等同 int * const sdg = &za;
    
    cout << "c 指针" << *sdf << endl;
    cout << " 引用" << sdg << endl;
    
    /* c++ 标准库没有提供时间相关的函数，继承了c 用于日期和时间操作的结构和函数。 #include <ctime>
     * 有四个与时间相关的类型：clock_t、time_t、size_t 和 tm。
     * 类型 clock_t、size_t 和 time_t 能够把系统时间和日期表示为某种整数。
     *
     * time 精度为s
     * 其他操作函数，省略
     */
    time_t now = time(0);
    cout << "1970 到目前经过秒数:" << now << endl;
    
    char* dt = ctime(&now);
    
    cout << "本地日期和时间：" << dt << endl;
    
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);
    cout << "UTC 日期和时间："<< dt << endl;
    
    // typedef 关键字，已知类型命名别名
    typedef int *pint32; // 指向int 的指针
    pint32 y,x;
    
    /* c++ 结构体 关键字：struct
     *
     *
     * time 精度为s
     */
    typedef struct Peoples    // 声明结构体类型 Peoples
    {
        char name[50];
        char sex[50];
        int age;
    }People;
    
    People laowang;  // 结构体变量声明
    People cuihua;
    
    strcpy(laowang.name,"laowang");
    strcpy(cuihua.name,"cuihua");
    
    laowang.age = 10;
    cout << "第一本书标题 : " << laowang.name <<endl;
    cout << "第一本书作者 : " << laowang.age <<endl;
 
    // 结构体做参数传递时，使用指针传递
    struct Peoples *stuuct_pointer; // 结构体指针，指针通过 -> 运算符访问结构的成员
    stuuct_pointer = &laowang;
    
    cout << "第一本书作者 : " << stuuct_pointer->name <<endl;
    
   
    
    Box box1;       // 类实例声明
    box1.length = 15313;
    box1.name = "big box";
    
    SmallBox amallBox;
    amallBox.setSmallWidth(68);
    
    cout << box1.name << endl;
    cout << amallBox.getSmallWidth() << endl;
    return 0;
}

// first c++ function
string founctionGetName(int age, string name, string sex)
{
    
    return "laowang";
}




