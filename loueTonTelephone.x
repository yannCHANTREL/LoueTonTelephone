struct livraison {char * adresse; char * dateCommande;};
struct telephone {char * appareil; double prix;};
struct location {int num; telephone tel; char * date; int enCours; assurance uneAssurance;};
struct client {char * nom; char * adresse; location tabLocation<>; int nbLocation;};
struct assurance {int duree; double prix; int modePaiement;};

struct enregistrerClientParam {char * nom; char * adresse;};
struct majInformationClientParam {char * ancienNom; char * nom; char * adresse;};
struct effectuerLocationParam {telephone tel; char * nom; int nbLocation; assurance uneAssurance;};
struct annulerLocationParam {int numLocation; char * nom;};
struct programmerLivraisonParam {char * nom; char * adresse; telephone tel;};

program LOUETONTEL_PROG {
	version LOUETONTEL_VERSION_1{
		/*Gestion client*/
		client enregistrer_client(enregistrerClientParam) = 1;
		client maj_information_client(majInformationClientParam) = 2;
		
		/*Gestion des locations*/
		location effectuer_location(effectuerLocationParam) = 3;
		void annuler_location(annulerLocationParam) = 4;
		void afficher_nb_location(client) = 5;
		void afficher_location(client) = 6;
		location modifier_location(telephone) = 7;
		
		/*Gestion des assurances*/
		assurance effectuer_assurance(int) = 8;
		void afficher_type_assurance() = 9;
		void afficher_garantie(assurance) = 10;
		
		/*Gestion des mobiles*/
		void afficher_liste_telephone() = 11;
		
		/*Gestion des livraisons*/
		livraison programmer_livraison(programmerLivraisonParam) = 12;
		void annuler_livraison(livraison) = 13;
	} = 1;
} = 0x20000001;
