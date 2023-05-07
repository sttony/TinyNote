cmake_minimum_required(VERSION 3.13)
project(TinyNote)

set(CMAKE_CXX_STANDARD 14)

find_package(Qt5 COMPONENTS Widgets REQUIRED)


add_executable(${PROJECT_NAME} main.cpp jsoncpp.cpp CNoteBook.cpp CNoteBook.h CNotebookEntry.cpp CNotebookEntry.h CNotebookElement.cpp CNotebookElement.h)

target_link_libraries(
        ${PROJECT_NAME}
        Qt5::Widgets
)