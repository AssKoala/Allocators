cmake_minimum_required(VERSION 3.22)

project(koala-allocators)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED True)

# We want all the warnings and as errors enabled
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)

	# add win32 version, we'll target Win10
	add_compile_definitions(_WIN32_WINNT=0x0A00)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# Set options for cmake
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../bin)

set(SOURCEDIR source)
set(SOURCES ${SOURCEDIR}/main.cpp
			${SOURCEDIR}/allocators/FixedBlockAllocator.cpp
			)

set(INCLUDEDIR include)
set(INCLUDES 	${INCLUDEDIR}/IAllocator.h
				${INCLUDEDIR}/KoalaAllocator.h
				${INCLUDEDIR}/FixedBlockAllocator.h
				${INCLUDEDIR}/koala_intrusive_list.h
				)

add_executable(koala-allocators ${SOURCES} ${INCLUDES})

target_link_libraries(koala-allocators )#${Boost_LIBRARIES})
target_include_directories(koala-allocators 
			PRIVATE ${INCLUDEDIR}
			#${Boost_INCLUDE_DIRS}
			)
