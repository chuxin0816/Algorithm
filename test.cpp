/*n个有序数a1,a2,...,an组成的数组称为n维向量。 为n维向量定义CVector类，包含私有数据成员：

int *data；//存储n维向量

int n； //向量维数。

方法有：无参构造函数，设置n=5,data的数据分别为0,1,2,3,4；构造函数，用虚参n1和数组a初始化n和data的数据；输出函数，按格式输出n维向量的值；析构函数。

主函数输入数据，生成CVector对象并调用输出函数测试。*/
#include <iostream>
using namespace std;
class CVector
{
private:
    int *data;
    int n;
public:
    CVector();
    CVector(int n1,int *a);
    void print();
    ~CVector();
};
CVector::CVector()
{
    n=5;
    data=new int[n];
    for(int i=0;i<n;i++)
        data[i]=i;
}
CVector::CVector(int n1,int *a)
{
    n=n1;
    data=new int[n];
    for(int i=0;i<n;i++)
        data[i]=a[i];
}
void CVector::print()
{
    for(int i=0;i<n;i++)
        cout<<data[i]<<" ";
    cout<<endl;
}
CVector::~CVector()
{
    delete []data;
}
int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    CVector v1;
    CVector v2(n,a);
    v1.print();
    v2.print();
    delete []a;
    return 0;
}
