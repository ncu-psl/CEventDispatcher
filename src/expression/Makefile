# Tool invocations
CC=gcc
YACC=yacc
LEX=lex
SRC=src
ODIR=output

CFLAGS=-I$(SRC) -I$(ODIR)
LIBS=

libcalc.a: calc.o
	@echo 'Building: $@'
	@ar -rcs $(ODIR)/libcalc.a $(ODIR)/calc.o $(ODIR)/calc.tab.o

calc.o:
	@echo 'Building: $@'
	@mkdir -p $(ODIR)
	@$(YACC) -v -db $(ODIR)/calc $(SRC)/calc.y
	@$(LEX) -o $(ODIR)/calc.c $(SRC)/calc.l
	@$(CC) $(ODIR)/calc.tab.c $(CFLAGS) $(LIBS) -c -o $(ODIR)/calc.tab.o
	@$(CC) $(ODIR)/calc.c $(CFLAGS) $(LIBS) -c -o $(ODIR)/calc.o

example: calc.o libcalc.a
	@echo 'Building: $@'
	@$(CC) $(SRC)/example.c $(ODIR)/libcalc.a $(CFLAGS) $(LIBS) -o $(ODIR)/example.exe

clean:
	@echo 'Removing all binaries'
	@rm -rf $(ODIR)/*