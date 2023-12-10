make:
	g++ -std=c++11 -o FileSystem_test FileSystem_test.cpp FileSystem.cpp
	g++ -std=c++11 -o Database_test Database_test.cpp Database.cpp FileSystem.cpp