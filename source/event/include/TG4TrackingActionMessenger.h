// $Id: TG4TrackingActionMessenger.h,v 1.1 2002/06/20 11:54:18 hristov Exp $
// Category: event
//
// Author: I. Hrivnacova
//
// Class TG4TrackingActionMessenger
// --------------------------------
// Messenger class that defines commands for TG4TrackingAction.
 
#ifndef TG4_TRACKING_ACTION_MESSENGER_H
#define TG4_TRACKING_ACTION_MESSENGER_H 

#include <G4UImessenger.hh>
#include <globals.hh>

class TG4TrackingAction;

class G4UIdirectory;
class G4UIcmdWithAnInteger;

class TG4TrackingActionMessenger: public G4UImessenger
{
  public:
    TG4TrackingActionMessenger(TG4TrackingAction* trackingAction);
    // --> protected
    // TG4TrackingActionMessenger();
    // TG4TrackingActionMessenger(const TG4TrackingActionMessenger& right);
    virtual ~TG4TrackingActionMessenger();
   
    // methods 
    virtual void SetNewValue(G4UIcommand* command, G4String string);
    
  protected:
    TG4TrackingActionMessenger();
    TG4TrackingActionMessenger(const TG4TrackingActionMessenger& right);

    // operators
    TG4TrackingActionMessenger& operator=(
                            const TG4TrackingActionMessenger& right);

  private:
    // data members
    TG4TrackingAction*     fTrackingAction;    //associated class 
    G4UIdirectory*         fTrackingDirectory; //command directory
    G4UIcmdWithAnInteger*  fNewVerboseCmd;     //command: newVerbose
    G4UIcmdWithAnInteger*  fNewVerboseTrackCmd;//command: newVerboseTrack
};

#endif //TG4_TRACKING_ACTION_MESSENGER_H