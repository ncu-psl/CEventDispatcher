CC=gcc
SRC=SRC
ODIR=output

CFLAGS= -I$(SRC) -I$(ODIR) -I./src/expression/src -I./src/expression/output
LIBS= ./src/expression/output/libcalc.a

main: DFH.o
	@echo 'Building: $@'
	@$(CC) $(SRC)/main.c $(ODIR)/DFN.o $(CFLAGS) $(LIBS) -o $(ODIR)/main.exe

DFH.o:
	@echo 'Building: $@'
	@$(CC) $(SRC)/DFN.c -c -o $(ODIR)/DFN.o

clean:
	@echo 'Removing all binaries'
	@rm -rf $(ODIR)/*.exe
	@rm -rf $(ODIR)/*.o