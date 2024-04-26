/*
 *
 * Copyright 2020 AT&T Intellectual Property
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "E2AP-PDU-Contents"
 * 	found in "e2ap-v01.01.00.asn"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example`
 */

#include "RICserviceUpdateFailure.h"

asn_TYPE_member_t asn_MBR_RICserviceUpdateFailure_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RICserviceUpdateFailure, protocolIEs),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ProtocolIE_Container_226P24,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"protocolIEs"
		},
};
static const ber_tlv_tag_t asn_DEF_RICserviceUpdateFailure_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RICserviceUpdateFailure_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* protocolIEs */
};
asn_SEQUENCE_specifics_t asn_SPC_RICserviceUpdateFailure_specs_1 = {
	sizeof(struct RICserviceUpdateFailure),
	offsetof(struct RICserviceUpdateFailure, _asn_ctx),
	asn_MAP_RICserviceUpdateFailure_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_RICserviceUpdateFailure = {
	"RICserviceUpdateFailure",
	"RICserviceUpdateFailure",
	&asn_OP_SEQUENCE,
	asn_DEF_RICserviceUpdateFailure_tags_1,
	sizeof(asn_DEF_RICserviceUpdateFailure_tags_1)
		/sizeof(asn_DEF_RICserviceUpdateFailure_tags_1[0]), /* 1 */
	asn_DEF_RICserviceUpdateFailure_tags_1,	/* Same as above */
	sizeof(asn_DEF_RICserviceUpdateFailure_tags_1)
		/sizeof(asn_DEF_RICserviceUpdateFailure_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_RICserviceUpdateFailure_1,
	1,	/* Elements count */
	&asn_SPC_RICserviceUpdateFailure_specs_1	/* Additional specs */
};

