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

Time:2017-6

info:

***************************************************************************************************/

#include <markcore.h>
#include <gtest/gtest.h>

MK_DEFINE_EXEC_INSTANCE(use_brpc, use_brpc, 1, 1, 1);

////////////////////////////////////////////////////////////////////////////////////////////////////
// main
//
int main(int argc, char** argv)
{
    auto gtestEnv = g_moduleInstance->_switch->InitEnv(argc, argv);
    // 获取输入参数
    if(gtestEnv.first == 1) {
        testing::GTEST_FLAG(list_tests) = true;
    }
    
    testing::InitGoogleTest(&gtestEnv.first, gtestEnv.second);
    int ret = RUN_ALL_TESTS ();
    return ret;
}