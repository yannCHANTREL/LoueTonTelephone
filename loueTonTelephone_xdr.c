/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "loueTonTelephone.h"

bool_t
xdr_information (XDR *xdrs, information *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		 if (!xdr_int (xdrs, &objp->id))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->processeur, 15,
			sizeof (char), (xdrproc_t) xdr_char))
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
		 if (!xdr_vector (xdrs, (char *)objp->systemeExploitation, 15,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		 if (!xdr_int (xdrs, &objp->id))
			 return FALSE;
		 if (!xdr_vector (xdrs, (char *)objp->processeur, 15,
			sizeof (char), (xdrproc_t) xdr_char))
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
		 if (!xdr_vector (xdrs, (char *)objp->systemeExploitation, 15,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->processeur, 15,
		sizeof (char), (xdrproc_t) xdr_char))
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
	 if (!xdr_vector (xdrs, (char *)objp->systemeExploitation, 15,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_telephone (XDR *xdrs, telephone *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->appareil, 15,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->prix))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idInfo))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_livraison (XDR *xdrs, livraison *objp)
{
	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->id))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->idClient))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->idTel))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->enCours))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->id);
			IXDR_PUT_LONG(buf, objp->idClient);
			IXDR_PUT_LONG(buf, objp->idTel);
			IXDR_PUT_LONG(buf, objp->enCours);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->id))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->idClient))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->idTel))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->enCours))
				 return FALSE;
		} else {
			objp->id = IXDR_GET_LONG(buf);
			objp->idClient = IXDR_GET_LONG(buf);
			objp->idTel = IXDR_GET_LONG(buf);
			objp->enCours = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idClient))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idTel))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->enCours))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_assurance (XDR *xdrs, assurance *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->duree))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->prix))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->modePaiement))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_location (XDR *xdrs, location *objp)
{
	register int32_t *buf;

	int i;

	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->id))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->idClient))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->idTel))
				 return FALSE;

		} else {
		IXDR_PUT_LONG(buf, objp->id);
		IXDR_PUT_LONG(buf, objp->idClient);
		IXDR_PUT_LONG(buf, objp->idTel);
		}
		 if (!xdr_vector (xdrs, (char *)objp->date, 15,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->enCours))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->idAssu))
			 return FALSE;
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 3 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->id))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->idClient))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->idTel))
				 return FALSE;

		} else {
		objp->id = IXDR_GET_LONG(buf);
		objp->idClient = IXDR_GET_LONG(buf);
		objp->idTel = IXDR_GET_LONG(buf);
		}
		 if (!xdr_vector (xdrs, (char *)objp->date, 15,
			sizeof (char), (xdrproc_t) xdr_char))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->enCours))
			 return FALSE;
		 if (!xdr_int (xdrs, &objp->idAssu))
			 return FALSE;
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idClient))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idTel))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->date, 15,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->enCours))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idAssu))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_client (XDR *xdrs, client *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->id))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->nom, 15,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->adresse, 15,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_enregistrerClientParam (XDR *xdrs, enregistrerClientParam *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->idClient))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->nom, 15,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->adresse, 15,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_majInformationClientParam (XDR *xdrs, majInformationClientParam *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->idClient))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->nom, 15,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->adresse, 15,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_effectuerLocationParam (XDR *xdrs, effectuerLocationParam *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->idTel))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idClient))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idAssu))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_annulerLocationParam (XDR *xdrs, annulerLocationParam *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->idLoc))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idClient))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_modifierLocationParam (XDR *xdrs, modifierLocationParam *objp)
{
	register int32_t *buf;


	if (xdrs->x_op == XDR_ENCODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->idLoc))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->idTel))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->idClient))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->idAssu))
				 return FALSE;
		} else {
			IXDR_PUT_LONG(buf, objp->idLoc);
			IXDR_PUT_LONG(buf, objp->idTel);
			IXDR_PUT_LONG(buf, objp->idClient);
			IXDR_PUT_LONG(buf, objp->idAssu);
		}
		return TRUE;
	} else if (xdrs->x_op == XDR_DECODE) {
		buf = XDR_INLINE (xdrs, 4 * BYTES_PER_XDR_UNIT);
		if (buf == NULL) {
			 if (!xdr_int (xdrs, &objp->idLoc))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->idTel))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->idClient))
				 return FALSE;
			 if (!xdr_int (xdrs, &objp->idAssu))
				 return FALSE;
		} else {
			objp->idLoc = IXDR_GET_LONG(buf);
			objp->idTel = IXDR_GET_LONG(buf);
			objp->idClient = IXDR_GET_LONG(buf);
			objp->idAssu = IXDR_GET_LONG(buf);
		}
	 return TRUE;
	}

	 if (!xdr_int (xdrs, &objp->idLoc))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idTel))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idClient))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idAssu))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_programmerLivraisonParam (XDR *xdrs, programmerLivraisonParam *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->idClient))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idTel))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_annulerLivraisonParam (XDR *xdrs, annulerLivraisonParam *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->idLiv))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idClient))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_modifierLivraisonParam (XDR *xdrs, modifierLivraisonParam *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->idClient))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idTel))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->idLiv))
		 return FALSE;
	return TRUE;
}
