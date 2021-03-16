/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include <stdio.h> 
#include <time.h> 
#include "loueTonTelephone.h"

#define NBMAX 5

client listeClient[NBMAX];
int nbClient;
location listeLocation[NBMAX];
int nbLocation;
livraison listeLivraison[NBMAX];
int nbLivraison;
assurance listeAssurance[NBMAX];
int nbAssurance;
information listeInformation[3];
telephone listeTelephone[3];

void * allumer_application_1_svc(void *argp, struct svc_req *rqstp) {
	nbClient = 0;
	nbLocation = 0;
	nbLivraison = 0;
	nbAssurance = 0;
	
	information info1;
	info1.id = 1;
	strcpy(info1.processeur,"Helio P60");
	info1.ram = 3;
	info1.tailleEcran = 6.0;
	info1.autonomie = 12;
	info1.memoire = 128;
	info1.qualiteCamera = 8;
	strcpy(info1.systemeExploitation,"Android Nougat");
	
	information info2;
	info2.id = 2;
	strcpy(info2.processeur,"Kirin 970");
	info2.ram = 4;
	info2.tailleEcran = 6.0;
	info2.autonomie = 12;
	info2.memoire = 128;
	info2.qualiteCamera = 10;
	strcpy(info2.systemeExploitation,"Android Oréo");
	
	information info3;
	info3.id = 3;
	strcpy(info3.processeur,"Snapdragon 845");
	info3.ram = 6;
	info3.tailleEcran = 6.4;
	info3.autonomie = 12;
	info3.memoire = 256;
	info3.qualiteCamera = 10;
	strcpy(info3.systemeExploitation,"Android Oréo");
	
	telephone tel1;
	tel1.id = 1;
	strcpy(tel1.appareil,"Galaxy S20 FE");
	tel1.prix = 659.0;
	tel1.idInfo = 1;
	listeTelephone[0] = tel1;
	
	telephone tel2;
	tel2.id = 2;
	strcpy(tel2.appareil,"Galaxy S20");
	tel2.prix = 909.0;
	tel2.idInfo = 2;
	listeTelephone[1] = tel2;
	
	telephone tel3;
	tel3.id = 3;
	strcpy(tel3.appareil,"Galaxy S20+");
	tel3.prix = 1009.0;
	tel3.idInfo = 3;
	listeTelephone[2] = tel3;
	
	printf("allumer_application - L'application est prête à être utilisé\n");
}

int * enregistrer_client_1_svc(enregistrerClientParam *argp, struct svc_req *rqstp) {
	enregistrerClientParam monClient = *argp;
	int idClient = monClient.idClient;
	
	if (idClient > nbClient) {
		// Création du nouveau client	
		client newClient;
		newClient.id = idClient;
		strcpy(newClient.nom,monClient.nom);
		strcpy(newClient.adresse,monClient.adresse);
		// On met a jour les infos
		listeClient[idClient] = newClient;
		nbClient++;
		// On retourne le nouveau client
		printf("enregistrer_client - Le client numéro %d, nommé %s a été crée\n",idClient,newClient.nom);
	}
	return &argp->idClient;
}

void * maj_information_client_1_svc(majInformationClientParam *argp, struct svc_req *rqstp) {
	majInformationClientParam data = *argp;
	if (nbClient >= data.idClient) {
		client unClient = listeClient[data.idClient];
		// On met a jour ses informations
		strcpy(unClient.nom,data.nom);
		strcpy(unClient.adresse,data.adresse);
		// On retourne le client modifié
		printf("maj_information_client - Vous avez modifié le client numéro %d\n",data.idClient);
	}
}

int * effectuer_location_1_svc(effectuerLocationParam *argp, struct svc_req *rqstp) {
	effectuerLocationParam data = *argp;
	static int idLocation;
	idLocation = nbLocation + 1;
	// Création de la nouvelle location
	location newLocation;
	newLocation.id = idLocation;
	newLocation.idClient = data.idClient;
	newLocation.idTel = data.idTel;
	time_t t = time(NULL); // Recupère la date du jour
	// Transforme la date en une chaine de caractères
	strcpy(newLocation.date,ctime(&t));
	newLocation.enCours = 1;
	newLocation.idAssu = data.idAssu;
	// On met a jour les infos
	listeLocation[idLocation] = newLocation;
	nbLocation++;
	
	client unClient = listeClient[data.idClient];
	assurance uneAssurance = listeAssurance[data.idAssu];
	telephone tel = listeTelephone[data.idTel];
	printf("effectuer_location - Le client nommé %s a crée une nouvelle location pour le téléphone nommé %s. Celle-ci prend effet immédiatement. Le téléphone est assuré pendant %d mois\n",unClient.nom,tel.appareil,uneAssurance.duree);
	return &idLocation;
}

