#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc,char **argv) {

	int pid=0; // lapsen pid tallentaan tähän. Jos arvo on nolla, lasta ei ole
	char c; // tallenna character 's', 'k' tai 'q' tähän.

	do {
		c = getchar();
		// jos c = "s" fork!
		// jos pid == 0 lapsi printtaa printf:llä tekstin ja nukkuu 
		// sekunnin. Tämä loopissa kunnes lapsi tapetaan 
		// ns. ikuinen loop. Muista tallentaa 
		// jos c = "k" ja pid > 0, niin kill(pid,SIGKILL) ja wait(). 
		// Muista myös pid = 0, kun lapsi on kuollut.
	} while (c != "q");
	
	// tarkasta onko lapsi hengissä, jos on niin kill(pid,SIGKILL) ja 
	// wait ja sitten return 0;
}