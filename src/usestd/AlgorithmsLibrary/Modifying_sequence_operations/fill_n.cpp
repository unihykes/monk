﻿/***************************************************************************************************
Author:liu.hao

Time:2018-6

info:
    
***************************************************************************************************/

#include <mkheaders.h>
#include <gtest/gtest.h>


//将一个值赋给一定数目的元素 
TEST(MSQ, fill_n)
{
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::fill_n(v.begin(), 5, -1);
    for (auto elem : v) {
        MK_PRINT_MSG("n = %d", elem);
    }
}