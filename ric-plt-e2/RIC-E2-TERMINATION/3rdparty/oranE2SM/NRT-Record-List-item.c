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
 * From ASN.1 module "E2SM-gNB-NRT-IEs"
 * 	found in "../asnTextFiles/e2sm-gNB-NRT-v401.asn"
 * 	`asn1c -fcompound-names -fincludes-quoted -fno-include-deps -findirect-choice -gen-PER -no-gen-OER -D.`
 */

#include "NRT-Record-List-item.h"

#include "NRT-Record-row-item.h"
static int
memb_nrt_Record_row_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1 && size <= 1024)) {
		/* Perform validation of the inner elements */
		return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_type_nrt_Record_row_constr_3 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 10,  10,  1,  1024 }	/* (SIZE(1..1024)) */,
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_nrt_Record_row_constr_3 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 10,  10,  1,  1024 }	/* (SIZE(1..1024)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_nrt_Record_row_3[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_NRT_Record_row_item,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_nrt_Record_row_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_nrt_Record_row_specs_3 = {
	sizeof(struct NRT_Record_List_item__nrt_Record_row),
	offsetof(struct NRT_Record_List_item__nrt_Record_row, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_nrt_Record_row_3 = {
	"nrt-Record-row",
	"nrt-Record-row",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_nrt_Record_row_tags_3,
	sizeof(asn_DEF_nrt_Record_row_tags_3)
		/sizeof(asn_DEF_nrt_Record_row_tags_3[0]) - 1, /* 1 */
	asn_DEF_nrt_Record_row_tags_3,	/* Same as above */
	sizeof(asn_DEF_nrt_Record_row_tags_3)
		/sizeof(asn_DEF_nrt_Record_row_tags_3[0]), /* 2 */
	{ 0, &asn_PER_type_nrt_Record_row_constr_3, SEQUENCE_OF_constraint },
	asn_MBR_nrt_Record_row_3,
	1,	/* Single element */
	&asn_SPC_nrt_Record_row_specs_3	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_NRT_Record_List_item_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NRT_Record_List_item, servedCellID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_NRT_Cell_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"servedCellID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct NRT_Record_List_item, nrt_Record_row),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		0,
		&asn_DEF_nrt_Record_row_3,
		0,
		{ 0, &asn_PER_memb_nrt_Record_row_constr_3,  memb_nrt_Record_row_constraint_1 },
		0, 0, /* No default value */
		"nrt-Record-row"
		},
};
static const ber_tlv_tag_t asn_DEF_NRT_Record_List_item_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NRT_Record_List_item_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* servedCellID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* nrt-Record-row */
};
asn_SEQUENCE_specifics_t asn_SPC_NRT_Record_List_item_specs_1 = {
	sizeof(struct NRT_Record_List_item),
	offsetof(struct NRT_Record_List_item, _asn_ctx),
	asn_MAP_NRT_Record_List_item_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NRT_Record_List_item = {
	"NRT-Record-List-item",
	"NRT-Record-List-item",
	&asn_OP_SEQUENCE,
	asn_DEF_NRT_Record_List_item_tags_1,
	sizeof(asn_DEF_NRT_Record_List_item_tags_1)
		/sizeof(asn_DEF_NRT_Record_List_item_tags_1[0]), /* 1 */
	asn_DEF_NRT_Record_List_item_tags_1,	/* Same as above */
	sizeof(asn_DEF_NRT_Record_List_item_tags_1)
		/sizeof(asn_DEF_NRT_Record_List_item_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_NRT_Record_List_item_1,
	2,	/* Elements count */
	&asn_SPC_NRT_Record_List_item_specs_1	/* Additional specs */
};

