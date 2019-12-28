all: test move stop

test: test.o libnxt.so
	g++ -g $? -o $@ -L. -lbluetooth -lnxt

move: move.o libnxt.so
	g++ -g $? -o $@ -L. -lbluetooth -lnxt

stop: stop.o libnxt.so
	g++ -g $? -o $@ -L. -lbluetooth -lnxt 

libnxt.so: nxt.o bt-conn.o
	g++ -g -shared $? -o $@  -lbluetooth

%.o: %.cpp
	g++ -g -fPIC -I../include -c $?


.PHONY: clean
clean:
	rm -rf test move stop *.o *.so
