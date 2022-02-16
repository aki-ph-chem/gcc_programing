f=aa

${f} : ${f}.c
	gcc -Wall  $< -o $@

for_gdb : ${f}.c
	gcc -Wall -g $< -o $@

clean : 
	rm -f ./${f}

run :
	./${f}	

.PHONY : clean for_gdb 
