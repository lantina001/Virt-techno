#include Shodan.Net.Models;
#include Shodan.Net.Models.Options;
#include <stdio.h>
#include <stdlib.h>
#define MAX_CMN_LEN 100

int main(int argc, char *argv[])
{
	/*Variabelen*/
	char cmd[MAX_CMN_LEN] = "", **p;
	char zoekterm[100];
	int filters;
	int hoeveelgeo;
	char stad[100];
	char land[50]


	if (argc < 2) /*Om te controleren of er een verbinding met de terminal gemaakt kan worden*/
	{
		fprintf(stderr, "Usage: ./program_name terminal_command ...");
		exit(EXIT_FAILURE);
	}
	else
	{
		/*Eerste vraag waarbij de vraag wordt opgeslagen in een variabele*/
		fprintf("Waar bent u naar opzoek op Shodan.io? \n");
		scanf("%s", zoekterm);
		/*Het installeren van shodan in op linux en het doorvoeren van de API key*/
		system("easy_install shodan");
		system("shodan init n3XIOMaUHqf4pVDub6NNuqo4yAJwjzlr");
		system("shodan count microsoft iis 6.0");
		system("shodan myip");
		system("shodan search" + zoekterm);

		/*Geeft een bestand weer met een lijst van gehackte websites*/
		fprintf("Hier volgt een lijst van meest gehackte websites:\n");
		system("shodan download --limit -1 hacked "title:hacked by" \n");
		system("shodan parse --fields title hacked.js.gz");
		system("shodan parse --fields title hacked.json.gz | grep -i "hacked by");
			system("shodan parse --fields title hacked.json.gz | grep -i '"hacked b
				y" | sed -e 's/.*hacked by//i' | sort | uniq -c");
		system("shodan parse --fields title hacked.json.gz | grep -i "hacked b
			y" | sed -e 's/.*hacked by//i' | sort | uniq -c | sort -k1nr -k2d | head -10");
		system("shodan stats --facets telnet.option port:23 ");
		system("shodan stats --facets telnet.option --limit 20  port:23 ");
		system("shodan search port:23 telnet.option:com_port_option ");

		/*Vraagt welke poortnummers de gebruiker wilt weten en slaat het op in een variabele*/
		fprintf("Wilt u poortnummers weten, zo ja? Op hoeveel poortnummers? \n");
		scanf("%d", &filters);

		/*Loop om de filters te laten zien*/
		for (filters = 0; filters <= filters; filters++) {
			Prinf("filter %d" + filters + " is \n")
				system("port" + filters);
		}

		/*Vraag om van hoeveel steden er apparaten getoond moeten worden, met een for loop*/
		fprintf("Van hoeveel steden wilt u informatie over het aantal apparaten?");
		scanf("%d", hoeveelgeo);
		for (hoeveelgeo = 0; hoeveelgeo <= hoeveelgeo; hoeveelgeo++) {

		fprintf("Van welke stad wilt u weten hoeveel apparaten er op shodan.io te zien zijn? \n")
			scanf("%s", &stad);
		system("city");
		fprintf("In welk land ligt de stad?");
		scanf("%s", land);
		system("country");
		fprintf("Het besturingssysteem is \n");
		system("os");
		fprintf("Het ip-adres is \n");
		system("net");
		}
	}
	return 0;
}
