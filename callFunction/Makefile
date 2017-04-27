
C_SRC=main.c sub.c
C_EXE=c.exe
CPP_SRC=main.cpp sub.cpp
CPP_EXE=cpp.exe

all:$(C_EXE) $(CPP_EXE)

$(C_EXE):$(C_SRC)
	gcc -o $@ $(C_SRC)

$(CPP_EXE):$(CPP_SRC)
	g++ -o $@ $(CPP_SRC)

clean:
	-rm $(C_EXE) $(CPP_EXE)
