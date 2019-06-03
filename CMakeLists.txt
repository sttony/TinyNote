cmake_minimum_required(VERSION 3.13)
project(TinyNote)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets COMPONENTS core base REQUIRED)

include("${wxWidgets_USE_FILE}")


add_executable(${PROJECT_NAME} main.cpp MainFrame.cpp MainFrame.h jsoncpp.cpp CNoteBook.cpp CNoteBook.h CNotebookEntry.cpp CNotebookEntry.h CNotebookElement.cpp CNotebookElement.h)

target_link_libraries(
        ${PROJECT_NAME}
        ${wxWidgets_LIBRARIES}
)