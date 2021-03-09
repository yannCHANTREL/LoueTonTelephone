struct livraison {char * adresse; char * dateCommande;};
struct telephone {char * appareil; double prix;};
struct location {int num; telephone tel; char * date; int enCours;};
struct client {char * nom; char * adresse; location tabLocation<>;};
struct assurance {char * type; char * garantie; double prix;};

struct enregistrerClientParam {char * nom; char * adress;};
struct majInformationClientParam {client clt; char * nom; char * adresse;};
struct effectuerLocationParam {telephone tel; client clt;};
struct annulerLocationParam {int numLocation; client clt;};
struct programmerLivraisonParam {client clt; telephone tel;};

program LOUETONTEL_PROG {
	version LOUETONTEL_VERSION_1{
		/*Gestion client*/
		client enregistrer_client(enregistrerClientParam) = 1;
		client maj_information_client(majInformationClientParam) = 2;
		
		/*Gestion des locations*/
		location effectuer_location(effectuerLocationParam) = 3;
		void annuler_location(annulerLocationParam) = 4;
		char afficher_nb_location(client clt) = 5;
		char afficher_location(client clt) = 6;
		location modifier_location(telephone tel) = 7;
		
		/*Gestion des assurances*/
		char afficher_type_assurance() = 8;
		char afficher_garantie(assurance assur) = 9;
		
		/*Gestion des mobiles*/
		char afficher_liste_telephone() = 10;
		
		/*Gestion des livraisons*/
		livraison programmer_livraison(programmerLivraisonParam) = 11;
		void annuler_livraison(livraison) = 12;
	} = 1;
} = 0x20000001;
