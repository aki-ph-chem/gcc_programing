f=head

${f} : ${f}.c
	gcc -Wall $< -o $@

for_gdb : ${f}.c
	gcc -g -Wall $< -o $@



clean : 
	rm -f ./${f} ./gdb

.PHONY : clean
