//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: G4RTJpegCoderTables.hh,v 1.5 2001/07/11 10:09:01 gunter Exp $
// GEANT4 tag $Name: geant4-05-00 $
//

// class description:
//  
//  This header file defines some hard coded numbers used by G4RTJpegCoder
// to convert 8 bits RGB to JPEG.
//

#ifndef G4RTJpegCoderTable_H
#define G4RTJpegCoderTable_H 1

#include "G4RTJpeg.hh"

//QuantumTable

static const int	YQuantumT[] = {

	1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,
};

static const int	CQuantumT[] = {

	1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,
	1,  1,  1,  1,  1,  1,  1,  1,
};

//HuffmanCode

static const int	YDcSizeT[] = {
		0x0002, 0x0003, 0x0003, 0x0003,
		0x0003, 0x0003, 0x0004, 0x0005,
		0x0006, 0x0007, 0x0008, 0x0009	};
static const int	YDcCodeT[] = {	
		0x0000, 0x0002, 0x0003, 0x0004,
		0x0005, 0x0006, 0x000e, 0x001e,
		0x003e, 0x007e, 0x00fe, 0x01fe	};
static const G4HuffmanCodeTable	YDcHuffmanT = {
	12,
	(int*)YDcSizeT,
	(int*)YDcCodeT	
};


static const int	CDcSizeT[] = {	 
		0x0002, 0x0002, 0x0002, 0x0003,
		0x0004, 0x0005, 0x0006, 0x0007,
		0x0008, 0x0009, 0x000a, 0x000b	};
static const int	CDcCodeT[] = {	 
		0x0000, 0x0001, 0x0002, 0x0006,
		0x000e, 0x001e, 0x003e, 0x007e,
		0x00fe, 0x01fe, 0x03fe, 0x07fe	};
static const G4HuffmanCodeTable	CDcHuffmanT = {
	12, 
	(int*)CDcSizeT,
	(int*)CDcCodeT 
};

 
static const int	YAcSizeT[] = {
		 4,  2,  2,  3,  4,  5,  7,  8,
		10, 16, 16,  4,  5,  7,  9, 11,
		16, 16, 16, 16, 16,  5,  8, 10,
		12, 16, 16, 16, 16, 16, 16,  6,
		 9, 12, 16, 16, 16, 16, 16, 16,
		16,  6, 10, 16, 16, 16, 16, 16,
		16, 16, 16,  7, 11, 16, 16, 16,
		16, 16, 16, 16, 16,  7, 12, 16,
		16, 16, 16, 16, 16, 16, 16,  8,
		12, 16, 16, 16, 16, 16, 16, 16,
		16,  9, 15, 16, 16, 16, 16, 16,
		16, 16, 16,  9, 16, 16, 16, 16,
		16, 16, 16, 16, 16,  9, 16, 16,
		16, 16, 16, 16, 16, 16, 16, 10,
		16, 16, 16, 16, 16, 16, 16, 16,
		16, 10, 16, 16, 16, 16, 16, 16,
		16, 16, 16, 11, 16, 16, 16, 16,
		16, 16, 16, 16, 16, 16, 16, 16,
		16, 16, 16, 16, 16, 16, 16, 11,
		16, 16, 16, 16, 16, 16, 16, 16,
		16, 16 };
static const int	YAcCodeT[] = { 
		0x000a, 0x0000, 0x0001, 0x0004,
		0x000b, 0x001a, 0x0078, 0x00f8,
		0x03f6, 0xff82, 0xff83, 0x000c,
		0x001b, 0x0079, 0x01f6, 0x07f6,
		0xff84, 0xff85, 0xff86, 0xff87,
		0xff88, 0x001c, 0x00f9, 0x03f7,
		0x0ff4, 0xff89, 0xff8a, 0xff8b,
		0xff8c, 0xff8d, 0xff8e, 0x003a,
		0x01f7, 0x0ff5, 0xff8f, 0xff90,
		0xff91, 0xff92, 0xff93, 0xff94,
		0xff95, 0x003b, 0x03f8, 0xff96,
		0xff97, 0xff98, 0xff99, 0xff9a,
		0xff9b, 0xff9c, 0xff9d, 0x007a,
		0x07f7, 0xff9e, 0xff9f, 0xffa0,
		0xffa1, 0xffa2, 0xffa3, 0xffa4,
		0xffa5, 0x007b, 0x0ff6, 0xffa6,
		0xffa7, 0xffa8, 0xffa9, 0xffaa,
		0xffab, 0xffac, 0xffad, 0x00fa,
		0x0ff7, 0xffae, 0xffaf, 0xffb0,
		0xffb1, 0xffb2, 0xffb3, 0xffb4,
		0xffb5, 0x01f8, 0x7fc0, 0xffb6,
		0xffb7, 0xffb8, 0xffb9, 0xffba,
		0xffbb, 0xffbc, 0xffbd, 0x01f9,
		0xffbe, 0xffbf, 0xffc0, 0xffc1,
		0xffc2, 0xffc3, 0xffc4, 0xffc5,
		0xffc6, 0x01fa, 0xffc7, 0xffc8,
		0xffc9, 0xffca, 0xffcb, 0xffcc,
		0xffcd, 0xffce, 0xffcf, 0x03f9,
		0xffd0, 0xffd1, 0xffd2, 0xffd3,
		0xffd4, 0xffd5, 0xffd6, 0xffd7,
		0xffd8, 0x03fa, 0xffd9, 0xffda,
		0xffdb, 0xffdc, 0xffdd, 0xffde,
		0xffdf, 0xffe0, 0xffe1, 0x07f8,
		0xffe2, 0xffe3, 0xffe4, 0xffe5,
		0xffe6, 0xffe7, 0xffe8, 0xffe9,
		0xffea, 0xffeb, 0xffec, 0xffed,
		0xffee, 0xffef, 0xfff0, 0xfff1,
		0xfff2, 0xfff3, 0xfff4, 0x07f9,
		0xfff5, 0xfff6, 0xfff7, 0xfff8,
		0xfff9, 0xfffa, 0xfffb, 0xfffc,
		0xfffd, 0xfffe };