void * annuler_location_1_svc(annulerLocationParam *argp, struct svc_req *rqstp) {
	annulerLocationParam data = *argp;
	if (nbLocation >= data.idLoc) {
		client unClient = listeClient[data.idClient];
		int i = data.idLoc;
		while (i < nbLocation) {
			listeLocation[i] = listeLocation[i+1];
			i++;
		}
		location loc;
		listeLocation[i] = loc;
		nbLocation--;
		printf("annuler_location - Le client nommé %s a annulé la location numéro %d\n",unClient.nom,data.idLoc);
	}
}

void * afficher_nb_location_1_svc(int *argp, struct svc_req *rqstp) {
	client monClient = listeClient[*argp];
	int nbLocationEnCours = 0;
	// Recherche du nombre de lacoation en cours pour ce client
	for (int i = 0; i < nbLocation; i++) {
		location locationActuel = listeLocation[i];
		if (locationActuel.idClient == *argp && locationActuel.enCours == 1) {
			nbLocationEnCours++;
		}
	}
	// Affichage du nombre de location en cours pour ce client
	printf("afficher_nb_location - Le client nommé %s a %d location en cours\n",monClient.nom,nbLocationEnCours);
}

void * afficher_location_1_svc(int *argp, struct svc_req *rqstp) {
	client monClient = listeClient[*argp];
	// on affiche chaque location du client
	for (int i = 0; i < nbLocation; i++) {
		location locationActuel = listeLocation[i];
		if (locationActuel.idClient == *argp) {
			telephone tel = listeTelephone[locationActuel.idTel];
			assurance assu = listeAssurance[locationActuel.idAssu];
			// Location en cours ?
			char * enCours = "Non";
			if (locationActuel.enCours == 1) {
				enCours = "Oui";
			}
			// Location avec assurance ?
			char * typeAssurance = "sans assurance";
			if (assu.modePaiement == 1) {
				typeAssurance = "avec assurance (paiement en mensualité)";
			} else if (assu.modePaiement == 2) {
				typeAssurance = "avec assurance (paiement unique)"; 
			}
			printf("afficher_location - Le client nommé %s a la location suviante :\nNuméro : %d - Téléphone : %s - Date de début : %s - En cours : %s - Type d'assurance : %s\n\n",monClient.nom,locationActuel.id,tel.appareil,locationActuel.date,enCours,typeAssurance);
		}
	}	
}

void * modifier_location_1_svc(modifierLocationParam *argp, struct svc_req *rqstp) {
	modifierLocationParam data = *argp;
	if (nbLocation >= data.idLoc) {
		// On crée une nouvelle location
		location newLocation;
		newLocation.id = data.idLoc;
		newLocation.idClient = data.idClient;
		newLocation.idTel = data.idTel;
		time_t t = time(NULL); // Recupère la date du jour
		// Transforme la date en une chaine de caractères
		strcpy(newLocation.date,ctime(&t));
		newLocation.enCours = 1;
		newLocation.idAssu = data.idAssu;
		listeLocation[data.idLoc] = newLocation;
		
		client unClient = listeClient[data.idClient];
		assurance uneAssurance = listeAssurance[data.idAssu];
		telephone tel = listeTelephone[data.idTel];
		printf("modifier_location - Le client nommé %s a modifié la location numéro %d, lui attribuant le téléphone nommé %s. Celle-ci prend effet immédiatement, et ce terminera dans %d\n",unClient.nom,newLocation.id,tel.appareil,uneAssurance.duree);
	}
}

int * effectuer_assurance_1_svc(int *argp, struct svc_req *rqstp) {
	int modePaiement = *argp;
	static int idAssu;
	idAssu = nbAssurance + 1;
	// Création de la nouvelle assurance
	assurance newAssurance;
	newAssurance.id = idAssu;
	newAssurance.modePaiement = modePaiement;
	if (modePaiement == 1) {
		newAssurance.prix = 4.99;
		newAssurance.duree = 24;
		printf("effectuer_assurance - Une nouvelle assurance a été crée, payable en mensualité\n");
	} else if (modePaiement == 2) {
		newAssurance.prix = 89.00;
		newAssurance.duree = 24;
		printf("effectuer_assurance - Une nouvelle assurance a été crée, paiement unique\n");
	} else {
		newAssurance.prix = 0.0;
		newAssurance.duree = 0;
		printf("effectuer_assurance - Assurance non assurée\n");
	}
	// On met a jour les infos
	listeAssurance[idAssu] = newAssurance;
	nbAssurance++;
	return &idAssu;
}

void * afficher_type_assurance_1_svc(void *argp, struct svc_req *rqstp) {
	printf("afficher_type_assurance - Il existe trois types d'assurances :\n - assurance avec paiement mensuel\n - assurance avec paiement unique\n - sans assurance\n");
}

