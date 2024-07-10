namespace std {}
using namespace std;
#include "kkProjectHeaders.h"

#include "kkLinkDef.h"

#include "kkProjectDict.cxx"

struct DeleteObjectFunctor {
   template <typename T>
   void operator()(const T *ptr) const {
      delete ptr;
   }
   template <typename T, typename Q>
   void operator()(const std::pair<T,Q> &) const {
      // Do nothing
   }
   template <typename T, typename Q>
   void operator()(const std::pair<T,Q*> &ptr) const {
      delete ptr.second;
   }
   template <typename T, typename Q>
   void operator()(const std::pair<T*,Q> &ptr) const {
      delete ptr.first;
   }
   template <typename T, typename Q>
   void operator()(const std::pair<T*,Q*> &ptr) const {
      delete ptr.first;
      delete ptr.second;
   }
};

#ifndef Hist4D_cxx
#define Hist4D_cxx
Hist4D::Hist4D() {
   _w_axis = 0;
   _x_axis = 0;
   _y_axis = 0;
   _z_axis = 0;
   _axes = 0;
}
Hist4D &Hist4D::operator=(const Hist4D & rhs)
{
   // This is NOT a copy operator=. This is actually a move operator= (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   TNamed::operator=(const_cast<Hist4D &>( rhs ));
   _w_axis = (const_cast<Hist4D &>( rhs )._w_axis);
   _x_axis = (const_cast<Hist4D &>( rhs )._x_axis);
   _y_axis = (const_cast<Hist4D &>( rhs )._y_axis);
   _z_axis = (const_cast<Hist4D &>( rhs )._z_axis);
   _axes = (const_cast<Hist4D &>( rhs )._axes);
   _hists = (const_cast<Hist4D &>( rhs )._hists);
   _minimum = (const_cast<Hist4D &>( rhs )._minimum);
   _maximum = (const_cast<Hist4D &>( rhs )._maximum);
   Hist4D &modrhs = const_cast<Hist4D &>( rhs );
   modrhs._w_axis = 0;
   modrhs._x_axis = 0;
   modrhs._y_axis = 0;
   modrhs._z_axis = 0;
   modrhs._axes = 0;
   modrhs._hists.clear();
   return *this;
}
Hist4D::Hist4D(const Hist4D & rhs)
   : TNamed(const_cast<Hist4D &>( rhs ))
   , _w_axis(const_cast<Hist4D &>( rhs )._w_axis)
   , _x_axis(const_cast<Hist4D &>( rhs )._x_axis)
   , _y_axis(const_cast<Hist4D &>( rhs )._y_axis)
   , _z_axis(const_cast<Hist4D &>( rhs )._z_axis)
   , _axes(const_cast<Hist4D &>( rhs )._axes)
   , _hists(const_cast<Hist4D &>( rhs )._hists)
   , _minimum(const_cast<Hist4D &>( rhs )._minimum)
   , _maximum(const_cast<Hist4D &>( rhs )._maximum)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   Hist4D &modrhs = const_cast<Hist4D &>( rhs );
   modrhs._w_axis = 0;
   modrhs._x_axis = 0;
   modrhs._y_axis = 0;
   modrhs._z_axis = 0;
   modrhs._axes = 0;
   modrhs._hists.clear();
}
Hist4D::~Hist4D() {
   delete _w_axis;   _w_axis = 0;
   delete _x_axis;   _x_axis = 0;
   delete _y_axis;   _y_axis = 0;
   delete _z_axis;   _z_axis = 0;
   delete _axes;   _axes = 0;
   std::for_each( ( _hists).rbegin(), ( _hists).rend(), DeleteObjectFunctor() );
}
#endif // Hist4D_cxx

#ifndef Histos_cxx
#define Histos_cxx
Histos::Histos() {
}
Histos &Histos::operator=(const Histos & rhs)
{
   // This is NOT a copy operator=. This is actually a move operator= (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   TNamed::operator=(const_cast<Histos &>( rhs ));
   VarNameList = (const_cast<Histos &>( rhs ).VarNameList);
   CutDefList = (const_cast<Histos &>( rhs ).CutDefList);
   setname = (const_cast<Histos &>( rhs ).setname);
   settitle = (const_cast<Histos &>( rhs ).settitle);
   histMap = (const_cast<Histos &>( rhs ).histMap);
   hist4Map = (const_cast<Histos &>( rhs ).hist4Map);
   histConfigMap = (const_cast<Histos &>( rhs ).histConfigMap);
   hist4ConfigMap = (const_cast<Histos &>( rhs ).hist4ConfigMap);
   Histos &modrhs = const_cast<Histos &>( rhs );
   modrhs.VarNameList.clear();
   modrhs.CutDefList.clear();
   modrhs.histMap.clear();
   modrhs.hist4Map.clear();
   modrhs.histConfigMap.clear();
   modrhs.hist4ConfigMap.clear();
   return *this;
}
Histos::Histos(const Histos & rhs)
   : TNamed(const_cast<Histos &>( rhs ))
   , VarNameList(const_cast<Histos &>( rhs ).VarNameList)
   , CutDefList(const_cast<Histos &>( rhs ).CutDefList)
   , setname(const_cast<Histos &>( rhs ).setname)
   , settitle(const_cast<Histos &>( rhs ).settitle)
   , histMap(const_cast<Histos &>( rhs ).histMap)
   , hist4Map(const_cast<Histos &>( rhs ).hist4Map)
   , histConfigMap(const_cast<Histos &>( rhs ).histConfigMap)
   , hist4ConfigMap(const_cast<Histos &>( rhs ).hist4ConfigMap)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   Histos &modrhs = const_cast<Histos &>( rhs );
   modrhs.VarNameList.clear();
   modrhs.CutDefList.clear();
   modrhs.histMap.clear();
   modrhs.hist4Map.clear();
   modrhs.histConfigMap.clear();
   modrhs.hist4ConfigMap.clear();
}
Histos::~Histos() {
   std::for_each( ( CutDefList).rbegin(), ( CutDefList).rend(), DeleteObjectFunctor() );
}
#endif // Histos_cxx

