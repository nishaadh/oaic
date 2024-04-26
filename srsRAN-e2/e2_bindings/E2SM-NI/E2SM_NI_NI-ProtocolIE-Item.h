/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-NI-IEs"
 * 	found in "/local/mnt/openairinterface5g/openair2/RIC_AGENT/MESSAGES/ASN1/R01/e2sm-ni-v01.00.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D /local/mnt/openairinterface5g/cmake_targets/ran_build/build/CMakeFiles/E2SM-NI/`
 */

#ifndef	_E2SM_NI_NI_ProtocolIE_Item_H_
#define	_E2SM_NI_NI_ProtocolIE_Item_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2SM_NI_NI-ProtocolIE-ID.h"
#include "E2SM_NI_NI-ProtocolIE-Test.h"
#include "E2SM_NI_NI-ProtocolIE-Value.h"
#include "constr_SEQUENCE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* E2SM_NI_NI-ProtocolIE-Item */
typedef struct E2SM_NI_NI_ProtocolIE_Item {
	E2SM_NI_NI_ProtocolIE_ID_t	 interfaceProtocolIE_ID;
	E2SM_NI_NI_ProtocolIE_Test_t	 interfaceProtocolIE_Test;
	E2SM_NI_NI_ProtocolIE_Value_t	 interfaceProtocolIE_Value;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_NI_NI_ProtocolIE_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_NI_NI_ProtocolIE_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_E2SM_NI_NI_ProtocolIE_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_NI_NI_ProtocolIE_Item_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_NI_NI_ProtocolIE_Item_H_ */
#include "asn_internal.h"
