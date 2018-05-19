main.o: main.cpp user.cpp user.hpp transaction.cpp transaction.hpp account.cpp account.hpp
	 clang++ -std=c++11 -c  transaction.cpp
	 clang++ -std=c++11 -c account.cpp
	 clang++ -std=c++11 -c user.cpp
	 clang++ -std=c++11 -c main.cpp
	 clang++ -std=c++11 main.o
	
clean:
	rm -f *.out *.o *.exe
