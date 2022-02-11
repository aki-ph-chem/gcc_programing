f=head

${f} : ${f}.c
	gcc -Wall $< -o $@

gdb : ${f}.c
	gcc -g -Wall $< -o $@



clean : 
	rm -f ./${f} ./gdb

.PHONY : clean
