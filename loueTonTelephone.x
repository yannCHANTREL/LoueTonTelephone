struct livraison {char * nom; char * adresse; telephone tel;};
struct information {char * processeur; int ram; double tailleEcran; int autonomie; int memoire; int qualiteCamera; char * systemeExploitation;};
struct telephone {char * appareil; double prix; information mesInformations;};
struct location {int num; telephone tel; char * date; int enCours; assurance uneAssurance;};
struct client {char * nom; char * adresse; location tabLocation<>; int nbLocation;};
struct assurance {int duree; double prix; int modePaiement;};

struct enregistrerClientParam {char * nom; char * adresse;};
struct majInformationClientParam {char * ancienNom; char * nom; char * adresse;};
struct effectuerLocationParam {telephone tel; char * nom; int nbLocation; assurance uneAssurance;};
struct annulerLocationParam {int numLocation; char * nom;};
struct modifierLocationParam {telephone tel; char * nom; int num; assurance uneAssurance;};
struct programmerLivraisonParam {char * nom; char * adresse; telephone tel;};

program LOUETONTEL_PROG {
	version LOUETONTEL_VERSION_1 {
		/* Initialisation de l'application */
		void allumer_application() = 1;
	
		/* Gestion client */
		client enregistrer_client(enregistrerClientParam) = 2;
		client maj_information_client(majInformationClientParam) = 3;
		
		/* Gestion des locations */
		location effectuer_location(effectuerLocationParam) = 4;
		void annuler_location(annulerLocationParam) = 5;
		void afficher_nb_location(client) = 6;
		void afficher_location(client) = 7;
		location modifier_location(modifierLocationParam) = 8;
		
		/* Gestion des assurances */
		assurance effectuer_assurance(int) = 9;
		void afficher_type_assurance() = 10;
		void afficher_garantie(assurance) = 11;
		
		/* Gestion des mobiles */
		void afficher_liste_telephone() = 12;
		telephone choisir_son_telephone(int) = 13;
		void afficher_information_telephone(int) = 14;
		
		/* Gestion des livraisons */
		livraison programmer_livraison(programmerLivraisonParam) = 15;
		void annuler_livraison(livraison) = 16;
	} = 1;
} = 0x20000001;
