bin/programa : src/main.cpp include/Foco.hpp include/EstadoFoco.hpp
	c++ src/main.cpp o- bin/programa -I include

run : bin/programa
	./bin/programa
bin/Memoria : src/memoria.cpp
	c++ src/memoria.cpp -o bin/programa

runMemoria: bin/programa
	./bin/programa