f=main

${f}.pdf : ${f}.dvi
	dvipdfmx $<

${f}.dvi : ${f}.tex
	platex $<

clean :
	rm -rf ./${f}.aux ./${f}.dvi ./${f}.log ./${f}.pdf

.PHONY : clean
