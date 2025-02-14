# Минимальная требуемая версия CMake
cmake_minimum_required(VERSION 3.29)

# Название проекта
project(_Programming_Basics_CPP_11_1)

# Устанавливаем стандарт C++ (C++20)
set(CMAKE_CXX_STANDARD 20)

# Создаём статическую библиотеку greeting_library из исходного файла
add_library(greeting_library STATIC lib/greeting_library.cpp)

# Указываем директорию, содержащую заголовочные файлы библиотеки
target_include_directories(greeting_library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Создаём исполняемый файл
add_executable(_Programming_Basics_CPP_11_1 main.cpp)

# Привязываем (линкуем) библиотеку greeting_library к исполняемому файлу
target_link_libraries(_Programming_Basics_CPP_11_1 greeting_library)