#ifndef ALIRAWEQUIPMENTHEADER_H
#define ALIRAWEQUIPMENTHEADER_H
// @(#)alimdc:$Name$:$Id$
// Author: Fons Rademakers  26/11/99

/* Copyright(c) 1998-2003, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// AliRawEquipmentHeader                                                //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#ifndef ROOT_TObject
#include <TObject.h>
#endif


class AliRawEquipmentHeader : public TObject {

public:
   AliRawEquipmentHeader() { fSize = 0; }
   ~AliRawEquipmentHeader() { }

   void         *HeaderBegin() { return (void *) &fSize; }
   Int_t         HeaderSize() const { return (Long_t) &fBasicElementSizeType - (Long_t) &fSize + sizeof(fBasicElementSizeType); }
   void          Swap();

   UInt_t        GetEquipmentSize() const { return fSize; }
   UInt_t        GetEquipmentType() const { return fEquipmentType; }
   UInt_t        GetId() const { return fEquipmentID; }
   const UInt_t *GetTypeAttribute() const { return fTypeAttribute; }
   UInt_t        GetBasicSizeType() const { return fBasicElementSizeType; }

   enum {
     kAttributeWords = 3
   };

private:
   UInt_t fSize;                            // number of raw data bytes
   UInt_t fEquipmentType;                   // equipment type
   UInt_t fEquipmentID;                     // equipment ID
   UInt_t fTypeAttribute[kAttributeWords];  // system (0,1) and user (2) attributes
   UInt_t fBasicElementSizeType;            // basic element size type

   ClassDef(AliRawEquipmentHeader,1) //Alice equipment header
};

#endif