void * afficher_garantie_1_svc(void *argp, struct svc_req *rqstp) {
	printf("afficher_garantie - Prendre une assurance vous octroie une protection contre tout vol ou dommage fait à votre appareil, à condition que celle-ci puissent être justifié. La garantie est valable pendant 24 mois.\n");
}

void * afficher_liste_telephone_1_svc(void *argp, struct svc_req *rqstp) {
	printf("afficher_liste_telephone - Les téléphones disponibles sont les suivants :\n");
	for (int i = 0; i < 3; i++) {
		telephone telActuel = listeTelephone[i];
		printf("mobile numéro %d - Nom : %s - Prix de l'appreil : %f\n",telActuel.id,telActuel.appareil,telActuel.prix);
	}
}

int * choisir_son_telephone_1_svc(int *argp, struct svc_req *rqstp) {
	int idTel = *argp;
	telephone tel = listeTelephone[idTel-1];
	printf("choisir_son_telephone - Vous avez choisi le téléphone numéro %d, nommé %s\n",*argp,tel.appareil);
	return argp;
}

void * afficher_information_telephone_1_svc(int *argp, struct svc_req *rqstp) {
	// On récupère le téléphone
	telephone tel = listeTelephone[*argp];
	information info;
	for (int i = 0; i < 3; i++) {
		information infoActuel = listeInformation[i];
		if (infoActuel.id == tel.idInfo) {
			info = infoActuel;
		}
	}
	printf("afficher_information_telephone - Téléphone numéro %d : Informations générale :\n",*argp);
	// on communique chaque informations du téléphone
	printf("Processeur : %s\n",info.processeur);
	printf("RAM : %d Go\n",info.ram);
	printf("Taille de l'écran : %f pouces\n",info.tailleEcran);
	printf("Autonomie estimé : %d heures\n",info.autonomie);
	printf("Mémoire interne : %d Go\n",info.memoire);
	printf("Résolution de la caméra : %d mégapixels\n",info.qualiteCamera);
	printf("Système d'exploitation : %s\n",info.systemeExploitation);
}

int * programmer_livraison_1_svc(programmerLivraisonParam *argp, struct svc_req *rqstp) {
	programmerLivraisonParam data = *argp;
	static int idLiv;
	idLiv = nbLivraison + 1;
	// Création de la livraison
	livraison newLivraison;
	newLivraison.id = idLiv;
	newLivraison.idClient = data.idClient;
	newLivraison.idTel = data.idTel;
	newLivraison.enCours = 1;
	// On met a jour les infos
	listeLivraison[idLiv] = newLivraison;
	nbLivraison++;
	// Affichage
	client clt = listeClient[data.idClient];
	telephone tel = listeTelephone[data.idTel];
	printf("programmer_livraison - La livraison à bien été crée. Le client nommé %s recevera sont téléphone %s sous 24h, à l'adresse %s\n Merci d'avoir commandé sur LoueTonTelephone !\n",clt.nom,tel.appareil,clt.adresse);
	return &idLiv;
}

void * annuler_livraison_1_svc(annulerLivraisonParam *argp, struct svc_req *rqstp) {
	annulerLivraisonParam data = *argp;
	// On met a jour ses informations
	if (nbLivraison >= data.idLiv) {
		int i = data.idLiv;
		while (i < nbLivraison) {
			listeLivraison[i] = listeLivraison[i+1];
			i++;
		}
		livraison liv;
		listeLivraison[i] = liv;
		nbLivraison--;
		
		// Affichage
		client unClient = listeClient[data.idClient];
		printf("annuler_livraison - Le client numéro %d, nommé %s a annulé la livraison numéro %d\n",data.idClient,unClient.nom,data.idLiv);
	}	
}

void * modifier_livraison_1_svc(modifierLivraisonParam *argp, struct svc_req *rqstp) {
	modifierLivraisonParam data = *argp;
	if (nbLivraison >= data.idLiv) {
		// On crée une nouvelle livraison
		livraison newLivraison;
		newLivraison.id = data.idLiv;
		newLivraison.idClient = data.idClient;
		newLivraison.idTel = data.idTel;
		newLivraison.enCours = 1;
		listeLivraison[data.idLiv] = newLivraison;
	
		client clt = listeClient[data.idClient];
		telephone tel = listeTelephone[data.idTel];
		printf("modifier_livraison - Le client nommé %s a modifié la livraison numéro %d, lui attribuant le téléphone numéro %d, nommé %s. Le téléphone sera livré, sous un délais de 24h maximum, à l'adresse %s.\n",clt.nom,data.idLiv,data.idTel,tel.appareil,clt.adresse);
	}
}