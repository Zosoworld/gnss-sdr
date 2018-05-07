/*
 * Generated by asn1c-0.9.22 (http://lionet.info/asn1c)
 * From ASN.1 module "ULP-Components"
 * 	found in "../supl-common.asn"
 */

#ifndef _NMR_H_
#define _NMR_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C"
{
#endif

    /* Forward declarations */
    struct NMRelement;

    /* NMR */
    typedef struct NMR
    {
        A_SEQUENCE_OF(struct NMRelement)
        list;

        /* Context for parsing across buffer boundaries */
        asn_struct_ctx_t _asn_ctx;
    } NMR_t;

    /* Implementation */
    extern asn_TYPE_descriptor_t asn_DEF_NMR;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "NMRelement.h"

#endif /* _NMR_H_ */
#include <asn_internal.h>
