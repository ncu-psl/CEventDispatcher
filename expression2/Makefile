# Tool invocations
CC=cc
YACC=yacc
LEX=lex
SRC=src
ODIR=output

CFLAGS=-I$(SRC) -I$(ODIR)
LIBS=

calc3:
	@echo 'Building example 3: $@'
	@mkdir -p $(ODIR)
	@$(YACC) -db $(ODIR)/calc3 $(SRC)/calc3.y
	@$(LEX) -o $(ODIR)/calc3.c $(SRC)/calc3.l
	@$(CC) $(CFLAGS) $(LIBS) -o $(ODIR)/calc3a $(ODIR)/calc3.c $(SRC)/calc3a.c $(ODIR)/calc3.tab.c

clean:
	@echo 'Removing all binaries'
	@rm -rf $(ODIR)/