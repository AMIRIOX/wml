a.out: main.cpp globalsys.cpp common.cpp dataProcessor.cpp reflex.cpp
	g++ main.cpp globalsys.cpp common.cpp dataProcessor.cpp reflex.cpp
clean:
	sudo rm -r /disk02/wmldata/wml
exe:
	sudo ./a.out
