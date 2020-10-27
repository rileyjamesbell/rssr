/*
 * Program to output lines from files at an interval through ncurses.
 * Part of RSSR
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <strings.h>

int main(int argc, char *argv[]){
	unsigned int ms=200000;//Microseconds
	if(getenv("RSSRMS")&&atoi(getenv("RSSRMS")))
		ms=atoi(getenv("RSSRMS"));//Override with environment variable if set
	
	int lm=25000;//Length multiplier (adds the length of the string*lm to ms)
	if(getenv("RSSRLM")&&atoi(getenv("RSSRLM")))
		lm=atoi(getenv("RSSRLM"));
	
	char filen[]="/dev/stdin"; //File to read from
	unsigned short mwl=1909; //max word length

	char ch;
	if(argc){
		while(--argc){
			if(argv[argc][0]=='-'){
				i=0;
				while((ch=argv[argc][++i])!='\0'){//For each character in each arguement
					switch(ch){
						case 'h':
							printf("\
%s\n\n\
USAGE: %s [OPTION] [FILE]\n\n\
OPTIONS:\n\
  -f <file>   File to read (assumes \"/dev/stdin\" if none are given)\n\
  -h          Show this help message\n\
  -l <ms>     Added delay for each character in the line (You can set a default\
 by setting the environment variable \"RSSRLM\"\n\
  -M <length> Override max word length\n\
  -m <ms>     Delay between each line in microseconds (You can set a default by\
 setting the environment variable \"RSSRMS\")\n\
",argv[0],argv[0]);
							return 0;
							break;
						case 'm':
							ms=atoi(argv[argc+1]);
							break;
						case 'f':
							filen=argv[argc+1];
							break;
						case 'M':
							mwl=atoi(argv[argc+1]);
							break;
						default:
							break;
					}
				}
			}else if(argc==1)
				filen=argv[argc];
		}
	}

	FILE* file=fopen(filen,"r");
	char l[mwl];

	initscr();
	noecho();
	curs_set(FALSE);

	while(fgets(&l,mwl,file)){
		mvprintw(0,0,l);
		refresh();
		usleep(ms+lm*_strlen(l));
	}
	endwin();

	return EXIT_SUCCESS;
}
