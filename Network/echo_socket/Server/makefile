echo_server:echo_server.o unixnet.o
	g++ echo_server.o unixnet.o -o echo_server

echo_server.o:server_echo.cpp unixnet.h
	g++ -c server_echo.cpp -o echo_server.o

unixnet.o:unixnet.cpp unixnet.h
	g++ -c unixnet.cpp -o unixnet.o

clean:
	rm -rf *.o echo_server

