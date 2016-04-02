echo_client:echo_client.o unixnet.o
	g++ echo_client.o unixnet.o -o echo_client

echo_client.o:client_echo.cpp unixnet.h
	g++ -c client_echo.cpp -o echo_client.o

unixnet.o:unixnet.cpp unixnet.h
	g++ -c unixnet.cpp -o unixnet.o

clean:
	rm -rf *.o echo_client

