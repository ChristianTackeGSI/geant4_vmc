// $Id: TG4UniformMagneticField.cxx,v 1.1.1.1 2002/06/16 15:57:35 hristov Exp $
// Category: geometry
//
// Author: I. Hrivnacova
//
// Class TG4UniformMagneticField
// -----------------------------
// See the class description in the header file.
// According to:
// Id: ExN02MagneticField.cc,v 1.1 1999/01/07 16:05:49 gunter Exp 
// GEANT4 tag Name: geant4-00-01

#include "TG4UniformMagneticField.h"

#include <G4FieldManager.hh>
#include <G4TransportationManager.hh>

//  Constructors

//_____________________________________________________________________________
TG4UniformMagneticField::TG4UniformMagneticField()
  : G4UniformMagField(G4ThreeVector()) 
{
//
  GetGlobalFieldManager()->SetDetectorField(this);
  GetGlobalFieldManager()->CreateChordFinder(this);
}

//_____________________________________________________________________________
TG4UniformMagneticField::TG4UniformMagneticField(G4ThreeVector fieldVector)
  : G4UniformMagField(fieldVector)
{    
//
  GetGlobalFieldManager()->SetDetectorField(this);
  GetGlobalFieldManager()->CreateChordFinder(this);
}

//_____________________________________________________________________________
TG4UniformMagneticField::TG4UniformMagneticField(const TG4UniformMagneticField& right)
  : G4UniformMagField(right)
{
//  
  GetGlobalFieldManager()->SetDetectorField(this);
  GetGlobalFieldManager()->CreateChordFinder(this);
}

//_____________________________________________________________________________
TG4UniformMagneticField::~TG4UniformMagneticField() {
//
}

// operators

//_____________________________________________________________________________
TG4UniformMagneticField& 
TG4UniformMagneticField::operator=(const TG4UniformMagneticField& right)
{				  
  // check assignement to self
  if (this == &right) return *this;

  // base class assignement
  G4UniformMagField::operator=(right);
  
  return *this;
}  

// public methods

//_____________________________________________________________________________
void TG4UniformMagneticField::SetFieldValue(G4double fieldValue)
{
// Sets the value of the Global Field to fieldValue along Z.
// ---

  //G4UniformMagField::SetFieldValue(G4ThreeVector(0,0,fieldValue));
  G4UniformMagField::SetFieldValue(G4ThreeVector(fieldValue,0, 0));
}

//_____________________________________________________________________________
void TG4UniformMagneticField::SetFieldValue(G4ThreeVector fieldVector)
{
// Sets the value of the Global Field.
// ---

  // Find the Field Manager for the global field
  G4FieldManager* fieldMgr= GetGlobalFieldManager();
    
  if(fieldVector!=G4ThreeVector(0.,0.,0.)) { 
    G4UniformMagField::SetFieldValue(fieldVector); 
    fieldMgr->SetDetectorField(this);
  } 
  else {
    // If the new field's value is Zero, then it is best to
    //  insure that it is not used for propagation.
    G4MagneticField* magField = 0;
    fieldMgr->SetDetectorField(magField);
  }
}

//_____________________________________________________________________________
G4FieldManager*  TG4UniformMagneticField::GetGlobalFieldManager() const
{
// Utility method
// ---

  return G4TransportationManager::GetTransportationManager()
           ->GetFieldManager();
}
    