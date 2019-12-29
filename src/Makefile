all: test move stop

test: test.o libnxt.so
	g++ $(filter %.o, $?) -o $@ -L. -lbluetooth -lnxt

move: move.o libnxt.so
	g++ $(filter %.o, $?) -o $@ -L. -lbluetooth -lnxt

stop: stop.o libnxt.so
	g++ $(filter %.o, $?) -o $@ -L. -lbluetooth -lnxt

libnxt.so: nxt.o bt-conn.o antenna.o
	g++ -shared $? -o $@  -lbluetooth

%.o: %.cpp %.h
	g++ -std=c++11 -g -fPIC -I../include -c $?


.PHONY: clean
clean:
	rm -rf test move stop *.o *.so
