PROJECT(use_boost)

#version
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
CMAKE_POLICY(VERSION 2.8)

#begin
INCLUDE($ENV{MK_PATH}/make/begin.cmake)

#目标类型
SET(TARGET_NAME use_boost)
SET(TARGET_TYPE RUNTIME)
SET(AUTO_RUN OFF)

#依赖库
SET(NEED_MARKCORE TRUE)
SET(NEED_BOOST_FULL TRUE)
SET(NEED_GTEST TRUE)
SET(NEED_BENCHMARK TRUE)

#借用 main.cpp
set(INCLUDE_SOURCE_FILES ${INCLUDE_SOURCE_FILES} ${MK_PATH}/markcore/ut/main.cpp)


#end
INCLUDE($ENV{MK_PATH}/make/end.cmake)
