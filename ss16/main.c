

int main(int argc, char* argv[]){

    if(argc != 2){

	fprintf(stderr,"Usage %s <docroot>\n",argv[0]);
	exit(1);
    }

    install_signal_handler();
    service(stdin,stdout,argv[1]);
    exit(1);
}
