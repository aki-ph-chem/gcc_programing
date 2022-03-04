f=httpd

${f}:${f}.c
	gcc -Wall $< -o $@ 

clean :
	rm ./${f}

run :
	./${f} .

.PHONY : clean run 
