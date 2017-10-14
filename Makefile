bin=bin/Ftp-client
libs=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfgui
objs=$(patsubst src/%.cpp,obj/%.o,$(wildcard src/*.cpp))
flags=-g

all: bin obj $(bin)
	./$(bin)

bin:
	mkdir bin

obj:
	mkdir obj

$(bin): $(objs)
	g++ $(objs) $(libs) -o $@

obj/main.o: src/main.cpp obj/ftp_client.o
	g++ -c $(flags) $< -Iinclude/ -o $@

obj/ftp_client.o: src/ftp_client.cpp
	g++ -c $(flags) $< -Iinclude/ -o $@

clear:
	-rm $(bin) $(objs)
