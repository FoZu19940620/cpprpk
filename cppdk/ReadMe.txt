makefile include paths command:
-I ./ $(shell find ./cppdk -maxdepth 1 -type d | tail -n +2 | sed -e 's/^.*$/-I&/')

you probably need pretty makefile include paths command:
-I ./ $(shell find ./cppdk -maxdepth 1 -type d | tail -n +2 | sed -e 's/^.*$/-I&/' | sed -e 's/^.*$/  & \\/' | sed -e '$s/.$//')

g++ include paths command:
-I ./ $(find ./cppdk -maxdepth 1 -type d | tail -n +2 | sed -e 's/^.*$/-I&/')