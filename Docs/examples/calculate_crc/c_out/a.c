/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>

#include "asn1crt_encoding.h"
#include "asn1crt_encoding_acn.h"

#include "a.h"
#include "postEncoding.h"




flag PacketHeader_version_Equal(const PacketHeader_version* pVal1, const PacketHeader_version* pVal2)
{
	(void)pVal1;
	(void)pVal2;

	return (*(pVal1)) == (*(pVal2));

}

flag PacketHeader_release_Equal(const PacketHeader_release* pVal1, const PacketHeader_release* pVal2)
{
	(void)pVal1;
	(void)pVal2;

	return (*(pVal1)) == (*(pVal2));

}

flag PacketHeader_varSizeArray_elem_Equal(const PacketHeader_varSizeArray_elem* pVal1, const PacketHeader_varSizeArray_elem* pVal2)
{
	(void)pVal1;
	(void)pVal2;

	return (*(pVal1)) == (*(pVal2));

}

flag PacketHeader_varSizeArray_Equal(const PacketHeader_varSizeArray* pVal1, const PacketHeader_varSizeArray* pVal2)
{
	(void)pVal1;
	(void)pVal2;

	flag ret=TRUE;
    int i1;

    ret = (pVal1->nCount == pVal2->nCount);
    for(i1 = 0; ret && i1 < pVal1->nCount; i1++) 
    {
    	ret = PacketHeader_varSizeArray_elem_Equal((&(pVal1->arr[i1])), (&(pVal2->arr[i1])));
    }

	return ret;

}

flag PacketHeader_Equal(const PacketHeader* pVal1, const PacketHeader* pVal2)
{
	(void)pVal1;
	(void)pVal2;

	flag ret=TRUE;

    ret = PacketHeader_version_Equal((&(pVal1->version)), (&(pVal2->version)));
    
    if (ret) {
        ret = PacketHeader_release_Equal((&(pVal1->release)), (&(pVal2->release)));
        
        if (ret) {
            ret = PacketHeader_varSizeArray_Equal((&(pVal1->varSizeArray)), (&(pVal2->varSizeArray)));
        
        }
    
    }

	return ret;

}

void PacketHeader_version_Initialize(PacketHeader_version* pVal)
{
	(void)pVal;


	(*(pVal)) = 1;
}
void PacketHeader_release_Initialize(PacketHeader_release* pVal)
{
	(void)pVal;


	(*(pVal)) = 1;
}
void PacketHeader_varSizeArray_elem_Initialize(PacketHeader_varSizeArray_elem* pVal)
{
	(void)pVal;


	(*(pVal)) = 1;
}
void PacketHeader_varSizeArray_Initialize(PacketHeader_varSizeArray* pVal)
{
	(void)pVal;

    int i1;

	i1 = 0;
	while (i1< 20) {
	    PacketHeader_varSizeArray_elem_Initialize((&(pVal->arr[i1])));
	    i1 = i1 + 1;
	}
	pVal->nCount = 1;
}
void PacketHeader_Initialize(PacketHeader* pVal)
{
	(void)pVal;



	/*set version */
	PacketHeader_version_Initialize((&(pVal->version)));
	/*set release */
	PacketHeader_release_Initialize((&(pVal->release)));
	/*set varSizeArray */
	PacketHeader_varSizeArray_Initialize((&(pVal->varSizeArray)));
}

flag PacketHeader_IsConstraintValid(const PacketHeader* pVal, int* pErrCode)
{
    flag ret = TRUE;
    int i1;
	(void)pVal;
	
    ret = ((1UL <= pVal->version) && (pVal->version <= 100UL));
    *pErrCode = ret ? 0 :  ERR_PACKETHEADER_VERSION; 
    if (ret) {
        ret = ((1UL <= pVal->release) && (pVal->release <= 100UL));
        *pErrCode = ret ? 0 :  ERR_PACKETHEADER_RELEASE; 
        if (ret) {
            ret = ((1 <= pVal->varSizeArray.nCount) && (pVal->varSizeArray.nCount <= 20));
            *pErrCode = ret ? 0 :  ERR_PACKETHEADER_VARSIZEARRAY; 
            if (ret) {
                for(i1 = 0; ret && i1 < pVal->varSizeArray.nCount; i1++) 
                {
                	ret = ((1UL <= pVal->varSizeArray.arr[i1]) && (pVal->varSizeArray.arr[i1] <= 20UL));
                	*pErrCode = ret ? 0 :  ERR_PACKETHEADER_VARSIZEARRAY_ELM; 
                }
            }
        }
    }

	return ret;
}

