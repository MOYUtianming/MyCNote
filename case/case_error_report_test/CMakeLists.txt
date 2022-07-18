project(case_error_report_test)

add_executable(case_error_report_test case_error_report_test.c)

target_link_libraries(
    case_error_report_test
    status_report
)
