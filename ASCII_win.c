#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	int ch;
	puts("ASCII code test\nPress \'c\' to clear the screen, \'q\' to exit.");
	do{
		ch = getch();
		switch(ch){
		case   7:	puts("The ASCII code of [Alarm] is 7.");								break;
		case   8:	puts("The ASCII code of [Backspace] / [Ctrl+H] / [Ctrl+h] is 8.");		break;
		case   9:	puts("The ASCII code of [Tab] / [Ctrl+I] / [Ctrl+i] is 9.");			break;
		case  10:	puts("The ASCII code of [Ctrl+Enter] / [Ctrl+j] / [Ctrl+J] is 10.");	break;
		case  13:	puts("The ASCII code of [Enter] / [Ctrl+M] / [Ctrl+m] is 13.");			break;

		case -32:
		case 127:
		case 224:
		case   0:
			printf("The ASCII code is %d %d.\n", ch, getch());
			break;
		case 'c':
			printf("The ASCII code of \'c\' is 99.\nPress any key to clear the screen. . .");
			ch = getch();
			if(ch == 0 || ch ==-32)	getch();
			system("cls");
			puts("ASCII code test\nPress \'c\' to clear the screen, \'q\' to exit.");
			break;

		default :
			if(ch < 32 )
				printf("The ASCII code is %d.\n", ch);
			else
				printf("The ASCII code of \'%c\' is %d.\n", ch, ch);
			break;
		}
	}while(ch!='q');

	printf("Press any key to exit. . .");
	getch();
	putchar('\n');
	return 0;
}

