/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _LOUETONTELEPHONE_H_RPCGEN
#define _LOUETONTELEPHONE_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct livraison {
	char *nom;
	char *adresse;
	telephone tel;
};
typedef struct livraison livraison;

struct information {
	char *processeur;
	int ram;
	double tailleEcran;
	int autonomie;
	int memoire;
	int qualiteCamera;
	char *systemeExploitation;
};
typedef struct information information;

struct telephone {
	char *appareil;
	double prix;
	information mesInformations;
};
typedef struct telephone telephone;

struct location {
	int num;
	telephone tel;
	char *date;
	int enCours;
	assurance uneAssurance;
};
typedef struct location location;

struct client {
	char *nom;
	char *adresse;
	struct {
		u_int tabLocation_len;
		location *tabLocation_val;
	} tabLocation;
	int nbLocation;
};
typedef struct client client;

struct assurance {
	int duree;
	double prix;
	int modePaiement;
};
typedef struct assurance assurance;

struct enregistrerClientParam {
	char *nom;
	char *adresse;
};
typedef struct enregistrerClientParam enregistrerClientParam;

struct majInformationClientParam {
	char *ancienNom;
	char *nom;
	char *adresse;
};
typedef struct majInformationClientParam majInformationClientParam;

struct effectuerLocationParam {
	telephone tel;
	char *nom;
	int nbLocation;
	assurance uneAssurance;
};
typedef struct effectuerLocationParam effectuerLocationParam;

struct annulerLocationParam {
	int numLocation;
	char *nom;
};
typedef struct annulerLocationParam annulerLocationParam;

struct modifierLocationParam {
	telephone tel;
	char *nom;
	int num;
	assurance uneAssurance;
};
typedef struct modifierLocationParam modifierLocationParam;

struct programmerLivraisonParam {
	char *nom;
	char *adresse;
	telephone tel;
};
typedef struct programmerLivraisonParam programmerLivraisonParam;

#define LOUETONTEL_PROG 0x20000001
#define LOUETONTEL_VERSION_1 1

