struct information {char processeur[15]; int ram; double tailleEcran; int autonomie; int memoire; int qualiteCamera; char systemeExploitation[15];};
struct telephone {char appareil[15]; double prix; information mesInformations;};
struct livraison {char nom[15]; char adresse[15]; telephone tel; int enCours;};
struct assurance {int duree; double prix; int modePaiement;};
struct location {int num; telephone tel; char date[15]; int enCours; assurance uneAssurance;};
struct client {char nom[15]; char adresse[15];};

struct enregistrerClientParam {char nom[15]; char adresse[15];};
struct majInformationClientParam {char ancienNom[15]; char nom[15]; char adresse[15];};
struct effectuerLocationParam {telephone tel; char nom[15]; int nbLocation; assurance uneAssurance;};
struct annulerLocationParam {int numLocation; char nom[15];};
struct modifierLocationParam {telephone tel; char nom[15]; int num; assurance uneAssurance;};
struct programmerLivraisonParam {char nom[15]; char adresse[15]; int nbLivraison; telephone tel;};
struct annulerLivraisonParam {int numLivraison; char nom[15];};
struct modifierLivraisonParam {char nom[15]; char adresse[15]; telephone tel; int numLivraison;};

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