TEX = xelatex

SLIDES_SRC := $(shell find . -name "*.tex")

all: slides

slides: $(SLIDES_SRC)

	$(TEX) -shell-escape $(SLIDES_SRC)	# first iteration
	$(TEX) -shell-escape $(SLIDES_SRC)  # second iteration	

clean:	

	@-rm -rf *.aux *.log *.nav *. *.out *.pdf *.snm *.toc *.vrb
	@-rm -rf _* 
