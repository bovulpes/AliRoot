#ifndef ALIPMDCALIBRATOR_H
#define ALIPMDCALIBRATOR_H
/* Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 * See cxx source for full Copyright notice                               */

class TTask;
class TObjArray;
class TH1F;  

class AliPMDCalibData;

class AliPMDCalibrator
{
 public:
  AliPMDCalibrator() ;              // ctor
  AliPMDCalibrator(const AliPMDCalibrator &pmdcalibrator);  // copy constructor
  AliPMDCalibrator &operator=(const AliPMDCalibrator &pmdcalibrator); // assignment op

  virtual ~AliPMDCalibrator() ;     // dtor
  virtual void Exec();
  void CalculateIsoCell();          //calculates gains
  void Init();
  Bool_t Store();
  
 private:

  enum
      {
	  kDet = 2,      // Number of Planes
	  kMaxSMN = 24,  // Number of Modules
	  kMaxRow = 48,  // Number of Rows
	  kMaxCol = 96   // Number of Columns
      };
  Float_t fGainFact[kDet][kMaxSMN][kMaxRow][kMaxCol];
  TH1F *fHsmIso[kDet][kMaxSMN];     //histos of isolated cell modulewise
  TH1F *fHadcIso[kDet][kMaxSMN][kMaxRow][kMaxCol];    // histos of isolated cells cellwise

  AliPMDCalibData *fCalibGain;

ClassDef(AliPMDCalibrator,3)        // description 
};
#endif // AliPMDCALIBRATOR_H
