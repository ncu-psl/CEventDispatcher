CC=gcc
SRC=src
ODIR=output
EX=example

CFLAGS= -I$(SRC) -I$(ODIR) -I./src/expression/src -I./src/expression/output
LIBS= ./src/expression/output/libcalc.a

all: expr CED.o test
	@echo 'Building: $@'

test: CED.o
	@echo 'Building: $@'
	@$(CC) $(SRC)/test.c $(ODIR)/CED.o $(CFLAGS) $(LIBS) -o $(ODIR)/test.exe

expr:
	@echo 'Building: $@'
	@$(MAKE) -C $(SRC)/expression

CED.o:
	@echo 'Building: $@'
	@$(CC) $(SRC)/CED.c -c -o $(ODIR)/CED.o

ex1:
	@echo 'Building: $@'
	@$(CC) $(EX)/ex1_multikey.c $(ODIR)/CED.o $(CFLAGS) $(LIBS) -o $(ODIR)/ex1_multikey.exe -lncurses


clean:
	@echo 'Removing all binaries'
	@rm -rf $(ODIR)/*.exe
	@rm -rf $(ODIR)/*.o