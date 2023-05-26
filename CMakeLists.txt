cmake_minimum_required(VERSION 3.13)
project(TinyNote)

set(CMAKE_CXX_STANDARD 14)
set(Boost_DEBUG 1)
FIND_PACKAGE(Boost REQUIRED filesystem system)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

find_package(Qt5 COMPONENTS Widgets REQUIRED)
qt5_wrap_cpp(MOC_SOURCES MainWindow.h)

add_executable(${PROJECT_NAME} main.cpp CNoteBook.cpp CNoteBook.h CNotebookEntry.cpp CNotebookEntry.h CNotebookElement.cpp CNotebookElement.h MainWindow.cpp MainWindow.h ${MOC_SOURCES} ErrorCode.h CNotePage.cpp)

target_link_libraries(
        ${PROJECT_NAME}
        Qt5::Core
        Qt5::Widgets
        Boost::system
        Boost::filesystem
        ${Boost_LIBRARIES}
)