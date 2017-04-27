
C_SRC=main.c
C_EXE=c.exe
CPP_SRC=main.cpp
CPP_EXE=cpp.exe

all:$(C_EXE) $(CPP_EXE)

$(C_EXE):$(C_SRC)
	gcc -o $@ $<

$(CPP_EXE):$(CPP_SRC)
	g++ -o $@ $<

clean:
	-rm $(C_EXE) $(CPP_EXE)
