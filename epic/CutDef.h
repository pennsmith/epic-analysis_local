//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Tue May 28 15:00:42 2024 by ROOT version 6.30/02)
//      from the StreamerInfo in file out/coverage.root
//////////////////////////////////////////////////////////


#ifndef CutDef_h
#define CutDef_h
class CutDef;

#include "Rtypes.h"
#include "TObject.h"
#include <TString.h>

class CutDef : public TObject {

public:
// Nested classes declaration.

public:
// Data Members.
   TString     varName;     //
   TString     varTitle;    //
   TString     cutType;     //
   TString     cutTitle;    //
   TString     cutID;       //
   double      min;         //
   double      max;         //
   double      center;      //
   double      delta;       //

   CutDef();
   CutDef(CutDef && ) = default;
   CutDef &operator=(const CutDef & );
   CutDef(const CutDef & );
   virtual ~CutDef();

   ClassDef(CutDef,2); // Generated by MakeProject.
};
#endif
