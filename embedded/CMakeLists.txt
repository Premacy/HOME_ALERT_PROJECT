project(HOME_ALERT)

set(SRC main.cpp Application/src/Application.cpp)

include_directories(Application/include)
include_directories(${CMAKE_SOURCE_DIR})

add_executable(HOME_ALERT ${SRC})