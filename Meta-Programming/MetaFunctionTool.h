//
// Created by cheyulin on 7/11/16.
//

#ifndef STLSTUDY_METAFUNCTIONTOOL_H
#define STLSTUDY_METAFUNCTIONTOOL_H

#include <boost/config.hpp>
#include "assert.h"

#define mp_arglist template //元函数参数列表开始
#define mp_arg typename //元函数参数声明
#define mp_function struct //元函数定义
#define mp_data typedef //元数据定义

#define mp_return(T) mp_data T type //元函数返回
//#define mp_return(T) using type = T
#define mp_exec(Func) Func::type //获得元函数返回结果
#define mp_eval(Func) Func::value //获得元函数返回值

#endif //STLSTUDY_METAFUNCTIONTOOL_H