#ifndef CutDef_cxx
#define CutDef_cxx
CutDef::CutDef() {
}
CutDef &CutDef::operator=(const CutDef & rhs)
{
   // This is NOT a copy operator=. This is actually a move operator= (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   TObject::operator=(const_cast<CutDef &>( rhs ));
   varName = (const_cast<CutDef &>( rhs ).varName);
   varTitle = (const_cast<CutDef &>( rhs ).varTitle);
   cutType = (const_cast<CutDef &>( rhs ).cutType);
   cutTitle = (const_cast<CutDef &>( rhs ).cutTitle);
   cutID = (const_cast<CutDef &>( rhs ).cutID);
   min = (const_cast<CutDef &>( rhs ).min);
   max = (const_cast<CutDef &>( rhs ).max);
   center = (const_cast<CutDef &>( rhs ).center);
   delta = (const_cast<CutDef &>( rhs ).delta);
   return *this;
}
CutDef::CutDef(const CutDef & rhs)
   : TObject(const_cast<CutDef &>( rhs ))
   , varName(const_cast<CutDef &>( rhs ).varName)
   , varTitle(const_cast<CutDef &>( rhs ).varTitle)
   , cutType(const_cast<CutDef &>( rhs ).cutType)
   , cutTitle(const_cast<CutDef &>( rhs ).cutTitle)
   , cutID(const_cast<CutDef &>( rhs ).cutID)
   , min(const_cast<CutDef &>( rhs ).min)
   , max(const_cast<CutDef &>( rhs ).max)
   , center(const_cast<CutDef &>( rhs ).center)
   , delta(const_cast<CutDef &>( rhs ).delta)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
CutDef::~CutDef() {
}
#endif // CutDef_cxx

#ifndef HistConfig_cxx
#define HistConfig_cxx
HistConfig::HistConfig() {
}
HistConfig &HistConfig::operator=(const HistConfig & rhs)
{
   // This is NOT a copy operator=. This is actually a move operator= (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   TNamed::operator=(const_cast<HistConfig &>( rhs ));
   logx = (const_cast<HistConfig &>( rhs ).logx);
   logy = (const_cast<HistConfig &>( rhs ).logy);
   logz = (const_cast<HistConfig &>( rhs ).logz);
   logw = (const_cast<HistConfig &>( rhs ).logw);
   return *this;
}
HistConfig::HistConfig(const HistConfig & rhs)
   : TNamed(const_cast<HistConfig &>( rhs ))
   , logx(const_cast<HistConfig &>( rhs ).logx)
   , logy(const_cast<HistConfig &>( rhs ).logy)
   , logz(const_cast<HistConfig &>( rhs ).logz)
   , logw(const_cast<HistConfig &>( rhs ).logw)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
}
HistConfig::~HistConfig() {
}
#endif // HistConfig_cxx

#ifndef BinSet_cxx
#define BinSet_cxx
BinSet::BinSet() {
   binList = 0;
}
BinSet &BinSet::operator=(const BinSet & rhs)
{
   // This is NOT a copy operator=. This is actually a move operator= (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   TObject::operator=(const_cast<BinSet &>( rhs ));
   binList = (const_cast<BinSet &>( rhs ).binList);
   varName = (const_cast<BinSet &>( rhs ).varName);
   varTitle = (const_cast<BinSet &>( rhs ).varTitle);
   BinSet &modrhs = const_cast<BinSet &>( rhs );
   modrhs.binList = 0;
   return *this;
}
BinSet::BinSet(const BinSet & rhs)
   : TObject(const_cast<BinSet &>( rhs ))
   , binList(const_cast<BinSet &>( rhs ).binList)
   , varName(const_cast<BinSet &>( rhs ).varName)
   , varTitle(const_cast<BinSet &>( rhs ).varTitle)
{
   // This is NOT a copy constructor. This is actually a move constructor (for stl container's sake).
   // Use at your own risk!
   (void)rhs; // avoid warning about unused parameter
   BinSet &modrhs = const_cast<BinSet &>( rhs );
   modrhs.binList = 0;
}
BinSet::~BinSet() {
   delete binList;   binList = 0;
}
#endif // BinSet_cxx

