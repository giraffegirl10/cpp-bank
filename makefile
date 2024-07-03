proj3:
	g++ -c -Wall Project3.cpp
	g++ -c -Wall Account.cpp
	g++ -o proj3 Project3.o Account.o

clean:
	rm *.o proj3
