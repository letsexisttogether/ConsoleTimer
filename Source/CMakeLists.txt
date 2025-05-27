set(OUT_FILE_NAME ConsoleTimer)

set(SOURCES Main.cpp
    OutputColorizer/Colorizer.cpp
    Timer/Timer.cpp)

add_executable(${OUT_FILE_NAME})

target_sources(${OUT_FILE_NAME}
    PRIVATE ${SOURCES})

target_include_directories(${OUT_FILE_NAME}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    