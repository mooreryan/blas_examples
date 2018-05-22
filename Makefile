CC = gcc
BLAS_FLAGS = -I/home/moorer/include -L/home/moorer/lib -lopenblas -lpthread -lgfortran

ifeq ($(OPT_LEVEL),)
OPT_LEVEL = -O3
endif

CFLAGS = -Wall -g -fopt-info-optimized -O$(OPT_LEVEL)

SRC = src
BIN = bin

sdot:
	$(CC) $(CFLAGS) $(BLAS_FLAGS) -o $(BIN)/$@ $(SRC)/$@.c

test_sdot: sdot
	valgrind $(BIN)/sdot

scopy:
	$(CC) $(CFLAGS) $(BLAS_FLAGS) -o $(BIN)/$@ $(SRC)/$@.c

test_scopy: scopy
	valgrind $(BIN)/scopy

jawn:
	echo -O$(OPT_LEVEL)
