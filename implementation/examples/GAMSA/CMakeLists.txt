cmake_minimum_required(VERSION 2.8)
project(GAMSA)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp MsaGenotype.h MsaGenotypeMut.cpp MsaGenotypeMut.h MsaGenotypeCrsOnePoint.cpp MsaGenotypeCrsOnePoint.h MsaEvalOp.cpp MsaEvalOp.h FastaParser.cpp FastaParser.h MsaGenotypeMutInsertGap.cpp MsaGenotypeMutInsertGap.h MsaGenotypeMutDeleteGap.cpp MsaGenotypeMutDeleteGap.h)

find_package(Boost)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

include_directories(../../)
add_executable(GAMSA ${SOURCE_FILES})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_libraries(GAMSA ${CMAKE_CURRENT_SOURCE_DIR}/../../debug/libECF.a)
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_link_libraries(GAMSA ${CMAKE_CURRENT_SOURCE_DIR}/../../release/libECF.a)
endif()