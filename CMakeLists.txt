cmake_minimum_required(VERSION 3.31.7 FATAL_ERROR)

project(RayTracingInOneWeekend CXX)

include(GenerateExportHeader)

add_library(RayTracingInOneWeekend 
    src/vec3.cpp
    src/color.cpp
    src/sphere.cpp
    src/hittable_list.cpp
)
target_sources(RayTracingInOneWeekend
    PUBLIC
    FILE_SET HEADERS
    BASE_DIRS ${CMAKE_CURRENT_LIST_DIR}/include ${CMAKE_CURRENT_BINARY_DIR}/include
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/include/rtiow_export.hpp
        include/vec3.hpp
        include/color.hpp
        include/ray.hpp
        include/hittable.hpp
        include/sphere.hpp
        include/hittable_list.hpp
)

set_target_properties(RayTracingInOneWeekend PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN ON
)

generate_export_header(RayTracingInOneWeekend
    BASE_NAME rtiow
    EXPORT_FILE_NAME ${CMAKE_CURRENT_BINARY_DIR}/include/rtiow_export.hpp
)

add_executable(inOneWeekend main.cpp)

target_link_libraries(inOneWeekend
    PRIVATE 
        RayTracingInOneWeekend
)
