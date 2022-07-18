project(status_report)

add_library(status_report status_report.c)

target_include_directories(
    status_report
    PUBLIC ${PROJECT_SOURCE_DIR}
)
