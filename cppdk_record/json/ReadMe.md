1.Version : 1.9.5
2.Homepage:https://github.com/open-source-parsers/jsoncpp
3.PythonDownloadPath:https://www.python.org/
4.execute(python >= 3.4):python amalgamate.py, generate dist folder
5.Only need contents of dist folder
6.copy dist/json folder and dist/jsoncpp.cpp to cppdk/json/detail
7.Myself write json.hpp to wrapper json.h json-forwards.h jsoncpp.cpp
8.Suggest(./,exist cppdk dir): #include <cppdk/json/json.hpp> && g++ -g -std=c++11 main.cpp -I./