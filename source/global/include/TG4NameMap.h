// $Id: TG4NameMap.h,v 1.1 2002/06/20 11:56:10 hristov Exp $
// Category: global
//
// Author: I. Hrivnacova
//
// Class TG4NameMap
// ----------------
// The map container for associated names. 
// The names can be added into map either in pairs (Add() method)
// or standalone - then they are paired with the fSecond data member 
// (AddName() method)

#ifndef TG4_NAME_MAP_H
#define TG4_NAME_MAP_H

#include <g4std/map>
#include <globals.hh>

class TG4NameMap
{
  typedef G4std::map<G4String, G4String, G4std::less<G4String> >  Map;
  typedef Map::iterator        MapIterator;
  typedef Map::const_iterator  MapConstIterator;

  public:
    TG4NameMap();
    // --> protected
    // TG4NameMap(const TG4NameMap& right);
    virtual ~TG4NameMap();

    // methods
    G4bool Add(const G4String& first, const G4String& second);  
    G4bool AddName(const G4String& name);  
    const G4String& GetSecond(const G4String& name);
    void PrintAll() const;
    void Clear();

    // set methods
    void SetSecond(const G4String& name);

  protected:
    TG4NameMap(const TG4NameMap& right);

    // operators
    TG4NameMap& operator=(const TG4NameMap& right);
  
  private:
    // static data members
    static G4String fgUndefined;  //the value of undefined second

    // data members
    Map       fMap;    //map container
    G4String  fSecond; //the current second
};

// inline methods
inline void TG4NameMap::SetSecond(const G4String& secondName)
{ fSecond = secondName; }

#endif //TG4_NAME_MAP_H