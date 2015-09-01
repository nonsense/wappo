/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Jan 28 19:26:48 2004
 */
/* Compiler settings for E:\Visual Studio Projects\WappoServer\WappoServer.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_IWGame = {0xBFC5D6BC,0xB8E1,0x4808,{0x91,0x58,0x6E,0xCD,0x34,0x5C,0x35,0x6D}};


const IID IID_IWLevels = {0x1B8369B8,0x07CF,0x48B6,{0x9E,0x4D,0xEA,0x56,0xA7,0x66,0x65,0x2A}};


const IID LIBID_WAPPOSERVERLib = {0x202FCBCC,0x8752,0x4D5A,{0xA8,0xE2,0xB1,0xBD,0xCB,0x1C,0x69,0x6D}};


const CLSID CLSID_WGame = {0x8F2004E2,0x0D1A,0x4CEE,{0x92,0x71,0x2E,0x63,0xD4,0xE0,0x01,0xB0}};


const CLSID CLSID_WLevels = {0x8CB9A5C1,0xC9F8,0x4B4B,{0xB6,0x13,0x4E,0x78,0x64,0xA4,0xBC,0x27}};


#ifdef __cplusplus
}
#endif

