set(OUT_FILE_NAME ConsoleTimer_TEST)
set(SOURCES Main.cpp)

add_executable(${OUT_FILE_NAME})

target_sources(${OUT_FILE_NAME}
    PRIVATE ${SOURCES})

target_include_directories(${OUT_FILE_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
    PRIVATE ${CMAKE_SOURCE_DIR}/Source
)