static const G4HuffmanCodeTable	YAcHuffmanT = {
	162, 
	(int*)YAcSizeT,
	(int*)YAcCodeT 
};

static const int		YEOBidx = 0;
static const int		YZRLidx = 151;


static const int	CAcSizeT[] = {
		 2,  2,  3,  4,  5,  5,  6,  7,
		 9, 10, 12,  4,  6,  8,  9, 11,
		12, 16, 16, 16, 16,  5,  8, 10,
		12, 15, 16, 16, 16, 16, 16,  5,
		 8, 10, 12, 16, 16, 16, 16, 16,
		16,  6,  9, 16, 16, 16, 16, 16,
		16, 16, 16,  6, 10, 16, 16, 16,
		16, 16, 16, 16, 16,  7, 11, 16,
		16, 16, 16, 16, 16, 16, 16,  7,
		11, 16, 16, 16, 16, 16, 16, 16,
		16,  8, 16, 16, 16, 16, 16, 16,
		16, 16, 16,  9, 16, 16, 16, 16,
		16, 16, 16, 16, 16,  9, 16, 16,
		16, 16, 16, 16, 16, 16, 16,  9,
		16, 16, 16, 16, 16, 16, 16, 16,
		16,  9, 16, 16, 16, 16, 16, 16,
		16, 16, 16, 11, 16, 16, 16, 16,
		16, 16, 16, 16, 16, 14, 16, 16,
		16, 16, 16, 16, 16, 16, 16, 10,
		15, 16, 16, 16, 16, 16, 16, 16,
		16, 16 };
static const int	CAcCodeT[] = { 
		0x0000, 0x0001, 0x0004, 0x000a,
		0x0018, 0x0019, 0x0038, 0x0078,
		0x01f4, 0x03f6, 0x0ff4, 0x000b,
		0x0039, 0x00f6, 0x01f5, 0x07f6,
		0x0ff5, 0xff88, 0xff89, 0xff8a,
		0xff8b, 0x001a, 0x00f7, 0x03f7,
		0x0ff6, 0x7fc2, 0xff8c, 0xff8d,
		0xff8e, 0xff8f, 0xff90, 0x001b,
		0x00f8, 0x03f8, 0x0ff7, 0xff91,
		0xff92, 0xff93, 0xff94, 0xff95,
		0xff96, 0x003a, 0x01f6, 0xff97,
		0xff98, 0xff99, 0xff9a, 0xff9b,
		0xff9c, 0xff9d, 0xff9e, 0x003b,
		0x03f9, 0xff9f, 0xffa0, 0xffa1,
		0xffa2, 0xffa3, 0xffa4, 0xffa5,
		0xffa6, 0x0079, 0x07f7, 0xffa7,
		0xffa8, 0xffa9, 0xffaa, 0xffab,
		0xffac, 0xffad, 0xffae, 0x007a,
		0x07f8, 0xffaf, 0xffb0, 0xffb1,
		0xffb2, 0xffb3, 0xffb4, 0xffb5,
		0xffb6, 0x00f9, 0xffb7, 0xffb8,
		0xffb9, 0xffba, 0xffbb, 0xffbc,
		0xffbd, 0xffbe, 0xffbf, 0x01f7,
		0xffc0, 0xffc1, 0xffc2, 0xffc3,
		0xffc4, 0xffc5, 0xffc6, 0xffc7,
		0xffc8, 0x01f8, 0xffc9, 0xffca,
		0xffcb, 0xffcc, 0xffcd, 0xffce,
		0xffcf, 0xffd0, 0xffd1, 0x01f9,
		0xffd2, 0xffd3, 0xffd4, 0xffd5,
		0xffd6, 0xffd7, 0xffd8, 0xffd9,
		0xffda, 0x01fa, 0xffdb, 0xffdc,
		0xffdd, 0xffde, 0xffdf, 0xffe0,
		0xffe1, 0xffe2, 0xffe3, 0x07f9,
		0xffe4, 0xffe5, 0xffe6, 0xffe7,
		0xffe8, 0xffe9, 0xffea, 0xffeb,
		0xffec, 0x3fe0, 0xffed, 0xffee,
		0xffef, 0xfff0, 0xfff1, 0xfff2,
		0xfff3, 0xfff4, 0xfff5, 0x03fa,
		0x7fc3, 0xfff6, 0xfff7, 0xfff8,
		0xfff9, 0xfffa, 0xfffb, 0xfffc,
		0xfffd, 0xfffe };
