/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2SM-NI-IEs"
 * 	found in "/local/mnt/openairinterface5g/openair2/RIC_AGENT/MESSAGES/ASN1/R01/e2sm-ni-v01.00.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D /local/mnt/openairinterface5g/cmake_targets/ran_build/build/CMakeFiles/E2SM-NI/`
 */

#ifndef	_E2SM_NI_NI_Identifier_H_
#define	_E2SM_NI_NI_Identifier_H_


#include "asn_application.h"

/* Including external dependencies */
#include "E2SM_NI_Global-eNB-ID.h"
#include "E2SM_NI_Global-en-gNB-ID.h"
#include "E2SM_NI_Global-ng-RAN-ID.h"
#include "E2SM_NI_Global-gNB-DU-ID.h"
#include "E2SM_NI_Global-gNB-CU-UP-ID.h"
#include "constr_CHOICE.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum E2SM_NI_NI_Identifier_PR {
	E2SM_NI_NI_Identifier_PR_NOTHING,	/* No components present */
	E2SM_NI_NI_Identifier_PR_global_eNB_ID,
	E2SM_NI_NI_Identifier_PR_global_en_gNB_ID,
	E2SM_NI_NI_Identifier_PR_global_ng_RAN_ID,
	E2SM_NI_NI_Identifier_PR_global_gNB_DU_ID,
	E2SM_NI_NI_Identifier_PR_global_gNB_CU_UP_ID
	/* Extensions may appear below */
	
} E2SM_NI_NI_Identifier_PR;

/* E2SM_NI_NI-Identifier */
typedef struct E2SM_NI_NI_Identifier {
	E2SM_NI_NI_Identifier_PR present;
	union E2SM_NI_NI_Identifier_u {
		E2SM_NI_Global_eNB_ID_t	 global_eNB_ID;
		E2SM_NI_Global_en_gNB_ID_t	 global_en_gNB_ID;
		E2SM_NI_Global_ng_RAN_ID_t	 global_ng_RAN_ID;
		E2SM_NI_Global_gNB_DU_ID_t	 global_gNB_DU_ID;
		E2SM_NI_Global_gNB_CU_UP_ID_t	 global_gNB_CU_UP_ID;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} E2SM_NI_NI_Identifier_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_E2SM_NI_NI_Identifier;
extern asn_CHOICE_specifics_t asn_SPC_E2SM_NI_NI_Identifier_specs_1;
extern asn_TYPE_member_t asn_MBR_E2SM_NI_NI_Identifier_1[5];
extern asn_per_constraints_t asn_PER_type_E2SM_NI_NI_Identifier_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _E2SM_NI_NI_Identifier_H_ */
#include "asn_internal.h"