flag PacketHeader_ACN_Encode(const PacketHeader* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	(void)pVal;
	(void)pBitStrm;

	int i1;
	ret = bCheckConstraints ? PacketHeader_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    /*Encode version */
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, pVal->version, 1, 100);
	    if (ret) {
	        /*Encode release */
	        BitStream_EncodeConstraintPosWholeNumber(pBitStrm, pVal->release, 1, 100);
	        if (ret) {
	            /*Encode varSizeArray */
	            BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->varSizeArray.nCount, 1, 20);
	            	
	            for(i1=0; (i1 < (int)pVal->varSizeArray.nCount) && ret; i1++) 
	            {
	            	BitStream_EncodeConstraintPosWholeNumber(pBitStrm, pVal->varSizeArray.arr[i1], 1, 20);
	            }
	        }
	    
	    }

    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag PacketHeader_ACN_Decode(PacketHeader* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	(void)pVal;
	(void)pBitStrm;
	*pErrCode = 0;

	int i1;
	asn1SccSint nCount;

	/*Decode version */
	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, (&(pVal->version)), 1, 100);
	*pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKETHEADER_VERSION;
	if (ret) {
	    /*Decode release */
	    ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, (&(pVal->release)), 1, 100);
	    *pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKETHEADER_RELEASE;
	    if (ret) {
	        /*Decode varSizeArray */
	        ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 20);
	        *pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKETHEADER_VARSIZEARRAY;
	        pVal->varSizeArray.nCount = (long)nCount;
	        	
	        for(i1=0; (i1 < (int)pVal->varSizeArray.nCount) && ret; i1++) 
	        {
	        	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, (&(pVal->varSizeArray.arr[i1])), 1, 20);
	        	*pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKETHEADER_VARSIZEARRAY_ELM;
	        }
	    }
	
	}


    return ret && PacketHeader_IsConstraintValid(pVal, pErrCode);
}



flag PacketBody_anInteger_Equal(const PacketBody_anInteger* pVal1, const PacketBody_anInteger* pVal2)
{
	(void)pVal1;
	(void)pVal2;

	return (*(pVal1)) == (*(pVal2));

}

flag PacketBody_anotherSizeArray_elem_Equal(const PacketBody_anotherSizeArray_elem* pVal1, const PacketBody_anotherSizeArray_elem* pVal2)
{
	(void)pVal1;
	(void)pVal2;

	return (*(pVal1)) == (*(pVal2));

}

flag PacketBody_anotherSizeArray_Equal(const PacketBody_anotherSizeArray* pVal1, const PacketBody_anotherSizeArray* pVal2)
{
	(void)pVal1;
	(void)pVal2;

	flag ret=TRUE;
    int i1;

    ret = (pVal1->nCount == pVal2->nCount);
    for(i1 = 0; ret && i1 < pVal1->nCount; i1++) 
    {
    	ret = PacketBody_anotherSizeArray_elem_Equal((&(pVal1->arr[i1])), (&(pVal2->arr[i1])));
    }

	return ret;

}

flag PacketBody_Equal(const PacketBody* pVal1, const PacketBody* pVal2)
{
	(void)pVal1;
	(void)pVal2;

	flag ret=TRUE;

    ret = (pVal1->kind == pVal2->kind);
    if (ret) {
    	switch(pVal1->kind) 
    	{
    	case aReal_PRESENT:
    		ret = (pVal1->u.aReal == pVal2->u.aReal);
    		break;
    	case anInteger_PRESENT:
    		ret = PacketBody_anInteger_Equal((&(pVal1->u.anInteger)), (&(pVal2->u.anInteger)));
    		break;
    	case anotherSizeArray_PRESENT:
    		ret = PacketBody_anotherSizeArray_Equal((&(pVal1->u.anotherSizeArray)), (&(pVal2->u.anotherSizeArray)));
    		break;
    	default: /*COVERAGE_IGNORE*/
    		ret = FALSE;    /*COVERAGE_IGNORE*/
    	}
    } /*COVERAGE_IGNORE*/
	return ret;

}

