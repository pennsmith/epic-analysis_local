//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Tue May 28 14:52:26 2024 by ROOT version 6.30/02)
//      from the StreamerInfo in file out/coverage.root
//////////////////////////////////////////////////////////


#ifndef Histos_h
#define Histos_h
class Histos;

#include "Rtypes.h"
#include "TNamed.h"
#include "Riostream.h"
#include <vector>
#include "TString.h"
#include "CutDef.h"
#include <TString.h>
#include <map>
#include "TH1.h"
#include "Hist4D.h"
#ifdef __MAKECINT__
#pragma link C++ class pair<TString,Hist4D* >+;
#endif
#include "HistConfig.h"
#ifdef __MAKECINT__
#pragma link C++ class pair<TString,HistConfig* >+;
#endif

class Histos : public TNamed {

public:
// Nested classes declaration.

public:
// Data Members.
   vector<TString> VarNameList;    //list of histogram names (for external looping)
   vector<CutDef*> CutDefList;     //list of associated cut definitions
   TString         setname;        //
   TString         settitle;       //
   std::vector<std::pair<TString,TH1*> > histMap;        //
   std::vector<std::pair<TString,Hist4D*> > hist4Map;       //
   std::vector<std::pair<TString,HistConfig*> > histConfigMap;    //
   std::vector<std::pair<TString,HistConfig*> > hist4ConfigMap;    //

   Histos();
   Histos(Histos && ) = default;
   Histos &operator=(const Histos & );
   Histos(const Histos & );
   virtual ~Histos();

   ClassDef(Histos,2); // Generated by MakeProject.
};
#endif