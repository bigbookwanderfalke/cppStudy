
C_SRC=main.c
C_EXE=c.exe
CPP_SRC=main.cpp
CPP_EXE=cpp.exe
C_LIB=-lpthread

all:$(C_EXE) $(CPP_EXE)

$(C_EXE):$(C_SRC)
	gcc -o $@ $< $(C_LIB)

$(CPP_EXE):$(CPP_SRC)
	g++ -o $@ $< $(C_LIB)

clean:
	-rm $(C_EXE) $(CPP_EXE)