#if defined(__STDC__) || defined(__cplusplus)
#define allumer_application 1
extern  void * allumer_application_1(void *, CLIENT *);
extern  void * allumer_application_1_svc(void *, struct svc_req *);
#define enregistrer_client 2
extern  client * enregistrer_client_1(enregistrerClientParam *, CLIENT *);
extern  client * enregistrer_client_1_svc(enregistrerClientParam *, struct svc_req *);
#define maj_information_client 3
extern  client * maj_information_client_1(majInformationClientParam *, CLIENT *);
extern  client * maj_information_client_1_svc(majInformationClientParam *, struct svc_req *);
#define effectuer_location 4
extern  location * effectuer_location_1(effectuerLocationParam *, CLIENT *);
extern  location * effectuer_location_1_svc(effectuerLocationParam *, struct svc_req *);
#define annuler_location 5
extern  void * annuler_location_1(annulerLocationParam *, CLIENT *);
extern  void * annuler_location_1_svc(annulerLocationParam *, struct svc_req *);
#define afficher_nb_location 6
extern  void * afficher_nb_location_1(client *, CLIENT *);
extern  void * afficher_nb_location_1_svc(client *, struct svc_req *);
#define afficher_location 7
extern  void * afficher_location_1(client *, CLIENT *);
extern  void * afficher_location_1_svc(client *, struct svc_req *);
#define modifier_location 8
extern  location * modifier_location_1(modifierLocationParam *, CLIENT *);
extern  location * modifier_location_1_svc(modifierLocationParam *, struct svc_req *);
#define effectuer_assurance 9
extern  assurance * effectuer_assurance_1(int *, CLIENT *);
extern  assurance * effectuer_assurance_1_svc(int *, struct svc_req *);
#define afficher_type_assurance 10
extern  void * afficher_type_assurance_1(void *, CLIENT *);
extern  void * afficher_type_assurance_1_svc(void *, struct svc_req *);
#define afficher_garantie 11
extern  void * afficher_garantie_1(assurance *, CLIENT *);
extern  void * afficher_garantie_1_svc(assurance *, struct svc_req *);
#define afficher_liste_telephone 12
extern  void * afficher_liste_telephone_1(void *, CLIENT *);
extern  void * afficher_liste_telephone_1_svc(void *, struct svc_req *);
#define choisir_son_telephone 13
extern  telephone * choisir_son_telephone_1(int *, CLIENT *);
extern  telephone * choisir_son_telephone_1_svc(int *, struct svc_req *);
#define afficher_information_telephone 14
extern  void * afficher_information_telephone_1(int *, CLIENT *);
extern  void * afficher_information_telephone_1_svc(int *, struct svc_req *);
#define programmer_livraison 15
extern  livraison * programmer_livraison_1(programmerLivraisonParam *, CLIENT *);
extern  livraison * programmer_livraison_1_svc(programmerLivraisonParam *, struct svc_req *);
#define annuler_livraison 16
extern  void * annuler_livraison_1(livraison *, CLIENT *);
extern  void * annuler_livraison_1_svc(livraison *, struct svc_req *);
extern int louetontel_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define allumer_application 1
extern  void * allumer_application_1();
extern  void * allumer_application_1_svc();
#define enregistrer_client 2
extern  client * enregistrer_client_1();
extern  client * enregistrer_client_1_svc();
#define maj_information_client 3
extern  client * maj_information_client_1();
extern  client * maj_information_client_1_svc();
#define effectuer_location 4
extern  location * effectuer_location_1();
extern  location * effectuer_location_1_svc();
#define annuler_location 5
extern  void * annuler_location_1();
extern  void * annuler_location_1_svc();
#define afficher_nb_location 6
extern  void * afficher_nb_location_1();
extern  void * afficher_nb_location_1_svc();
#define afficher_location 7
extern  void * afficher_location_1();
extern  void * afficher_location_1_svc();
#define modifier_location 8
extern  location * modifier_location_1();
extern  location * modifier_location_1_svc();
#define effectuer_assurance 9
extern  assurance * effectuer_assurance_1();
extern  assurance * effectuer_assurance_1_svc();
#define afficher_type_assurance 10
extern  void * afficher_type_assurance_1();
extern  void * afficher_type_assurance_1_svc();
#define afficher_garantie 11
extern  void * afficher_garantie_1();
extern  void * afficher_garantie_1_svc();
#define afficher_liste_telephone 12
extern  void * afficher_liste_telephone_1();
extern  void * afficher_liste_telephone_1_svc();
#define choisir_son_telephone 13
extern  telephone * choisir_son_telephone_1();
extern  telephone * choisir_son_telephone_1_svc();
#define afficher_information_telephone 14
extern  void * afficher_information_telephone_1();
extern  void * afficher_information_telephone_1_svc();
#define programmer_livraison 15
extern  livraison * programmer_livraison_1();
extern  livraison * programmer_livraison_1_svc();
#define annuler_livraison 16
extern  void * annuler_livraison_1();
extern  void * annuler_livraison_1_svc();
extern int louetontel_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_livraison (XDR *, livraison*);
extern  bool_t xdr_information (XDR *, information*);
extern  bool_t xdr_telephone (XDR *, telephone*);
extern  bool_t xdr_location (XDR *, location*);
extern  bool_t xdr_client (XDR *, client*);
extern  bool_t xdr_assurance (XDR *, assurance*);
extern  bool_t xdr_enregistrerClientParam (XDR *, enregistrerClientParam*);
extern  bool_t xdr_majInformationClientParam (XDR *, majInformationClientParam*);
extern  bool_t xdr_effectuerLocationParam (XDR *, effectuerLocationParam*);
extern  bool_t xdr_annulerLocationParam (XDR *, annulerLocationParam*);
extern  bool_t xdr_modifierLocationParam (XDR *, modifierLocationParam*);
extern  bool_t xdr_programmerLivraisonParam (XDR *, programmerLivraisonParam*);

#else /* K&R C */
extern bool_t xdr_livraison ();
extern bool_t xdr_information ();
extern bool_t xdr_telephone ();
extern bool_t xdr_location ();
extern bool_t xdr_client ();
extern bool_t xdr_assurance ();
extern bool_t xdr_enregistrerClientParam ();
extern bool_t xdr_majInformationClientParam ();
extern bool_t xdr_effectuerLocationParam ();
extern bool_t xdr_annulerLocationParam ();
extern bool_t xdr_modifierLocationParam ();
extern bool_t xdr_programmerLivraisonParam ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_LOUETONTELEPHONE_H_RPCGEN */
