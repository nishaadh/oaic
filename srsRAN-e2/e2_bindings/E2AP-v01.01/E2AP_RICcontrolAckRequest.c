/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-IEs"
 * 	found in "./e2ap-v01.01.asn1"
 * 	`asn1c -pdu=all -fcompound-names -gen-PER -no-gen-OER -no-gen-example -fno-include-deps -fincludes-quoted -D E2AP-v01.01/`
 */

#include "E2AP_RICcontrolAckRequest.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
asn_per_constraints_t asn_PER_type_E2AP_RICcontrolAckRequest_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  2 }	/* (0..2,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_E2AP_RICcontrolAckRequest_value2enum_1[] = {
	{ 0,	5,	"noAck" },
	{ 1,	3,	"ack" },
	{ 2,	4,	"nAck" }
	/* This list is extensible */
};
static const unsigned int asn_MAP_E2AP_RICcontrolAckRequest_enum2value_1[] = {
	1,	/* ack(1) */
	2,	/* nAck(2) */
	0	/* noAck(0) */
	/* This list is extensible */
};
const asn_INTEGER_specifics_t asn_SPC_E2AP_RICcontrolAckRequest_specs_1 = {
	asn_MAP_E2AP_RICcontrolAckRequest_value2enum_1,	/* "tag" => N; sorted by tag */
	asn_MAP_E2AP_RICcontrolAckRequest_enum2value_1,	/* N => "tag"; sorted by N */
	3,	/* Number of elements in the maps */
	4,	/* Extensions before this member */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_E2AP_RICcontrolAckRequest_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
asn_TYPE_descriptor_t asn_DEF_E2AP_RICcontrolAckRequest = {
	"RICcontrolAckRequest",
	"RICcontrolAckRequest",
	&asn_OP_NativeEnumerated,
	asn_DEF_E2AP_RICcontrolAckRequest_tags_1,
	sizeof(asn_DEF_E2AP_RICcontrolAckRequest_tags_1)
		/sizeof(asn_DEF_E2AP_RICcontrolAckRequest_tags_1[0]), /* 1 */
	asn_DEF_E2AP_RICcontrolAckRequest_tags_1,	/* Same as above */
	sizeof(asn_DEF_E2AP_RICcontrolAckRequest_tags_1)
		/sizeof(asn_DEF_E2AP_RICcontrolAckRequest_tags_1[0]), /* 1 */
	{ 0, &asn_PER_type_E2AP_RICcontrolAckRequest_constr_1, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_E2AP_RICcontrolAckRequest_specs_1	/* Additional specs */
};

