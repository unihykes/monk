PROJECT(bm_leveldb)

#version
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)
CMAKE_POLICY(VERSION 3.1)

#begin
INCLUDE($ENV{MK_PATH}/make/begin.cmake)

#Ŀ������
SET(TARGET_NAME bm_leveldb)
SET(TARGET_TYPE RUNTIME)

#������
SET(NEED_GTEST TRUE)
SET(NEED_LEVELDB TRUE)
SET(NEED_MARKCORE TRUE)


ADD_DEFINITIONS(-DLEVELDB_PLATFORM_POSIX)
include_directories(${MK_PATH}/3rd_Party/leveldb/leveldb/include)
include_directories(${MK_PATH}/3rd_Party/leveldb/leveldb)

set(INCLUDE_SOURCE_FILES ${INCLUDE_SOURCE_FILES} ${MK_PATH}/3rd_Party/leveldb/leveldb/benchmarks/db_bench.cc)
set(INCLUDE_SOURCE_FILES ${INCLUDE_SOURCE_FILES} ${MK_PATH}/3rd_Party/leveldb/leveldb/util/histogram.cc)
set(INCLUDE_SOURCE_FILES ${INCLUDE_SOURCE_FILES} ${MK_PATH}/3rd_Party/leveldb/leveldb/util/testutil.cc)
set(INCLUDE_SOURCE_FILES ${INCLUDE_SOURCE_FILES} ${MK_PATH}/3rd_Party/leveldb/leveldb/util/crc32c.cc)
set(INCLUDE_SOURCE_FILES ${INCLUDE_SOURCE_FILES} ${MK_PATH}/3rd_Party/leveldb/leveldb/util/comparator.cc)


#end
INCLUDE($ENV{MK_PATH}/make/end.cmake)
