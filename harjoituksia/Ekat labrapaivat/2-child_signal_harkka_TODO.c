#include <signal.h>
#include <stdio.h>	
#include <sys/types.h>	
#include <unistd.h>	
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
// Aja tarpeeksi monta kertaa, ett‰ p‰‰ohjelma j‰‰ jumiin kun
// children ei mene nollaan. T‰m‰ johtuu siit‰, ett‰ SIGCHLD 
// signaaleja tulee enemm‰n kuin kaksi kerralla. Sek‰ k‰sittelyss‰
// oleva signaali, ett‰ k‰sittelyn aikana blokattu signaali
// on varattu ja kolmas ja siit‰ eteenp‰in signaalit menev‰t "hukkaan",
// jos niit‰ ei ehdit‰ k‰sitell‰ kunnolla.
static int children = 0;

void myHandler(int signum) {
	// TODO: v‰henn‰ globaalia children arvoa yhdell‰.
}

int childact(int nro) {
	// TODO: arvo luku 11-20 v‰lill‰. Printtaa ulos luku aikana, jonka lapsi nukkuu.
	// Nuku arvottu aika. Printtaa ulos ett‰ lapsi kuolee ja sen j‰lkeen exit.
	// Googleta miten C:n random toimii ellei ole tuttu
}	

int main(int argc, char** argv) {
	struct sigaction sa;

	// TODO: Luo sigaction struct ,  alusta mask ja flags kaikki // signaalit ja asenna signal handler SIGCHLD signaalille.
	

	// TODO: Forkkaa 10 lasta, lapset menev‰t childact() funktioon. Kasvata globaalia children arvoa
	// per luotu lapsi (valmiina arvo on 10)

	// TODO: While loopissa kunnes children arvo on taas nolla, nuku, k‰sittele kuollut lapsi wait komennolla, printtaa ulos tiedot lapsesta 
	// Jos lapsia kuolee kolme samalla hetkell‰, niin ohjelman pit‰isi j‰‰d‰ ikuisesti odottelemaamn
}