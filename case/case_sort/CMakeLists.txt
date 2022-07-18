project(case_sort)

add_executable(case_bubble_sort case_bubble_sort.c)

target_link_libraries(
    case_bubble_sort
    status_report
    bubble_sort
)

target_include_directories(
    case_bubble_sort
    PUBLIC ../
    PUBLIC ../../lib/libsort/libbubble_sort
)

add_executable(case_insertion_sort case_insertion_sort.c)

target_link_libraries(
    case_insertion_sort
    status_report
    insertion_sort
)

target_include_directories(
    case_insertion_sort
    PUBLIC ../
    PUBLIC ../../lib/libsort/libinsertion_sort
)

add_executable(case_merge_sort case_merge_sort.c)

target_link_libraries(
    case_merge_sort
    status_report
    merge_sort
)

target_include_directories(
    case_merge_sort
    PUBLIC ../
    PUBLIC ../../lib/libsort/libmerge_sort
)
