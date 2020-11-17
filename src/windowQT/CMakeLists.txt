cmake_minimum_required(VERSION 3.0.0)
project(test)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

SET(CMAKE_AUTOMOC True)

SET(SRCS
	WindowQT.cpp
)

SET(HEADERS
	WindowQT.hpp

)

add_executable(main ${SRCS} ${HEADERS})
target_link_libraries(main Qt5::Widgets Qt5::Core Qt5::Gui)