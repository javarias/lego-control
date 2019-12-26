test: nxt.o test.o
	g++ -g $? -o $@

%.o: %.cpp
	g++ -g -I../include -c $?
