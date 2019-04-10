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
#include <mkOptionSwitch.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// 
//

class mkMultiChannel final : public mkIOption
{
public:
    mkMultiChannel() 
        : mkIOption({"aaa","bbb","ccc"})
        , _dataChannelCount(12)
        , _metaChannelCount(33)
    {
    }
    
    virtual void SetVaule (const string& key, const string& value) override
    {
    }
    
    virtual void Apply() override
    {
    }
    
    const int GetDataChannelCount() const 
    {
        return _dataChannelCount;
    }
    
    const int GetMetaChannelCount() const 
    {
        return _metaChannelCount;
    }
    
private:
    int     _dataChannelCount;//data通道数量
    int     _metaChannelCount;//meta通道数量
};

class mkOptionA final : public mkIOption
{
public:
    mkOptionA() 
        :mkIOption({"ddd","eee","fff"})
    {
    }
    
    virtual void SetVaule (const string& key, const string& value) override
    {
    }
    
    virtual void Apply() override
    {
    }
    
    int GetfuncA() const
    {
         return 100;
    }
    
private:
    int _value;
};

class mkOptionB final : public mkIOption
{
public:
    mkOptionB() 
        :mkIOption({"ggg","hhh","iii"})
    {
    }
    
    virtual void SetVaule (const string& key, const string& value) override
    {
    }
    
    virtual void Apply() override
    {
    }
    
    string GetFuncB() const
    {
        return "abc";
    }
private:
    string _value;
};

//备份选项
class mkBackupSwitch  final : public mkIOptionSwitch
{
public:
    mkBackupSwitch()
    {
        RegisterOption<mkMultiChannel>();
        RegisterOption<mkOptionA>();
        RegisterOption<mkOptionB>();
    }

    ~mkBackupSwitch()
    {
    }
    
private:
    virtual void BeforeApplyAttrBatch() override
    {
    }
};


TEST(ut_mkIOptionSwitch, mkBackupSwitch)
{
    mkBackupSwitch switchs;
    
    try {
        //设置选项
        switchs.SetOptionAttrBatch("aaa", "test_value1");
        switchs.SetOptionAttrBatch("ddd", "test_value2");
        switchs.SetOptionAttrBatch("fff", "test_value3");
        switchs.SetOptionAttrBatch("hhh", "test_value4");
        switchs.ApplyOptionAttrBatch();
        MK_PRINT();
        
        //使用选项
        {
            auto pOption = switchs.GetOption<mkMultiChannel>();
            MK_PRINT("cout = %d", pOption->GetDataChannelCount());
            MK_PRINT("cout = %d", pOption->GetMetaChannelCount());
        }
        {
            auto pOption = switchs.GetOption<mkOptionA>();
            int id = pOption->GetfuncA();
            MK_PRINT("id = %d", id);
        }
        {
            auto pOption = switchs.GetOption<mkOptionB>();
            string name = pOption->GetFuncB();
            MK_PRINT("name = %s", name);
        }
        
        //修改选项
        {
            switchs.SetOptionAttr<mkMultiChannel>("aaa", "test_valuexxx");
            switchs.SetOptionAttr<mkMultiChannel>("bbb", "test_valueyyy");
            switchs.SetOptionAttr<mkMultiChannel>("ccc", "test_valuezzz");
            switchs.ApplyOptionAttr<mkMultiChannel>();
        }
        
        //禁用选项
        {
            switchs.DisableOption<mkMultiChannel>();
        }
    }
    catch(string& e) {
        MK_PRINT("e = %s", e.c_str());
    }
}