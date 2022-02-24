f_0=main

f_1=http
f_2=log
f_3=memory
f_4=sig

# link 

${f_0} : ${f_0}.o ${f_1}.o ${f_2}.o ${f_3}.o ${f_4}.o
	gcc $^ -o $@

# in main.c
${f_0} : ${f_0}.c
	gcc -I ./include -Wall $< -o $@

${f_1}.o : ./${f_1}.c
	gcc -Wall $< -c

${f_2}.o : ./${f_2}.c
	gcc -Wall $< -c

${f_3}.o : ./${f_3}.c
	gcc -Wall $< -c

${f_4}.o : ./${f_4}.c
	gcc -Wall $< -c


clean :
	seq 0 1 5 | xargs -I@ rm @.o
		

run :
	./{f_0}

.PHONY : run clean
