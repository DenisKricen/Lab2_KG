cmake_minimum_required(VERSION 3.16)

# Назва твого проєкту
project(Lab1_KG LANGUAGES CXX)

# Стандарт C++ (Qt 6 вимагає мінімум C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Автоматична генерація мета-файлів Qt (це магія Qt)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Ось тут CMake звернеться до vcpkg, щоб знайти Qt
find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Core)

# Створюємо виконуваний файл. 
# ВАЖЛИВО: переконася, що у тебе є файл main.cpp
add_executable(Lab1_KG core/main.cpp)

# Підключаємо бібліотеки Qt до твого файлу
target_link_libraries(Lab1_KG PRIVATE Qt6::Widgets Qt6::Gui Qt6::Core)