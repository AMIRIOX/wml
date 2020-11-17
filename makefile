a.out: main.cpp globalsys.cpp common.cpp dataProcessor.cpp
	g++ main.cpp globalsys.cpp common.cpp dataProcessor.cpp
clean:
	sudo rm -r /disk02/wmldata/wml
exe:
	sudo ./a.out
