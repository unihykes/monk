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

Time:2021-1

info:

***************************************************************************************************/

#include<mkheaders.h>
#include "print/mkPrint.h"
#include "utility/mkTrace.h"
#include "utility/mkLog.h"
#include "utility/mkOptionSwitch.h"
#include "utility/mkVersion.h"
#include "utility/mkPerf.h"
#include "mkModuleInstance.h"

MK_DEFINE_MODULE_INSTANCE(markcore, markcore, 1, 0, 0);

mkModuleInstance::mkModuleInstance(const std::string& moduleName, const std::string& resName,
    unsigned int major, unsigned int minor, unsigned int patch)
{
    _trace = make_shared<mkTrace>(moduleName);
    _loger = make_shared<mkLog>(moduleName);
    _print = make_shared<mkPrint>(moduleName);
    _switch = make_shared<mkOptionSwitch>();
    _version = make_shared<mkVersion>(major, minor, patch);
    _perf = make_shared<mkPerf>(moduleName);
}

mkModuleInstance::~mkModuleInstance()
{
    
}