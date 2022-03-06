f=httpd2

${f}:${f}.c
	gcc -Wall $< -o $@

clean :
	rm ./${f}

usser=aki
port=8082
docroot=./hoge
docroot_fake=./foo


run :
	./${f}  --port=${port} ${docroot} 

debug : 
	./${f} --port=${port} --debug ${docroot} 

debug_f :
	./${f} --port=${port} --debug ${docroot_fake}

.PHONY : clean run debug debug_f
