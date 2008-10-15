#ifndef ALITRDPIDCHECKER_H
#define ALITRDPIDCHECKER_H

//////////////////////////////////////////////////////
//
// Task to check PID performance of the TRD
//
// Author : Alex Wilk <wilka@uni-muenster.de>
//
///////////////////////////////////////////////////////

#include "AliPID.h"
#include "../Cal/AliTRDCalPID.h"

#ifndef ALITRDRECOTASK_H
#include "AliTRDrecoTask.h"
#endif

class TObjArray;
class TList;
class TClonesArray;
class TTreeSRedirector;
class AliTRDReconstructor;
class AliTRDpidChecker : public AliTRDrecoTask 
{

  enum{
    kLQlikelihood    = 0     // place for 2-dim LQ electron likelihood distributions
    ,kNNlikelihood   = 1     // place for NN electron likelihood distributions
    ,kdEdx           = 2     // place for the dE/dx spectra
    ,kPH             = 3     // place for pulse height spectra
    ,kNClus          = 4     // place for the number of clusters per track
    ,kMomentum       = 5     // place for the momentum distribution
    ,kMomentumBin    = 6     // place for the momentum distribution
    ,kGraphLQ        = 7     // place for the 2-dim LQ pion efficiencies
    ,kGraphNN        = 8     // place for the NN pion efficiencies
  };

  enum{
    kGraphStart = kGraphLQ
  };

public:
  AliTRDpidChecker();
  virtual ~AliTRDpidChecker();
  
  void    CreateOutputObjects();
  void    Exec(Option_t *option);
  void    GetRefFigure(Int_t ifig, Int_t &first, Int_t &last, Option_t *opt);  
  void    GetRefFigure(Int_t ifig);
  Bool_t  PostProcess();
  void    Terminate(Option_t *);


private:
  AliTRDpidChecker(const AliTRDpidChecker&);               // not implemented
  AliTRDpidChecker& operator=(const AliTRDpidChecker&);    // not implemented

  AliTRDReconstructor *fReconstructor;     //! reconstructor needed for recalculation the PID

  ClassDef(AliTRDpidChecker, 1); // TRD PID checker
};

#endif
