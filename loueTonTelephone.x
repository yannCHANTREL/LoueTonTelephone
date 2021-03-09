struct livraison{char * adresse, char * dateCommande;};
struct telephone{char * appareil; double prix;};
struct location{int num; telephone tel; char * date; int enCours;};
struct client{char * nom; char * adresse; location tabLocation<>;};
struct assurance{char * type; char * garantie; double prix;};

struct enregistrerClientParam{char * nom; char * adress;};
struct majInformationClientParam{client clt; char * nom; char * adresse;};
struct effectuerLocationParam{telephone tel; client clt;};
struct annulerLocationParam{int numLocation, client clt;};
struct programmerLivraisonParam{client clt, telephone tel;};

program LOUETONTEL_PROG{
	version LOUETONTEL_VERSION_1{
		//Gestion client
		client enregistrer_client(enregistrerClientParam);
		client maj_information_client(majInformationClientParam);
		
		//Gestion des locations
		location effectuer_location(effectuerLocationParam);
		void annuler_location(annulerLocationParam);
		char[] afficher_nb_location(client clt);
		char[] afficher_location(client clt);
		location modifier_location(telephone tel);
		
		//Gestion des assurances
		char[] afficher_type_assurance();
		char * afficher_garantie(assurance assur);
		
		//Gestion des mobiles
		char[] afficher_liste_telephone();
		
		//Gestion des livraisons
		livraison programmer_livraison(programmerLivraisonParam);
		void annuler_livraison(livraison);
	} = 1;
} = 0x20000001;
