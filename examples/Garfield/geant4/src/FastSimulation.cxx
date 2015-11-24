//------------------------------------------------
// The Virtual Monte Carlo examples
// Copyright (C) 2007 - 2015 Ivana Hrivnacova
// All rights reserved.
//
// For the licensing terms see geant4_vmc/LICENSE.
// Contact: root-vmc@cern.ch
//-------------------------------------------------

/// \file Garfield/geant4/src/FastSimulation.cxx
/// \brief Implementation of the Garfield::FastSimulation class 
///
/// Garfield garfieldpp example adapted to Virtual Monte Carlo.
///
/// \date 28/10/2015
/// \author I. Hrivnacova; IPN, Orsay

#include "FastSimulation.h"
#include "GarfieldG4FastSimulationModel.h"
#include "GarfieldPhysics.h"

#include <G4RegionStore.hh>
#include <G4Material.hh>
#include <GFlashHomoShowerParameterisation.hh>
#include <G4FastSimulationManager.hh>
#include <GFlashShowerModel.hh>
#include <GFlashHitMaker.hh>
#include <GFlashParticleBounds.hh>
#include <G4NistManager.hh>

#include <Riostream.h>

using namespace std;

namespace Garfield
{

//_____________________________________________________________________________
FastSimulation::FastSimulation() 
  : TG4VUserFastSimulation()
{
/// Standard constructor

  cout << "FastSimulation::FastSimulation" << endl;

  //Get instance of singleton GarfieldPhysics before creation of the physics list
  GarfieldPhysics* garfieldPhysics = GarfieldPhysics::GetInstance();
  cout << "garfieldPhysics " << garfieldPhysics << endl;


  // Enable GarfieldModel for different particle types and energy ranges
  double minEnergy_keV = 100;
  double maxEnergy_keV = 1e+12;

  //garfieldPhysics->AddParticleName("e-", minEnergy_keV, maxEnergy_keV);
  //garfieldPhysics->AddParticleName("e+", minEnergy_keV, maxEnergy_keV);

  //garfieldPhysics->AddParticleName("mu-", minEnergy_keV, maxEnergy_keV);
  garfieldPhysics->AddParticleName("mu+", minEnergy_keV, maxEnergy_keV);

  //garfieldPhysics->AddParticleName("pi-", minEnergy_keV, maxEnergy_keV);
  //garfieldPhysics->AddParticleName("pi+", minEnergy_keV, maxEnergy_keV);
  //garfieldPhysics->AddParticleName("kaon-", minEnergy_keV, maxEnergy_keV);
  //garfieldPhysics->AddParticleName("kaon+", minEnergy_keV, maxEnergy_keV);
  //garfieldPhysics->AddParticleName("proton", minEnergy_keV, maxEnergy_keV);
  //garfieldPhysics->AddParticleName("anti_proton", minEnergy_keV, maxEnergy_keV);
  //garfieldPhysics->AddParticleName("deuteron", minEnergy_keV, maxEnergy_keV);
  //garfieldPhysics->AddParticleName("alpha", minEnergy_keV, maxEnergy_keV);

  //garfieldPhysics->EnableCreateSecondariesInGeant4();
  garfieldPhysics->DisableCreateSecondariesInGeant4();

/*
  // Create fast simulation model configuration.
  // This will generate UI commands which can be used to set particles
  // and regions where the model will be applied
  SetModel("garfieldModel");

  // In the following calls users can select the particles and regions
  // which the fast simulation model(s) will be applied to. 
  // The setting can be done also interactively via UI commands.
  SetModelParticles("garfieldModel", "all");
  SetModelRegions("garfieldModel", "AirB");
*/
}

//_____________________________________________________________________________
FastSimulation::~FastSimulation()
{
/// Destructor

  // can't we just delete the instance ??
  GarfieldPhysics::Dispose();
}

//
// protected methods
//

//_____________________________________________________________________________
void  FastSimulation::Construct()
{
/// This function must be overriden in user class and users should create
/// the simulation models and register them to VMC framework

  G4cout<<"Construct Garfield model."<<G4endl;

  // Create the fast simulation model
  GarfieldG4FastSimulationModel* garfieldModel 
    = new GarfieldG4FastSimulationModel("garfieldModel");

  // Register the model in VMC frameworks
  Register(garfieldModel);

  G4cout<<"end construct Garfield model."<<G4endl;
  //
  // end Initializing shower model
}

} 
