project(case_hello_world)

add_executable(case_hello_world hello_world.c)

target_link_libraries(
    case_hello_world
    status_report
)
