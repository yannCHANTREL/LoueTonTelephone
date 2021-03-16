struct information {int id; char processeur[15]; int ram; double tailleEcran; int autonomie; int memoire; int qualiteCamera; char systemeExploitation[15];};

struct telephone {int id; char appareil[15]; double prix; int idInfo;};

struct livraison {int id; int idClient; int idTel; int enCours;};

struct assurance {int id; int duree; double prix; int modePaiement;};

struct location {int id; int idClient; int idTel; char date[15]; int enCours; int idAssu;};

struct client {int id; char nom[15]; char adresse[15];};



struct enregistrerClientParam {int idClient; char nom[15]; char adresse[15];};

struct majInformationClientParam {int idClient; char nom[15]; char adresse[15];};

struct effectuerLocationParam {int idTel; int idClient; int idAssu;};

struct annulerLocationParam {int idLoc; int idClient;};

struct modifierLocationParam {int idLoc; int idTel; int idClient; int idAssu;};

struct programmerLivraisonParam {int idClient; int idTel;};

struct annulerLivraisonParam {int idLiv; int idClient;};

struct modifierLivraisonParam {int idClient; int idTel; int idLiv;};



program LOUETONTEL_PROG {

	version LOUETONTEL_VERSION_1 {

		/* Initialisation de l'application */

		void allumer_application() = 1;

	

		/* Gestion client */

		int enregistrer_client(enregistrerClientParam) = 2;

		void maj_information_client(majInformationClientParam) = 3;

		

		/* Gestion des locations */

		int effectuer_location(effectuerLocationParam) = 4;

		void annuler_location(annulerLocationParam) = 5;

		void afficher_nb_location(int idClient) = 6;

		void afficher_location(int idClient) = 7;

		void modifier_location(modifierLocationParam) = 8;

		

		/* Gestion des assurances */

		int effectuer_assurance(int modePaiement) = 9;

		void afficher_type_assurance() = 10;

		void afficher_garantie() = 11;

		

		/* Gestion des mobiles */

		void afficher_liste_telephone() = 12;

		int choisir_son_telephone(int idTel) = 13;

		void afficher_information_telephone(int idTel) = 14;

		

		/* Gestion des livraisons */

		int programmer_livraison(programmerLivraisonParam) = 15;

		void annuler_livraison(annulerLivraisonParam) = 16;

		void modifier_livraison(modifierLivraisonParam) = 17;

	} = 1;

} = 0x20000001;