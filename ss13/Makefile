#f=return_func_ptr
f=return_func_ptr_2

${f} : ${f}.c
	gcc -Wall $< -o $@

clean :
	rm ${f}

run :
	./${f}

.PHONY : clean run
