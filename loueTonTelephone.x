struct information {char processeur[256]; int ram; double tailleEcran; int autonomie; int memoire; int qualiteCamera; char systemeExploitation[256];};
struct telephone {char appareil[256]; double prix; information mesInformations;};
struct livraison {char nom[256]; char adresse[256]; telephone tel; int enCours;};
struct assurance {int duree; double prix; int modePaiement;};
struct location {int num; telephone tel; char date[256]; int enCours; assurance uneAssurance;};
struct client {char nom[256]; char adresse[256]; location tabLocation[10]; int nbLocation; livraison tabLivraison[10]; int nbLivraison;};

struct enregistrerClientParam {char nom[256]; char adresse[256];};
struct majInformationClientParam {char ancienNom[256]; char nom[256]; char adresse[256];};
struct effectuerLocationParam {telephone tel; char nom[256]; int nbLocation; assurance uneAssurance;};
struct annulerLocationParam {int numLocation; char nom[256];};
struct modifierLocationParam {telephone tel; char nom[256]; int num; assurance uneAssurance;};
struct programmerLivraisonParam {char nom[256]; char adresse[256]; int nbLivraison; telephone tel;};
struct annulerLivraisonParam {int numLivraison; char nom[256];};
struct modifierLivraisonParam {char nom[256]; char adresse[256]; telephone tel; int numLivraison;};

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
		void annuler_livraison(annulerLivraisonParam) = 16;
		livraison modifier_livraison(modifierLivraisonParam) = 17;
	} = 1;
} = 0x20000001;
