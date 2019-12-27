test: test.o nxt.o bt-conn.o
	g++ -g $? -o $@ -lbluetooth

%.o: %.cpp
	g++ -g -I../include -c $?


.PHONY: clean
clean:
	rm -rf test *.o
