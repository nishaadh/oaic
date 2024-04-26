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
 * From ASN.1 module "E2AP-Containers"
 * 	found in "e2ap-v01.01.00.asn"
 * 	`asn1c -pdu=auto -fincludes-quoted -fcompound-names -findirect-choice -fno-include-deps -gen-PER -no-gen-OER -no-gen-example`
 */

#ifndef	_ProtocolIE_SingleContainer_H_
#define	_ProtocolIE_SingleContainer_H_


#include "asn_application.h"

/* Including external dependencies */
#include "ProtocolIE-Field.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ProtocolIE-SingleContainer */
typedef RICaction_ToBeSetup_ItemIEs_t	 ProtocolIE_SingleContainer_229P0_t;
typedef RICaction_Admitted_ItemIEs_t	 ProtocolIE_SingleContainer_229P1_t;
typedef RICaction_NotAdmitted_ItemIEs_t	 ProtocolIE_SingleContainer_229P2_t;
typedef E2connectionUpdate_ItemIEs_t	 ProtocolIE_SingleContainer_229P3_t;
typedef E2connectionUpdateRemove_ItemIEs_t	 ProtocolIE_SingleContainer_229P4_t;
typedef E2connectionSetupFailed_ItemIEs_t	 ProtocolIE_SingleContainer_229P5_t;
typedef E2nodeComponentConfigUpdate_ItemIEs_t	 ProtocolIE_SingleContainer_229P6_t;
typedef E2nodeComponentConfigUpdateAck_ItemIEs_t	 ProtocolIE_SingleContainer_229P7_t;
typedef RANfunction_ItemIEs_t	 ProtocolIE_SingleContainer_229P8_t;
typedef RANfunctionID_ItemIEs_t	 ProtocolIE_SingleContainer_229P9_t;
typedef RANfunctionIDcause_ItemIEs_t	 ProtocolIE_SingleContainer_229P10_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_SingleContainer_229P0;
asn_struct_free_f ProtocolIE_SingleContainer_229P0_free;
asn_struct_print_f ProtocolIE_SingleContainer_229P0_print;
asn_constr_check_f ProtocolIE_SingleContainer_229P0_constraint;
ber_type_decoder_f ProtocolIE_SingleContainer_229P0_decode_ber;
der_type_encoder_f ProtocolIE_SingleContainer_229P0_encode_der;
xer_type_decoder_f ProtocolIE_SingleContainer_229P0_decode_xer;
xer_type_encoder_f ProtocolIE_SingleContainer_229P0_encode_xer;
per_type_decoder_f ProtocolIE_SingleContainer_229P0_decode_uper;
per_type_encoder_f ProtocolIE_SingleContainer_229P0_encode_uper;
per_type_decoder_f ProtocolIE_SingleContainer_229P0_decode_aper;
per_type_encoder_f ProtocolIE_SingleContainer_229P0_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_SingleContainer_229P1;
asn_struct_free_f ProtocolIE_SingleContainer_229P1_free;
asn_struct_print_f ProtocolIE_SingleContainer_229P1_print;
asn_constr_check_f ProtocolIE_SingleContainer_229P1_constraint;
ber_type_decoder_f ProtocolIE_SingleContainer_229P1_decode_ber;
der_type_encoder_f ProtocolIE_SingleContainer_229P1_encode_der;
xer_type_decoder_f ProtocolIE_SingleContainer_229P1_decode_xer;
xer_type_encoder_f ProtocolIE_SingleContainer_229P1_encode_xer;
per_type_decoder_f ProtocolIE_SingleContainer_229P1_decode_uper;
per_type_encoder_f ProtocolIE_SingleContainer_229P1_encode_uper;
per_type_decoder_f ProtocolIE_SingleContainer_229P1_decode_aper;
per_type_encoder_f ProtocolIE_SingleContainer_229P1_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_SingleContainer_229P2;
asn_struct_free_f ProtocolIE_SingleContainer_229P2_free;
asn_struct_print_f ProtocolIE_SingleContainer_229P2_print;
asn_constr_check_f ProtocolIE_SingleContainer_229P2_constraint;
ber_type_decoder_f ProtocolIE_SingleContainer_229P2_decode_ber;
der_type_encoder_f ProtocolIE_SingleContainer_229P2_encode_der;
xer_type_decoder_f ProtocolIE_SingleContainer_229P2_decode_xer;
xer_type_encoder_f ProtocolIE_SingleContainer_229P2_encode_xer;
per_type_decoder_f ProtocolIE_SingleContainer_229P2_decode_uper;
per_type_encoder_f ProtocolIE_SingleContainer_229P2_encode_uper;
per_type_decoder_f ProtocolIE_SingleContainer_229P2_decode_aper;
per_type_encoder_f ProtocolIE_SingleContainer_229P2_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_SingleContainer_229P3;
asn_struct_free_f ProtocolIE_SingleContainer_229P3_free;
asn_struct_print_f ProtocolIE_SingleContainer_229P3_print;
asn_constr_check_f ProtocolIE_SingleContainer_229P3_constraint;
ber_type_decoder_f ProtocolIE_SingleContainer_229P3_decode_ber;
der_type_encoder_f ProtocolIE_SingleContainer_229P3_encode_der;
xer_type_decoder_f ProtocolIE_SingleContainer_229P3_decode_xer;
xer_type_encoder_f ProtocolIE_SingleContainer_229P3_encode_xer;
per_type_decoder_f ProtocolIE_SingleContainer_229P3_decode_uper;
per_type_encoder_f ProtocolIE_SingleContainer_229P3_encode_uper;
per_type_decoder_f ProtocolIE_SingleContainer_229P3_decode_aper;
per_type_encoder_f ProtocolIE_SingleContainer_229P3_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_SingleContainer_229P4;
asn_struct_free_f ProtocolIE_SingleContainer_229P4_free;
asn_struct_print_f ProtocolIE_SingleContainer_229P4_print;
asn_constr_check_f ProtocolIE_SingleContainer_229P4_constraint;
ber_type_decoder_f ProtocolIE_SingleContainer_229P4_decode_ber;
der_type_encoder_f ProtocolIE_SingleContainer_229P4_encode_der;
xer_type_decoder_f ProtocolIE_SingleContainer_229P4_decode_xer;
xer_type_encoder_f ProtocolIE_SingleContainer_229P4_encode_xer;
per_type_decoder_f ProtocolIE_SingleContainer_229P4_decode_uper;
per_type_encoder_f ProtocolIE_SingleContainer_229P4_encode_uper;
per_type_decoder_f ProtocolIE_SingleContainer_229P4_decode_aper;
per_type_encoder_f ProtocolIE_SingleContainer_229P4_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_SingleContainer_229P5;
asn_struct_free_f ProtocolIE_SingleContainer_229P5_free;
asn_struct_print_f ProtocolIE_SingleContainer_229P5_print;
asn_constr_check_f ProtocolIE_SingleContainer_229P5_constraint;
ber_type_decoder_f ProtocolIE_SingleContainer_229P5_decode_ber;
der_type_encoder_f ProtocolIE_SingleContainer_229P5_encode_der;
xer_type_decoder_f ProtocolIE_SingleContainer_229P5_decode_xer;
xer_type_encoder_f ProtocolIE_SingleContainer_229P5_encode_xer;
per_type_decoder_f ProtocolIE_SingleContainer_229P5_decode_uper;
per_type_encoder_f ProtocolIE_SingleContainer_229P5_encode_uper;
per_type_decoder_f ProtocolIE_SingleContainer_229P5_decode_aper;
per_type_encoder_f ProtocolIE_SingleContainer_229P5_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_SingleContainer_229P6;
asn_struct_free_f ProtocolIE_SingleContainer_229P6_free;
asn_struct_print_f ProtocolIE_SingleContainer_229P6_print;
asn_constr_check_f ProtocolIE_SingleContainer_229P6_constraint;
ber_type_decoder_f ProtocolIE_SingleContainer_229P6_decode_ber;
der_type_encoder_f ProtocolIE_SingleContainer_229P6_encode_der;
xer_type_decoder_f ProtocolIE_SingleContainer_229P6_decode_xer;
xer_type_encoder_f ProtocolIE_SingleContainer_229P6_encode_xer;
per_type_decoder_f ProtocolIE_SingleContainer_229P6_decode_uper;
per_type_encoder_f ProtocolIE_SingleContainer_229P6_encode_uper;
per_type_decoder_f ProtocolIE_SingleContainer_229P6_decode_aper;
per_type_encoder_f ProtocolIE_SingleContainer_229P6_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_SingleContainer_229P7;
asn_struct_free_f ProtocolIE_SingleContainer_229P7_free;
asn_struct_print_f ProtocolIE_SingleContainer_229P7_print;
asn_constr_check_f ProtocolIE_SingleContainer_229P7_constraint;
ber_type_decoder_f ProtocolIE_SingleContainer_229P7_decode_ber;
der_type_encoder_f ProtocolIE_SingleContainer_229P7_encode_der;
xer_type_decoder_f ProtocolIE_SingleContainer_229P7_decode_xer;
xer_type_encoder_f ProtocolIE_SingleContainer_229P7_encode_xer;
per_type_decoder_f ProtocolIE_SingleContainer_229P7_decode_uper;
per_type_encoder_f ProtocolIE_SingleContainer_229P7_encode_uper;
per_type_decoder_f ProtocolIE_SingleContainer_229P7_decode_aper;
per_type_encoder_f ProtocolIE_SingleContainer_229P7_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_SingleContainer_229P8;
asn_struct_free_f ProtocolIE_SingleContainer_229P8_free;
asn_struct_print_f ProtocolIE_SingleContainer_229P8_print;
asn_constr_check_f ProtocolIE_SingleContainer_229P8_constraint;
ber_type_decoder_f ProtocolIE_SingleContainer_229P8_decode_ber;
der_type_encoder_f ProtocolIE_SingleContainer_229P8_encode_der;
xer_type_decoder_f ProtocolIE_SingleContainer_229P8_decode_xer;
xer_type_encoder_f ProtocolIE_SingleContainer_229P8_encode_xer;
per_type_decoder_f ProtocolIE_SingleContainer_229P8_decode_uper;
per_type_encoder_f ProtocolIE_SingleContainer_229P8_encode_uper;
per_type_decoder_f ProtocolIE_SingleContainer_229P8_decode_aper;
per_type_encoder_f ProtocolIE_SingleContainer_229P8_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_SingleContainer_229P9;
asn_struct_free_f ProtocolIE_SingleContainer_229P9_free;
asn_struct_print_f ProtocolIE_SingleContainer_229P9_print;
asn_constr_check_f ProtocolIE_SingleContainer_229P9_constraint;
ber_type_decoder_f ProtocolIE_SingleContainer_229P9_decode_ber;
der_type_encoder_f ProtocolIE_SingleContainer_229P9_encode_der;
xer_type_decoder_f ProtocolIE_SingleContainer_229P9_decode_xer;
xer_type_encoder_f ProtocolIE_SingleContainer_229P9_encode_xer;
per_type_decoder_f ProtocolIE_SingleContainer_229P9_decode_uper;
per_type_encoder_f ProtocolIE_SingleContainer_229P9_encode_uper;
per_type_decoder_f ProtocolIE_SingleContainer_229P9_decode_aper;
per_type_encoder_f ProtocolIE_SingleContainer_229P9_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_ProtocolIE_SingleContainer_229P10;
asn_struct_free_f ProtocolIE_SingleContainer_229P10_free;
asn_struct_print_f ProtocolIE_SingleContainer_229P10_print;
asn_constr_check_f ProtocolIE_SingleContainer_229P10_constraint;
ber_type_decoder_f ProtocolIE_SingleContainer_229P10_decode_ber;
der_type_encoder_f ProtocolIE_SingleContainer_229P10_encode_der;
xer_type_decoder_f ProtocolIE_SingleContainer_229P10_decode_xer;
xer_type_encoder_f ProtocolIE_SingleContainer_229P10_encode_xer;
per_type_decoder_f ProtocolIE_SingleContainer_229P10_decode_uper;
per_type_encoder_f ProtocolIE_SingleContainer_229P10_encode_uper;
per_type_decoder_f ProtocolIE_SingleContainer_229P10_decode_aper;
per_type_encoder_f ProtocolIE_SingleContainer_229P10_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _ProtocolIE_SingleContainer_H_ */
#include "asn_internal.h"
