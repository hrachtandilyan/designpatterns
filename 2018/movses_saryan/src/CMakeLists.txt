cmake_minimum_required (VERSION 2.6)
project (Marvel)
set(CMAKE_CXX_STANDARD 11) # Enable c++11 standard
set(YOUR_DIRECTORY, C:/Users/Developer/Desktop/self/CmakeTest/src)

set(SOURCE_FILES BadGuyBase.h Censored.h MainGirlBase.h MarvelFactoryBase.h SpidermanClasses.h SpidermanFactory.cpp SpidermanFactory.h SuperHeroBase.h SupermanFactory.h marvel.cpp
)    

add_executable(Marvel ${SOURCE_FILES})

target_include_directories(Marvel PUBLIC ${SOURCE_FILES})