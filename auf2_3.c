#define _XOPEN_SOURCE
#define _POSIX_C_SOURCE 200112L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <readline/readline.h>


void printmenu();
void clearBuffer();
void printenvlist();
void printenventry();
void addenventry();
void modenventry();
void removeenventry();

extern char **environ;

int main()
{
	int choice;
	
	do
	{

		printmenu();
		scanf("%i[012345]", &choice);
		clearBuffer();
		switch(choice)
		{
			case(1):
				printenvlist();
				printf("\n");
				break;
			case(2):
				printenventry();
				break;
			case(3):
				addenventry();
				break;
			case(4):
				modenventry();
				break;
			case(5):
				removeenventry();
				break;
		}

	} while (choice != 0);	

	printf("Programm beendet\n");
}

void clearBuffer()		// Tastaturpuffer loeschen
{
	char dummy;

	do
		scanf("%c", &dummy);
	while(dummy != '\n');
}

void printmenu()
{
	printf("---------------------\n");
	printf("Environment-List Menu\n");
	printf("---------------------\n\n");
	printf("[1]: Print environment list\n");
	printf("[2]: Print environment entry (getenv)\n");
	printf("[3]: Add environment entry (putenv)\n");
	printf("[4]: Modify environment entry (setenv)\n");
	printf("[5]: Remove environment entry (unsetenv)\n");
	printf("[0]: End\n");

	printf("\nYour choice: ");
}

void printenvlist()
{
	int i = 0;

	while(*(environ+i))
	{
		puts(*(environ+i));
		i++;
	}
}

void printenventry()
{
	int i = 0;
	char *name;
	

	printf("Print environment entry\n");
	printf("Umgebungsvariable: ");
	name = readline(NULL);
	
	while(*(name+i))
	{
		*(name+i) = toupper(*(name+i));
		i++;
	}

	char *env = getenv(name);

	if(env)
		printf("\n%s=%s\n\n", name, env);
	else
		printf("Kein Eintrag vorhanden.\n\n");

	//free(name);


}

void addenventry()
{
	char *name;


	printf("Add environment entry\n");
	printf("Geben sie Ihren Ausdruck ein('NAME=value'): ");
	name = readline(NULL);

	if(putenv(name) == 0)
		printf("Variable wurde erfolgreich hinzugefuegt.\n");
	else
		printf("Variable konnte nicht hinzugefuegt werden.\n");

	//free(name);

}

void modenventry()
{
	int i = 0;
	char *name;
	char *value;

	printf("Modify environment entry\n");
	printf("Umgebungsvariable die geaendert werden soll: ");
	name = readline(NULL);
	
	while(*(name+i))
	{
		*(name+i) = toupper(*(name+i));
		i++;
	}

	char *env = getenv(name);

	if(env)
	{
		printf("Geben sie den Wert fuer %s ein: ", name);
		value = readline(NULL);
		setenv(name, value, 1);
		//free(value);
	}
	else
		fprintf(stderr,"Variable %s existiert nicht!\n", name);

	//free(name);


}

void removeenventry()
{
	int i = 0;
	char *name;

	printf("Remove environment entry\n");
	printf("Umgebungsvariable die geloescht werden soll: ");
	name = readline(NULL);
	
	while(*(name+i))
	{
		*(name+i) = toupper(*(name+i));
		i++;
	}

	if(unsetenv(name) == 0)
	{
		printf("Variable %s wurde geloescht.\n", name);
	}
	else
		printf("Variable %s existiert nicht!\n", name);

	//free(name);
}
