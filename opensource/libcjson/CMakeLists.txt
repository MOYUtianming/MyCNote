project(cjson)

add_library(cjson cJSON.c)

target_include_directories(
    cjson
    PUBLIC ${PROJECT_SOURCE_DIR}
)

add_library(cjson_utils cJSON_Utils.c)

target_include_directories(
    cjson_utils
    PUBLIC ${PROJECT_SOURCE_DIR}
)
