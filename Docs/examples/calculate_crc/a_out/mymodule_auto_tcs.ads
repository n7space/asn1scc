-- Code automatically generated by asn1scc tool
with adaasn1rtl;
with MYMODULE;

PACKAGE MYMODULE_auto_tcs
IS

FUNCTION PacketHeader_ACN_enc_dec(val:MYMODULE.PacketHeader; Filename : in String) RETURN adaasn1rtl.TEST_CASE_RESULT;

FUNCTION PacketBody_ACN_enc_dec(val:MYMODULE.PacketBody; Filename : in String) RETURN adaasn1rtl.TEST_CASE_RESULT;

FUNCTION Packet_ACN_enc_dec(val:MYMODULE.Packet; Filename : in String) RETURN adaasn1rtl.TEST_CASE_RESULT;

end MYMODULE_auto_tcs;