void PacketBody_anInteger_Initialize(PacketBody_anInteger* pVal)
{
	(void)pVal;


	(*(pVal)) = 0;
}
void PacketBody_anotherSizeArray_elem_Initialize(PacketBody_anotherSizeArray_elem* pVal)
{
	(void)pVal;


	(*(pVal)) = 1;
}
void PacketBody_anotherSizeArray_Initialize(PacketBody_anotherSizeArray* pVal)
{
	(void)pVal;

    int i1;

	i1 = 0;
	while (i1< 100) {
	    PacketBody_anotherSizeArray_elem_Initialize((&(pVal->arr[i1])));
	    i1 = i1 + 1;
	}
	pVal->nCount = 1;
}
void PacketBody_Initialize(PacketBody* pVal)
{
	(void)pVal;


	/*set aReal*/
	pVal->kind = aReal_PRESENT;
	pVal->u.aReal = 0.00000000000000000000E+000;
}

flag PacketBody_IsConstraintValid(const PacketBody* pVal, int* pErrCode)
{
    flag ret = TRUE;
    int i1;
	(void)pVal;
	
    if (pVal->kind == anInteger_PRESENT) {
    	ret = (pVal->u.anInteger <= 65535UL);
    	*pErrCode = ret ? 0 :  ERR_PACKETBODY_ANINTEGER; 
    }
    if (ret) {
        if (pVal->kind == anotherSizeArray_PRESENT) {
        	ret = ((1 <= pVal->u.anotherSizeArray.nCount) && (pVal->u.anotherSizeArray.nCount <= 100));
        	*pErrCode = ret ? 0 :  ERR_PACKETBODY_ANOTHERSIZEARRAY; 
        	if (ret) {
        	    for(i1 = 0; ret && i1 < pVal->u.anotherSizeArray.nCount; i1++) 
        	    {
        	    	ret = ((1UL <= pVal->u.anotherSizeArray.arr[i1]) && (pVal->u.anotherSizeArray.arr[i1] <= 200UL));
        	    	*pErrCode = ret ? 0 :  ERR_PACKETBODY_ANOTHERSIZEARRAY_ELM; 
        	    }
        	}
        }
    }

	return ret;
}

flag PacketBody_ACN_Encode(const PacketBody* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	(void)pVal;
	(void)pBitStrm;

	int i1;
	ret = bCheckConstraints ? PacketBody_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    switch(pVal->kind) 
	    {
	    case aReal_PRESENT:
	    	BitStream_EncodeConstraintWholeNumber(pBitStrm, 0, 0, 2);
	    	BitStream_EncodeReal(pBitStrm, pVal->u.aReal);
	    	break;
	    case anInteger_PRESENT:
	    	BitStream_EncodeConstraintWholeNumber(pBitStrm, 1, 0, 2);
	    	BitStream_EncodeConstraintPosWholeNumber(pBitStrm, pVal->u.anInteger, 0, 65535);
	    	break;
	    case anotherSizeArray_PRESENT:
	    	BitStream_EncodeConstraintWholeNumber(pBitStrm, 2, 0, 2);
	    	BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->u.anotherSizeArray.nCount, 1, 100);
	    		
	    	for(i1=0; (i1 < (int)pVal->u.anotherSizeArray.nCount) && ret; i1++) 
	    	{
	    		BitStream_EncodeConstraintPosWholeNumber(pBitStrm, pVal->u.anotherSizeArray.arr[i1], 1, 200);
	    	}
	    	break;
	    default: /*COVERAGE_IGNORE*/
	        *pErrCode = ERR_ACN_ENCODE_PACKETBODY;         /*COVERAGE_IGNORE*/
	        ret = FALSE;                    /*COVERAGE_IGNORE*/
	    } /*COVERAGE_IGNORE*/
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag PacketBody_ACN_Decode(PacketBody* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	(void)pVal;
	(void)pBitStrm;
	*pErrCode = 0;

	asn1SccSint MYMODULE_PacketBody_index_tmp;
	int i1;
	asn1SccSint nCount;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &MYMODULE_PacketBody_index_tmp, 0, 2);
	*pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKETBODY;
	if (ret) {
	    switch(MYMODULE_PacketBody_index_tmp) 
	    {
	    case 0:
	    	pVal->kind = aReal_PRESENT;
	    	ret = BitStream_DecodeReal(pBitStrm, (&(pVal->u.aReal)));
	    	*pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKETBODY_AREAL;
	    	break;
	    case 1:
	    	pVal->kind = anInteger_PRESENT;
	    	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, (&(pVal->u.anInteger)), 0, 65535);
	    	*pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKETBODY_ANINTEGER;
	    	break;
	    case 2:
	    	pVal->kind = anotherSizeArray_PRESENT;
	    	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 100);
	    	*pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKETBODY_ANOTHERSIZEARRAY;
	    	pVal->u.anotherSizeArray.nCount = (long)nCount;
	    		
	    	for(i1=0; (i1 < (int)pVal->u.anotherSizeArray.nCount) && ret; i1++) 
	    	{
	    		ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, (&(pVal->u.anotherSizeArray.arr[i1])), 1, 200);
	    		*pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKETBODY_ANOTHERSIZEARRAY_ELM;
	    	}
	    	break;
	    default: /*COVERAGE_IGNORE*/
	        *pErrCode = ERR_ACN_DECODE_PACKETBODY;     /*COVERAGE_IGNORE*/
	        ret = FALSE;                /*COVERAGE_IGNORE*/
	    } 
	} /*COVERAGE_IGNORE*/

    return ret && PacketBody_IsConstraintValid(pVal, pErrCode);
}