static const G4HuffmanCodeTable	CAcHuffmanT = {
	162,
	(int*)CAcSizeT,
	(int*)CAcCodeT 
};

static const int		CEOBidx = 0;
static const int		CZRLidx = 151;

//HuffmanCode

static const int		DcDhtLength = 0x21;
static const int		AcDhtLength = 0xb7;

static const u_char	YDcDht[] = {
	0xff, 0xc4,		
	0x00, 0x1f,			
	0x00,			 
	0x00, 0x01, 0x05, 0x01, 0x01, 0x01, 0x01, 0x01,	 
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,	
	0x08, 0x09, 0x0a, 0x0b
};

static const u_char	CDcDht[] = {	
	0xff, 0xc4,	
	0x00, 0x1f,			
	0x01,			 
	0x00, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,	 
	0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,	
	0x08, 0x09, 0x0a, 0x0b
};

static const u_char	YAcDht[] = {	
	0xff, 0xc4,			
	0x00, 0xb5,			
	0x10,			 

	0x00, 0x02, 0x01, 0x03, 0x03, 0x02, 0x04, 0x03,	 
	0x05, 0x05, 0x04, 0x04, 0x00, 0x00, 0x01, 0x7d,

	0x01, 0x02, 0x03, 0x00, 0x04, 0x11, 0x05, 0x12,	
	0x21, 0x31, 0x41, 0x06, 0x13, 0x51, 0x61, 0x07,
	0x22, 0x71, 0x14, 0x32, 0x81, 0x91, 0xa1, 0x08,
	0x23, 0x42, 0xb1, 0xc1, 0x15, 0x52, 0xd1, 0xf0,
	0x24, 0x33, 0x62, 0x72, 0x82, 0x09, 0x0a, 0x16,
	0x17, 0x18, 0x19, 0x1a, 0x25, 0x26, 0x27, 0x28,
	0x29, 0x2a, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,
	0x3a, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,
	0x4a, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
	0x5a, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69,
	0x6a, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79,
	0x7a, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89,
	0x8a, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98,
	0x99, 0x9a, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7,
	0xa8, 0xa9, 0xaa, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6,
	0xb7, 0xb8, 0xb9, 0xba, 0xc2, 0xc3, 0xc4, 0xc5,
	0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xd2, 0xd3, 0xd4,
	0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda, 0xe1, 0xe2,
	0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9, 0xea,
	0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8,
	0xf9, 0xfa
};

static const u_char	CAcDht[] = {	
	0xff, 0xc4,			
	0x00, 0xb5,			
	0x11,			 

	0x00, 0x02, 0x01, 0x02, 0x04, 0x04, 0x03, 0x04,	 
	0x07, 0x05, 0x04, 0x04, 0x00, 0x01, 0x02, 0x77,

	0x00, 0x01, 0x02, 0x03, 0x11, 0x04, 0x05, 0x21,	
	0x31, 0x06, 0x12, 0x41, 0x51, 0x07, 0x61, 0x71,
	0x13, 0x22, 0x32, 0x81, 0x08, 0x14, 0x42, 0x91,
	0xa1, 0xb1, 0xc1, 0x09, 0x23, 0x33, 0x52, 0xf0,
	0x15, 0x62, 0x72, 0xd1, 0x0a, 0x16, 0x24, 0x34,
	0xe1, 0x25, 0xf1, 0x17, 0x18, 0x19, 0x1a, 0x26,
	0x27, 0x28, 0x29, 0x2a, 0x35, 0x36, 0x37, 0x38,
	0x39, 0x3a, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
	0x49, 0x4a, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
	0x59, 0x5a, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68,
	0x69, 0x6a, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,
	0x79, 0x7a, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87,
	0x88, 0x89, 0x8a, 0x92, 0x93, 0x94, 0x95, 0x96,
	0x97, 0x98, 0x99, 0x9a, 0xa2, 0xa3, 0xa4, 0xa5,
	0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xb2, 0xb3, 0xb4,
	0xb5, 0xb6, 0xb7, 0xb8, 0xb9, 0xba, 0xc2, 0xc3,
	0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xd2,
	0xd3, 0xd4, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9, 0xda,
	0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9,
	0xea, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8,
	0xf9, 0xfa
};

#endif

