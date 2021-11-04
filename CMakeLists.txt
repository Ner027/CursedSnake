cmake_minimum_required(VERSION 3.20)
project(snake)

link_directories("/home/nero/Desktop/Software Development/C|C++/Ncurses")

set(CMAKE_CXX_STANDARD 23)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(snake main.cpp CursesWrapper/Rect.cpp CursesWrapper/Rect.h CursesWrapper/Vector2.cpp CursesWrapper/Vector2.h CursesWrapper/Util.cpp CursesWrapper/Util.h Player.cpp Player.h GameManager.cpp GameManager.h Utils.cpp Utils.h Consts.h)

target_link_libraries(snake libncurses.a Threads::Threads)
