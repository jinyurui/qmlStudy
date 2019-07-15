#ifndef FUNVOID_H
#define FUNVOID_H

#include <QDebug>

class FunVoid
{
public:
    FunVoid(){}

    // 函数返回类型
    template <typename Class, typename R, typename... Args>
    static R ResultType(R (Class::*)(Args...) const)
    {
        return R();
    }

    // 形参列表


    static void print()
    {
       qDebug() << "empty" << endl;
    }
    //展开函数
    template <class T, class ...Args>
    static void print(T head, Args... rest)
    {
       qDebug() << "parameter " << head ;
       print(rest...);
    }
};

#endif // FUNVOID_H
