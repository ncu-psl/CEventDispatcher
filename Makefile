CC=gcc
SRC=SRC
ODIR=output

CFLAGS= -I$(SRC) -I$(ODIR) -I./expression2/src -I./expression2/output
LIBS= ./expression2/output/libcalc.a

main: 
	@echo 'Building: $@'
	@$(CC) $(SRC)/main.c $(CFLAGS) $(LIBS) -o $(ODIR)/main.exe 

clean:
	@echo 'Removing all binaries'
	@rm -r $(ODIR)/*.exe