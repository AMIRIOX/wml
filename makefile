a.out: main.cpp globalsys.cpp common.cpp dataProcessor.cpp reflex.cpp timeProcessor.cpp
	g++ main.cpp globalsys.cpp common.cpp dataProcessor.cpp reflex.cpp timeProcessor.cpp
# clean:
#	sudo rm -r /disk02/wmldata/wml
exe:
	sudo ./a.out
install: main.cpp globalsys.cpp common.cpp dataProcessor.cpp reflex.cpp timeProcessor.cpp
	g++ main.cpp globalsys.cpp common.cpp dataProcessor.cpp reflex.cpp timeProcessor.cpp -std=c++20 -o wml
	sudo cp ./wml /disk01/codework/bin/wml