flag Packet_Equal(const Packet* pVal1, const Packet* pVal2)
{
	(void)pVal1;
	(void)pVal2;

	flag ret=TRUE;

    ret = PacketHeader_Equal((&(pVal1->p_header)), (&(pVal2->p_header)));
    
    if (ret) {
        ret = PacketBody_Equal((&(pVal1->p_body)), (&(pVal2->p_body)));
    
    }

	return ret;

}

void Packet_Initialize(Packet* pVal)
{
	(void)pVal;



	/*set p_header */
	PacketHeader_Initialize((&(pVal->p_header)));
	/*set p_body */
	PacketBody_Initialize((&(pVal->p_body)));
}

flag Packet_IsConstraintValid(const Packet* pVal, int* pErrCode)
{
    flag ret = TRUE;
    int i1;
	(void)pVal;
	
    ret = ((1UL <= pVal->p_header.version) && (pVal->p_header.version <= 100UL));
    *pErrCode = ret ? 0 :  ERR_PACKET_P_HEADER_VERSION; 
    if (ret) {
        ret = ((1UL <= pVal->p_header.release) && (pVal->p_header.release <= 100UL));
        *pErrCode = ret ? 0 :  ERR_PACKET_P_HEADER_RELEASE; 
        if (ret) {
            ret = ((1 <= pVal->p_header.varSizeArray.nCount) && (pVal->p_header.varSizeArray.nCount <= 20));
            *pErrCode = ret ? 0 :  ERR_PACKET_P_HEADER_VARSIZEARRAY; 
            if (ret) {
                for(i1 = 0; ret && i1 < pVal->p_header.varSizeArray.nCount; i1++) 
                {
                	ret = ((1UL <= pVal->p_header.varSizeArray.arr[i1]) && (pVal->p_header.varSizeArray.arr[i1] <= 20UL));
                	*pErrCode = ret ? 0 :  ERR_PACKET_P_HEADER_VARSIZEARRAY_ELM; 
                }
            }
        }
    }
    if (ret) {
        if (pVal->p_body.kind == anInteger_PRESENT) {
        	ret = (pVal->p_body.u.anInteger <= 65535UL);
        	*pErrCode = ret ? 0 :  ERR_PACKET_P_BODY_ANINTEGER; 
        }
        if (ret) {
            if (pVal->p_body.kind == anotherSizeArray_PRESENT) {
            	ret = ((1 <= pVal->p_body.u.anotherSizeArray.nCount) && (pVal->p_body.u.anotherSizeArray.nCount <= 100));
            	*pErrCode = ret ? 0 :  ERR_PACKET_P_BODY_ANOTHERSIZEARRAY; 
            	if (ret) {
            	    for(i1 = 0; ret && i1 < pVal->p_body.u.anotherSizeArray.nCount; i1++) 
            	    {
            	    	ret = ((1UL <= pVal->p_body.u.anotherSizeArray.arr[i1]) && (pVal->p_body.u.anotherSizeArray.arr[i1] <= 200UL));
            	    	*pErrCode = ret ? 0 :  ERR_PACKET_P_BODY_ANOTHERSIZEARRAY_ELM; 
            	    }
            	}
            }
        }
    }

	return ret;
}

