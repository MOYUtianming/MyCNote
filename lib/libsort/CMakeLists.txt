project(sort)

add_library(bubble_sort libbubble_sort/bubble_sort.c)

target_include_directories(
    bubble_sort
    PUBLIC ${PROJECT_SOURCE_DIR}/libbubble_sort
)
target_link_libraries(
    bubble_sort
    status_report
)

add_library(insertion_sort libinsertion_sort/insertion_sort.c)

target_include_directories(
    insertion_sort
    PUBLIC ${PROJECT_SOURCE_DIR}/libinsertion_sort
)
target_link_libraries(
    insertion_sort
    status_report
)

add_library(merge_sort libmerge_sort/merge_sort.c)

target_include_directories(
    merge_sort
    PUBLIC ${PROJECT_SOURCE_DIR}/libmerge_sort
)
target_link_libraries(
    merge_sort
    status_report
)
