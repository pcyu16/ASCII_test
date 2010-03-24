#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

int kbhit()
{
	struct termios oldt, newt;
	int ch; 
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0); 
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if(ch != EOF){
		ungetc(ch, stdin);
		return 1;
	}   
	return 0;

}

int getch()
{
	while(!kbhit());
	return getchar();
}

int main(void)
{
	int ch;
	puts("ASCII code test\nPress \'c\' to clear the screen, \'q\' to exit.");
	do{
		ch = getch();
		switch(ch){
		case 27:
			printf("The ASCII code is 27");
			while(kbhit()){
				ch = getchar();
				printf(" %d", ch);
			}
			putchar('.');
			putchar('\n');
			break;
		case 'c':
			printf("The ASCII code of \'c\' is 99.\nPress any key to clear the screen. . .");
			getch();
			while(kbhit())	getchar();	/* flush */
			system("clear");
			puts("ASCII code test\nPress \'c\' to clear the screen, \'q\' to exit.");
			break;
		default:
			if(isalpha(ch) || isdigit(ch))
				printf("The ASCII code of \'%c\' is %d.\n", ch, ch);
			else
				printf("The ASCII code is %d.\n", ch);
		}
	}while(ch!='q');
	
	printf("Press any key to exit. . .");
	getch();
	putchar('\n');
	return 0;
}

