#include <bits/stdc++.h>
using namespace std;
class student{
    private:
    int x1,x2,x3;
    int *s=new int[1000];
    public:
    student():x1(0),x2(0),x3(0){}
    // student(int x1,int x2,int x3):x1(x1),x2(x2),x3(x3){}
    /* student(int x1,int x2,int x3){
        x1=x1;
        x2=x2;
        x3=x3;
    } */
    void print() {
        cout<<x1<<' '<<x2<<' '<<x3<<endl;
    }
};
student a(1,2,3);
int main() {
    
    a.print();
    return 0;
}

