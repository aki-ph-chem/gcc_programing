f=ls

${f} : ${f}.c
	gcc -Wall $< -o $@

for_gdb : ${f}.c
	gcc -g -Wall $< -o $@

run : 
	./${f}

clean : 
	rm -f ./${f} ./gdb

.PHONY : clean run
