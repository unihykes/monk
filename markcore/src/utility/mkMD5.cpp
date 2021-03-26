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
#include <boost/algorithm/hex.hpp>
#include <boost/uuid/detail/md5.hpp>
#include"mkMD5.h"
 
bool 
mkMD5::GetMd5(std::string &str_md5, const char* const buffer, size_t buffer_size)
{
	if (buffer == nullptr) {
		return false;
	}
	boost::uuids::detail::md5 boost_md5;
	boost::uuids::detail::md5::digest_type digest
    ;
    boost_md5.process_bytes(buffer, buffer_size);
	boost_md5.get_digest(digest);
	
    const char* char_digest = reinterpret_cast<const char*>(&digest);
	str_md5.clear();
	boost::algorithm::hex(char_digest,char_digest+sizeof(boost::uuids::detail::md5::digest_type), std::back_inserter(str_md5));
	return true;
}