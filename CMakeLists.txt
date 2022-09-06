cmake_minimum_required(VERSION 3.0.0)
# set project
project(cTest VERSION 0.0.1)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

# include CMake module
include(CTest) #CMake module for test
include(InstallRequiredSystemLibraries)
# set c version
set(CMAKE_C_STANDARD 99)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# set build params
add_compile_options(--save-temps)
# include path
# add_subdirectory(lib/libcjson)
include_directories(
    ${PROJECT_SOURCE_DIR}/case
    ${PROJECT_SOURCE_DIR}/lib
    )

add_subdirectory(lib/libsort)
add_subdirectory(opensource/libcjson)
add_subdirectory(lib/libstatusreport)
add_subdirectory(case/case_cJson_test)
add_subdirectory(case/case_hello_world)
add_subdirectory(case/case_error_report_test)
add_subdirectory(case/case_sort)
# test block
enable_testing()
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 	bin)
# install block
# install(TARGETS caseHelloWorld
#     RUNTIME DESTINATION bin)

# pack block

include(CPack)
set(CPACK_SOURCE_IGNORE_FILES
${PROJECT_SOURCE_DIR}/build
${PROJECT_SOURCE_DIR}/data
${PROJECT_SOURCE_DIR}/note
${PROJECT_SOURCE_DIR}/photos
${PROJECT_SOURCE_DIR}/ref
${PROJECT_SOURCE_DIR}/.gitignore
${PROJECT_SOURCE_DIR}/C.code-workspace
${PROJECT_SOURCE_DIR}/Doxyfile
)

set(CPACK_PACKAGE_NAME "cTest")
set(CPACK_SOURCE_GENERATOR "7Z")
set(CPACK_INSTALL_PREFIX, "cTest")
set(CPACK_PACKAGE_DIRECTORY "cTest")
set(CPACK_OUTPUT_FILE_PREFIX ${PROJECT_SOURCE_DIR}/pack)
