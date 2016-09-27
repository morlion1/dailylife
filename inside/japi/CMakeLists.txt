cmake_minimum_required(VERSION 2.8)
project( Japi )
find_package( OpenCV REQUIRED )
add_executable( Japi Japi.cpp )
target_link_libraries( Japi ${OpenCV_LIBS} )

