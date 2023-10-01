1.asio-1.28.0 == boost-1.82.0
2.https://think-async.com/Asio/#
3.Only need include dir content : asio-1.28.0/include/* copy to cppchk/,then, include/asio.hpp copy to cppchk/asio/
4.Suggest(./,exist cppdk dir): #include <cppdk/asio/asio.hpp> && g++ -g -std=c++11 main.cpp -I./ -I./cppdk/ -lpthread
5.Allow(./,exist cppdk dir): #include <asio.hpp> && g++ -g -std=c++11 main.cpp -I./cppdk/asio -lpthread

