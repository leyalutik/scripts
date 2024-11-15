//#Creating directory with files : 
#main.cpp (base file)  with add unit_tests.cpp
#class.cpp class.h (files for test)
#unit_tests.cpp (file with Google Unit Tests test functions) and examples all 10
#if smth wrong to display instuction how valid pattern of command 
#and instruction how install google test 


#Steps
#Input command framework
# display menu
# base						-> main.cpp
# class number_class name1_class name2_class 	-> main.cpp {namen_class.cpp namen_class.h}
# unit_tests					-> main class unit_tests.cpp
# unknown commands

# enter name directory
# if directory exist - ask another name
#create directory with neccerary files


#!/bin/bash


#include<iostream>


echo base
echo class
echo unit
read -p answer

do []
echo Input directory name:
read -p directory_name
while  [ [ -e  directory_name ]] 




if [answer==base] 
	cd directory_name && touch main.cpp 
	&& cat "#include<iostream>\n #include<string>\n include<vector>\n #include<exception>\n
	int main()\n{\n\nreturn0;\n}\n" > main.cpp
endif

elif [answer==class]

	echo Input number of classes
	read -p number_class # point it's a number
	cd directory_name && touch main.cpp 
	&& cat "#include<iostream>\n #include<string>\n include<vector>\n #include<exception>\n
	int main()\n{\n\nreturn0;\n}\n" > main.cpp
	mkdir SOURCE
	cd SOURCE
	mkdir INCLUDE
	touch CMakeLists.txt
	cat "add_library ( source_lib\n" > CMakeLists.txt
	for(int i=0; i<number_class; ++i)
	{
		echo Input class name:
		read -p class_name
		echo Creating files: $(class_name).cpp $(class_name).h 
	#create file cpp
		touch $(class_name).cpp
		cat "#include\"$(class_name).h\"" > class_name.cpp
	#create file h		
		cd INCLUDE
		touch $(class_name).h
		cat "#ifndef $(class_name)_h (function with UPPER_LETTER)\n#define $(class_name)_h\n
		#include<iostream>\n #include<string>\n include<vector>\n #include<exception>\n
		class $(class_name)\n{\n\n};\n
		#endif\n" > class_name.h
	#add to CMakelists  library  new file
	cat "$(class_name).cpp\n " >> CMakelists.txt
	}

	#add to CMakelists  library  new file
	cat ")\n SET(MY_INCLUDE \"INCLUDE\") " >> CMakelists.txt
	target_link_library(source_lib INCLUDE) 
Доделать
Правильные файлы CMakeLists.txt (подсмотреть skillbox 26)


	}


