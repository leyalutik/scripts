#!/bin/bash

# Ввод имени проекта
echo "Input Project name:"
read project_name

# Создание имени директории
directory_name="${project_name}_directory"

# Проверка существования директории
if [ -d "$directory_name" ]; then
  echo "Directory with such project name exists. Please enter another name."
  exit 1
fi

# Создание основной директории и переход в неё
mkdir "$directory_name"
cd "$directory_name" || exit

MAIN()
{
  echo -e "
#include<iostream>\n#include<string>\n#include<vector>\n#include<exception>\n\n
  int main() \n{\n    return 0;\n}
  " >> main.cpp
}

MAIN_SOURCE()
{
echo -e "
#include\"$1.h\"\n
" >> main.cpp
}
MAKEFILE()
{
# Создание Makefile
  echo -e "CXX = g++\nCXXFLAGS = -std=c++17 -Wall -Wextra -pedantic\n\nTARGET = main\n\nall: \$(TARGET)\n\n\$(TARGET): main.cpp\n\t\$(CXX) \$(CXXFLAGS) -o \$(TARGET) main.cpp\n\nclean:\n\trm -f \$(TARGET)" > Makefile
 

}

CLASS_CPP()
{


    echo -e "#include \"${class_name}.h\"\n\nvoid ${class_name}::example() {}\n" > "${class_name}.cpp"

}

CLASS_H()
{
    echo -e "#ifndef ${class_name}_H\n#define ${class_name}_H\n\nclass ${class_name} {\npublic:\n    void example();\n};\n\n#endif" > "${class_name}.h"

}

CMAKELISTS_SIMPLE()
{
 echo -e "cmake_minimum_required(VERSION 3.10)\n\nproject(${project_name})\n\nset(CMAKE_CXX_STANDARD 17)\nset(CMAKE_CXX_STANDARD_REQUIRED True)\n\nadd_executable(${project_name} main.cpp ${class_name}.cpp)" > CMakeLists.txt
}
CMAKELISTS_BASE()
{
    echo -e "cmake_minimum_required(VERSION 3.10)\nproject(${project_name})\n\nset(CMAKE_CXX_STANDARD 17)\n\nadd_subdirectory(SOURCE)\nadd_executable(${project_name} main.cpp)\ntarget_include_directories(${project_name} PUBLIC \${CMAKE_SOURCE_DIR}/INCLUDE)\ntarget_link_libraries(${project_name} source_lib)\n" > CMakeLists.txt
}

CMAKELISTS_SOURCE()
{
    echo -e "set(SOURCE_FILES\n" > CMakeLists.txt
    for file in $(ls *.cpp); do
      echo -e "    ${file}" >> CMakeLists.txt
    done
    echo -e ")\nadd_library(source_lib \${SOURCE_FILES})\ntarget_include_directories(source_lib PUBLIC \${CMAKE_SOURCE_DIR}/INCLUDE)\n" >> CMakeLists.txt

}
# Меню выбора
echo "Options:"
echo "base  -> Create a simple main.cpp file."
echo "class -> Create main.cpp, class files, and CMakeLists.txt."
echo "unit  -> Create main.cpp, class files, unit_tests.cpp with Google Test."
echo "Enter your choice:"
read answer

# Базовый проект
if [[ "$answer" == "base" ]]; then
  touch main.cpp
  MAIN
  echo "Created main.cpp with a basic template."
  touch Makefile
MAKEFILE
 echo "Created Makefile for building the project."

  echo "To build the project, run 'make'. To clean up, run 'make clean'."
# Проект с классами
elif [[ "$answer" == "class" ]]; then
mkdir build
  echo "simple (main.cpp, class.cpp, class.h)"
  echo "complex (SOURCE, INCLUDE)"
  read level

  if [[ "$level" == "simple" ]]; then
    echo "Input class name:"
    read class_name
    # Создание файлов
    touch main.cpp
 MAIN
    touch "${class_name}.cpp"
    CLASS ${class_name}
    CLASS_CPP ${class_name}
    touch "${class_name}.h"
    CLASS_H ${class_name}
    echo "Created main.cpp, ${class_name}.cpp, and ${class_name}.h."
# Создание CMakeLists.txt
    touch CMakeLists.txt
CMAKELISTS_SIMPLE ${project_name}
    echo "Created main.cpp, ${class_name}.cpp, ${class_name}.h, and CMakeLists.txt for a simple project."



elif [[ "$level" == "complex" ]]; then
     

    touch main.cpp
    mkdir SOURCE INCLUDE
    echo "Input number of classes:"
    read number_classes

    for ((i = 1; i <= number_classes; i++)); do
      echo "Input class name $i:"
      read class_name
      MAIN_SOURCE "${class_name}"
