project(case_cJson_test)

add_executable(case_cJson_test case_cJson_test.c)

target_link_libraries(
    case_cJson_test
    status_report
    cjson
)
