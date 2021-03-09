/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "loueTonTelephone.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
louetontel_prog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		enregistrerClientParam enregistrer_client_1_arg;
		majInformationClientParam maj_information_client_1_arg;
		effectuerLocationParam effectuer_location_1_arg;
		annulerLocationParam annuler_location_1_arg;
		client afficher_nb_location_1_arg;
		client afficher_location_1_arg;
		telephone modifier_location_1_arg;
		assurance afficher_garantie_1_arg;
		programmerLivraisonParam programmer_livraison_1_arg;
		livraison annuler_livraison_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case enregistrer_client:
		_xdr_argument = (xdrproc_t) xdr_enregistrerClientParam;
		_xdr_result = (xdrproc_t) xdr_client;
		local = (char *(*)(char *, struct svc_req *)) enregistrer_client_1_svc;
		break;

	case maj_information_client:
		_xdr_argument = (xdrproc_t) xdr_majInformationClientParam;
		_xdr_result = (xdrproc_t) xdr_client;
		local = (char *(*)(char *, struct svc_req *)) maj_information_client_1_svc;
		break;

	case effectuer_location:
		_xdr_argument = (xdrproc_t) xdr_effectuerLocationParam;
		_xdr_result = (xdrproc_t) xdr_location;
		local = (char *(*)(char *, struct svc_req *)) effectuer_location_1_svc;
		break;

	case annuler_location:
		_xdr_argument = (xdrproc_t) xdr_annulerLocationParam;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) annuler_location_1_svc;
		break;

	case afficher_nb_location:
		_xdr_argument = (xdrproc_t) xdr_client;
		_xdr_result = (xdrproc_t) xdr_char;
		local = (char *(*)(char *, struct svc_req *)) afficher_nb_location_1_svc;
		break;

	case afficher_location:
		_xdr_argument = (xdrproc_t) xdr_client;
		_xdr_result = (xdrproc_t) xdr_char;
		local = (char *(*)(char *, struct svc_req *)) afficher_location_1_svc;
		break;

	case modifier_location:
		_xdr_argument = (xdrproc_t) xdr_telephone;
		_xdr_result = (xdrproc_t) xdr_location;
		local = (char *(*)(char *, struct svc_req *)) modifier_location_1_svc;
		break;

	case afficher_type_assurance:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_char;
		local = (char *(*)(char *, struct svc_req *)) afficher_type_assurance_1_svc;
		break;

	case afficher_garantie:
		_xdr_argument = (xdrproc_t) xdr_assurance;
		_xdr_result = (xdrproc_t) xdr_char;
		local = (char *(*)(char *, struct svc_req *)) afficher_garantie_1_svc;
		break;

	case afficher_liste_telephone:
		_xdr_argument = (xdrproc_t) xdr_void;
		_xdr_result = (xdrproc_t) xdr_char;
		local = (char *(*)(char *, struct svc_req *)) afficher_liste_telephone_1_svc;
		break;

	case programmer_livraison:
		_xdr_argument = (xdrproc_t) xdr_programmerLivraisonParam;
		_xdr_result = (xdrproc_t) xdr_livraison;
		local = (char *(*)(char *, struct svc_req *)) programmer_livraison_1_svc;
		break;

	case annuler_livraison:
		_xdr_argument = (xdrproc_t) xdr_livraison;
		_xdr_result = (xdrproc_t) xdr_void;
		local = (char *(*)(char *, struct svc_req *)) annuler_livraison_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (LOUETONTEL_PROG, LOUETONTEL_VERSION_1);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, LOUETONTEL_PROG, LOUETONTEL_VERSION_1, louetontel_prog_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (LOUETONTEL_PROG, LOUETONTEL_VERSION_1, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, LOUETONTEL_PROG, LOUETONTEL_VERSION_1, louetontel_prog_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (LOUETONTEL_PROG, LOUETONTEL_VERSION_1, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}