cd SOURCE
      # Создание файлов
      touch "${class_name}.cpp"

CLASS_CPP ${class_name}
cd ../INCLUDE

      touch "${class_name}.h"
CLASS_H ${class_name}
 cd ..
    done

    # Создание главного CMakeLists.txt
    MAIN
    touch CMakeLists.txt
    CMAKELISTS_BASE ${project_name}

    # Создание CMakeLists.txt в SOURCE
    cd SOURCE
    touch CMakeLists.txt
    CMAKELISTS_SOURCE ${project_name}

     cd .. 
    echo "Created complex project structure with SOURCE and INCLUDE directories, and CMakeLists.txt."
  

fi

# Проект с тестами
elif [[ "$answer" == "unit" ]]; then

mkdir build
  echo "simple (main.cpp, class.cpp, class.h, unit_tests.cpp)"
  echo "complex (SOURCE, INCLUDE, samples)"
  read level

  if [[ "$level" == "simple" ]]; then
    echo "Input class name:"
    read class_name
    # Создание файлов
    touch main.cpp
    MAIN
    touch "${class_name}.cpp"
    CLASS_CPP ${class_name}
    touch "${class_name}.h"
    CLASS_H ${class_name}

    # Создание файла с тестами
    mkdir tests
    touch tests/unit_tests.cpp
    cd tests
    echo -e "#include \"${class_name}.h\"\n#include <gtest.h>\n\nTEST(${class_name}Test, ExampleTest) {\n    EXPECT_EQ(1, 1);\n}\n\nint main(int argc, char **argv) \n{\n    ::testing::InitGoogleTest(&argc, argv);\n    return RUN_ALL_TESTS();\n}" > unit_tests.cpp
cd ..
    # Создание CMakeLists.txt
    touch CMakeLists.txt
    CMAKELISTS_UNIT_SIMPLE ${project_name}
    {
    echo -e "cmake_minimum_required(VERSION 3.10)\nproject(${project_name})\n\nset(CMAKE_CXX_STANDARD 17)\n\nadd_executable(${project_name} main.cpp ${class_name}.cpp unit_tests.cpp)\ntarget_include_directories(${project_name} PUBLIC .)\ntarget_link_libraries(${project_name} gtest gtest_main pthread)" > CMakeLists.txt
}
    echo "Created project with Google Test integration. Ensure Google Test is installed."

  elif [[ "$level" == "complex" ]]; then
    mkdir SOURCE INCLUDE tests
    echo "Input number of classes:"
    read number_classes

    for ((i = 1; i <= number_classes; i++)); do
      echo "Input class name $i:"
      read class_name
      # Создание файлов для класса
      cd SOURCE
      touch "${class_name}.cpp"

CLASS_CPP ${class_name}
cd ../INCLUDE

      touch "${class_name}.h"
CLASS_H ${class_name} 
 cd ..
 done

    # Копирование директории samples из Google Test
    home_path=$(pwd)  # Запоминаем текущую директорию
    gtest_samples_path=~/Desktop/git/googletest/samples  # Укажите путь к samples
    if [[ -d "$gtest_samples_path" ]]; then
      cp -R "$gtest_samples_path" "$home_path/tests/samples"
      echo "Copied Google Test samples to $home_path/tests/samples."
    else
      echo "Google Test samples directory not found at $gtest_samples_path."
    fi

    # Создание файла unit_tests.cpp
    touch tests/unit_tests.cpp
    echo -e "#include <gtest/gtest.h>\n#include \"../INCLUDE/sample_class.h\"\n\nTEST(SampleClassTest, ExampleTest) {\n    EXPECT_EQ(1, 1);\n}\n\nint main(int argc, char **argv) \n{\n    ::testing::InitGoogleTest(&argc, argv);\n    return RUN_ALL_TESTS();\n}" > tests/unit_tests.cpp

    # Создание CMakeLists.txt
    touch CMakeLists.txt
    echo -e "cmake_minimum_required(VERSION 3.10)\nproject(${project_name})\n\nset(CMAKE_CXX_STANDARD 17)\n\nadd_subdirectory(SOURCE)\nadd_executable(${project_name} main.cpp)\ntarget_include_directories(${project_name} PUBLIC INCLUDE)\ntarget_link_libraries(${project_name} gtest gtest_main pthread)" > CMakeLists.txt

    echo "Created complex project with Google Test integration and copied samples."
  fi


# Неизвестная команда
else
  echo "Unknown command. Please choose 'base', 'class', or 'unit'."
  exit 1
fi

