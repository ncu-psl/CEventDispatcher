# Tool invocations
CC=gcc
YACC=yacc
LEX=lex
SRC=src
ODIR=output

CFLAGS=-I$(SRC) -I$(ODIR)
LIBS=

package: calc.o
	@echo 'Building: $@'
	@ar -rcs $(ODIR)/libcalc.a $(ODIR)/calc.o $(ODIR)/calc.tab.o

calc.o:
	@echo 'Building: $@'
	@mkdir -p $(ODIR)
	@$(YACC) -v -db $(ODIR)/calc $(SRC)/calc.y
	@$(LEX) -o $(ODIR)/calc.c $(SRC)/calc.l
	@$(CC) $(ODIR)/calc.tab.c $(CFLAGS) $(LIBS) -c -o $(ODIR)/calc.tab.o
	@$(CC) $(ODIR)/calc.c $(CFLAGS) $(LIBS) -c -o $(ODIR)/calc.o

main.exe: calc.o package
	@echo 'Building: $@'
	@$(CC) $(SRC)/main.c $(CFLAGS) $(LIBS) -o $(ODIR)/main.exe $(ODIR)/libcalc.a

clean:
	@echo 'Removing all binaries'
	@rm -r $(ODIR)/*