flag Packet_ACN_Encode(const Packet* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;
	(void)pVal;
	(void)pBitStrm;

	Packet_extension_function_positions bitStreamPositions_1;
	BitStream bitStreamPositions_start1;
	int i1;
	ret = bCheckConstraints ? Packet_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret) {
	    bitStreamPositions_start1 = *pBitStrm; //save the initial position of the bit stream at 
	    if (ret) {
	        /*Encode p_header */
	        /*Encode version */
	        BitStream_EncodeConstraintPosWholeNumber(pBitStrm, pVal->p_header.version, 1, 100);
	        if (ret) {
	            /*Encode release */
	            BitStream_EncodeConstraintPosWholeNumber(pBitStrm, pVal->p_header.release, 1, 100);
	            if (ret) {
	                /*Encode varSizeArray */
	                BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->p_header.varSizeArray.nCount, 1, 20);
	                	
	                for(i1=0; (i1 < (int)pVal->p_header.varSizeArray.nCount) && ret; i1++) 
	                {
	                	BitStream_EncodeConstraintPosWholeNumber(pBitStrm, pVal->p_header.varSizeArray.arr[i1], 1, 20);
	                }
	            }
	        
	        }
	        
	        if (ret) {
	            /*Encode Packet_body_length_in_bytes */
	            bitStreamPositions_1.Packet_body_length_in_bytes = *pBitStrm; //save position of the bit stream
	            {
	            	static byte tmp[] = {0x00,0x00};
	            	BitStream_AppendBits(pBitStrm, tmp, 16);
	            }
	            if (ret) {
	                /*Encode p_body */
	                switch(pVal->p_body.kind) 
	                {
	                case aReal_PRESENT:
	                	BitStream_EncodeConstraintWholeNumber(pBitStrm, 0, 0, 2);
	                	BitStream_EncodeReal(pBitStrm, pVal->p_body.u.aReal);
	                	break;
	                case anInteger_PRESENT:
	                	BitStream_EncodeConstraintWholeNumber(pBitStrm, 1, 0, 2);
	                	BitStream_EncodeConstraintPosWholeNumber(pBitStrm, pVal->p_body.u.anInteger, 0, 65535);
	                	break;
	                case anotherSizeArray_PRESENT:
	                	BitStream_EncodeConstraintWholeNumber(pBitStrm, 2, 0, 2);
	                	BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->p_body.u.anotherSizeArray.nCount, 1, 100);
	                		
	                	for(i1=0; (i1 < (int)pVal->p_body.u.anotherSizeArray.nCount) && ret; i1++) 
	                	{
	                		BitStream_EncodeConstraintPosWholeNumber(pBitStrm, pVal->p_body.u.anotherSizeArray.arr[i1], 1, 200);
	                	}
	                	break;
	                default: /*COVERAGE_IGNORE*/
	                    *pErrCode = ERR_ACN_ENCODE_PACKET_P_BODY;         /*COVERAGE_IGNORE*/
	                    ret = FALSE;                    /*COVERAGE_IGNORE*/
	                } /*COVERAGE_IGNORE*/
	                if (ret) {
	                    /*Encode Packet_packet_crc32 */
	                    bitStreamPositions_1.Packet_packet_crc32 = *pBitStrm; //save position of the bit stream
	                    {
	                    	static byte tmp[] = {0x00,0x00,0x00,0x00};
	                    	BitStream_AppendBits(pBitStrm, tmp, 32);
	                    }
	                    if (ret) {
	                        my_encoding_patcher(pVal, &bitStreamPositions_start1, &bitStreamPositions_1, pBitStrm);
	                    }
	                
	                }
	            
	            }
	        
	        }
	    
	    }

    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag Packet_ACN_Decode(Packet* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	(void)pVal;
	(void)pBitStrm;
	*pErrCode = 0;

	Packet_extension_function_positions bitStreamPositions_1;
	BitStream bitStreamPositions_start1;
	int i1;
	asn1SccSint nCount;
	asn1SccSint MYMODULE_Packet_p_body_index_tmp;

	ret = TRUE;
	bitStreamPositions_start1 = *pBitStrm; //save the initial position of the bit stream
	if (ret) {
	    /*Decode p_header */
	    /*Decode version */
	    ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, (&(pVal->p_header.version)), 1, 100);
	    *pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKET_P_HEADER_VERSION;
	    if (ret) {
	        /*Decode release */
	        ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, (&(pVal->p_header.release)), 1, 100);
	        *pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKET_P_HEADER_RELEASE;
	        if (ret) {
	            /*Decode varSizeArray */
	            ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 20);
	            *pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKET_P_HEADER_VARSIZEARRAY;
	            pVal->p_header.varSizeArray.nCount = (long)nCount;
	            	
	            for(i1=0; (i1 < (int)pVal->p_header.varSizeArray.nCount) && ret; i1++) 
	            {
	            	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, (&(pVal->p_header.varSizeArray.arr[i1])), 1, 20);
	            	*pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKET_P_HEADER_VARSIZEARRAY_ELM;
	            }
	        }
	    
	    }
	    
	    if (ret) {
	        /*Decode Packet_body_length_in_bytes */
	        bitStreamPositions_1.Packet_body_length_in_bytes = *pBitStrm; //save position of the bit stream
	        ret = BitStream_ReadBitPattern_ignore_value(pBitStrm, 16);
	        
	        if (ret) {
	            /*Decode p_body */
	            ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &MYMODULE_Packet_p_body_index_tmp, 0, 2);
	            *pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKET_P_BODY;
	            if (ret) {
	                switch(MYMODULE_Packet_p_body_index_tmp) 
	                {
	                case 0:
	                	pVal->p_body.kind = aReal_PRESENT;
	                	ret = BitStream_DecodeReal(pBitStrm, (&(pVal->p_body.u.aReal)));
	                	*pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKET_P_BODY_AREAL;
	                	break;
	                case 1:
	                	pVal->p_body.kind = anInteger_PRESENT;
	                	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, (&(pVal->p_body.u.anInteger)), 0, 65535);
	                	*pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKET_P_BODY_ANINTEGER;
	                	break;
	                case 2:
	                	pVal->p_body.kind = anotherSizeArray_PRESENT;
	                	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 1, 100);
	                	*pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKET_P_BODY_ANOTHERSIZEARRAY;
	                	pVal->p_body.u.anotherSizeArray.nCount = (long)nCount;
	                		
	                	for(i1=0; (i1 < (int)pVal->p_body.u.anotherSizeArray.nCount) && ret; i1++) 
	                	{
	                		ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, (&(pVal->p_body.u.anotherSizeArray.arr[i1])), 1, 200);
	                		*pErrCode = ret ? 0 : ERR_ACN_DECODE_PACKET_P_BODY_ANOTHERSIZEARRAY_ELM;
	                	}
	                	break;
	                default: /*COVERAGE_IGNORE*/
	                    *pErrCode = ERR_ACN_DECODE_PACKET_P_BODY;     /*COVERAGE_IGNORE*/
	                    ret = FALSE;                /*COVERAGE_IGNORE*/
	                } 
	            } /*COVERAGE_IGNORE*/
	            if (ret) {
	                /*Decode Packet_packet_crc32 */
	                bitStreamPositions_1.Packet_packet_crc32 = *pBitStrm; //save position of the bit stream
	                ret = BitStream_ReadBitPattern_ignore_value(pBitStrm, 32);
	                
	                if (ret) {
	                    ret = crc_validator(pVal, &bitStreamPositions_start1, &bitStreamPositions_1, pBitStrm, pErrCode);
	                }
	            
	            }
	        
	        }
	    
	    }
	
	}


    return ret && Packet_IsConstraintValid(pVal, pErrCode);
}
