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
};

#endif // FUNVOID_H
