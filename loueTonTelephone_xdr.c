/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "loueTonTelephone.h"

bool_t
xdr_livraison (XDR *xdrs, livraison *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)&objp->nom, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->adresse, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_telephone (xdrs, &objp->tel))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_information (XDR *xdrs, information *objp)
{
	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_pointer (xdrs, (char **)&objp->processeur, sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->ram))
			 return FALSE;
		 if (!xdr_double (xdrs, &objp->tailleEcran))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->autonomie))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->memoire))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->qualiteCamera))
				 return FALSE;

		} else {
		IXDR_PUT_LONG(buf, objp->autonomie);
		IXDR_PUT_LONG(buf, objp->memoire);
		IXDR_PUT_LONG(buf, objp->qualiteCamera);
		}
		 if (!xdr_pointer (xdrs, (char **)&objp->systemeExploitation, sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_pointer (xdrs, (char **)&objp->processeur, sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->ram))
			 return FALSE;
		 if (!xdr_double (xdrs, &objp->tailleEcran))
			 return FALSE;
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->autonomie))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->memoire))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->qualiteCamera))
				 return FALSE;

		} else {
		objp->autonomie = IXDR_GET_LONG(buf);
		objp->memoire = IXDR_GET_LONG(buf);
		objp->qualiteCamera = IXDR_GET_LONG(buf);
		}
		 if (!xdr_pointer (xdrs, (char **)&objp->systemeExploitation, sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_pointer (xdrs, (char **)&objp->processeur, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->ram))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->tailleEcran))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->autonomie))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->memoire))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->qualiteCamera))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->systemeExploitation, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_telephone (XDR *xdrs, telephone *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)&objp->appareil, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->prix))
		 return FALSE;
	 if (!xdr_information (xdrs, &objp->mesInformations))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_location (XDR *xdrs, location *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->num))
		 return FALSE;
	 if (!xdr_telephone (xdrs, &objp->tel))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->date, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->enCours))
		 return FALSE;
	 if (!xdr_assurance (xdrs, &objp->uneAssurance))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_client (XDR *xdrs, client *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)&objp->nom, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->adresse, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_array (xdrs, (char **)&objp->tabLocation.tabLocation_val, (u_int *) &objp->tabLocation.tabLocation_len, ~0,
		sizeof (location), (xdrproc_t) xdr_location))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->nbLocation))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_assurance (XDR *xdrs, assurance *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->duree))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->prix))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->modePaiement))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_enregistrerClientParam (XDR *xdrs, enregistrerClientParam *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)&objp->nom, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->adresse, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_majInformationClientParam (XDR *xdrs, majInformationClientParam *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)&objp->ancienNom, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->nom, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->adresse, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_effectuerLocationParam (XDR *xdrs, effectuerLocationParam *objp)
{
	register int32_t *buf;

	 if (!xdr_telephone (xdrs, &objp->tel))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->nom, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->nbLocation))
		 return FALSE;
	 if (!xdr_assurance (xdrs, &objp->uneAssurance))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_annulerLocationParam (XDR *xdrs, annulerLocationParam *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->numLocation))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->nom, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_modifierLocationParam (XDR *xdrs, modifierLocationParam *objp)
{
	register int32_t *buf;

	 if (!xdr_telephone (xdrs, &objp->tel))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->nom, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->num))
		 return FALSE;
	 if (!xdr_assurance (xdrs, &objp->uneAssurance))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_programmerLivraisonParam (XDR *xdrs, programmerLivraisonParam *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)&objp->nom, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->adresse, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_telephone (xdrs, &objp->tel))
		 return FALSE;
	return TRUE;
}
