/***************************************************************************************************
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

#include <markcore.h>
#include <gtest/gtest.h>

TEST(mkOptionSwitch, run)
{
    class mkOptionA final : public mkIOption
    {
    public:
        mkOptionA()
            : mkIOption()
        {
        }
        
        virtual bool OnSetValue (const string& key, const string& value) override
        {
            return true;
        }
        
        int Get() const
        {
            return 1024;
        }
    };
    
    mkOptionSwitch switchs;
    switchs.ClearOption<mkOptionA>();
    
    //设置选项
    switchs.SetOptions("aaa", "test_value1", false);
    switchs.SetOptions("ddd", "test_value2", false);
    switchs.SetOptions("fff", "test_value3", false);
    switchs.SetOptions("hhh", "test_value4", false);
    switchs.Applys();
    
    //使用选项
    {
        auto pOption = switchs.GetOption<mkOptionA>();
        pOption->Get();

    }
    
    //修改选项
    {
        switchs.SetOption<mkOptionA>("aaa", "test_valuexxx");
        switchs.Apply<mkOptionA>();
    }
}