/*******************************************************************************************************************************
This file is a part of the protein side-chain packing software FASPR

Copyright (c) 2020 Xiaoqiang Huang (tommyhuangthu@foxmail.com, xiaoqiah@umich.edu)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation 
files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, 
modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the 
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE 
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR 
IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
********************************************************************************************************************************/
#pragma warning(disable:4305)
#pragma warning(disable:4101)
#pragma warning(disable:4244)

#ifndef SELF_ENERGY_H
#define SELF_ENERGY_H

#include "RotamerBuilder.h"

#define WGT_HBOND       3.0
#define WGT_SSBOND      3.0
#define CACB_DIST_CUT   2.5
#define RESI_DIST_CUT   3.5
#define SEC_CUT        15.0
//atomic parameters
#define RADIUS_C1       2.00
#define RADIUS_C2       1.60
#define RADIUS_C3       2.45
#define RADIUS_C4       2.10
#define RADIUS_C5       2.10
#define RADIUS_C6       1.85
#define RADIUS_C7       2.05
#define RADIUS_C8       1.35
#define RADIUS_O1       1.75
#define RADIUS_O2       1.60
#define RADIUS_O3       1.30
#define RADIUS_O4       1.35
#define RADIUS_N1       1.75
#define RADIUS_N2       1.20
#define RADIUS_N3       1.70
#define RADIUS_N4       1.00
#define RADIUS_S1       1.80
#define RADIUS_S2       1.90
#define DEPTH_C1        0.25
#define DEPTH_C2        0.30
#define DEPTH_C3        0.50
#define DEPTH_C4        0.50
#define DEPTH_C5        0.65
#define DEPTH_C6        0.50
#define DEPTH_C7        0.45
#define DEPTH_C8        0.15
#define DEPTH_O1        0.15
#define DEPTH_O2        0.10
#define DEPTH_O3        0.25
#define DEPTH_O4        0.05
#define DEPTH_N1        0.05
#define DEPTH_N2        0.05
#define DEPTH_N3        0.55
#define DEPTH_N4        0.05
#define DEPTH_S1        0.10
#define DEPTH_S2        0.55
//VDW
#define DSTAR_MIN_CUT   0.47
#define DSTAR_MAX_CUT   2.75
#define VDW_REP_CUT    10.0
//Hbond energy
#define OPT_HBOND_DIST  2.8
#define MIN_HBOND_DIST  2.6
#define MAX_HBOND_DIST  3.2
#define MIN_HBOND_THETA 90.
#define MIN_HBOND_PHI   90.
//SSbond energy
#define OPT_SSBOND_DIST 2.03
#define MIN_SSBOND_DIST 1.73
#define MAX_SSBOND_DIST 2.53
#define OPT_SSBOND_ANGL 105.
#define MIN_SSBOND_ANGL 75.
#define MAX_SSBOND_ANGL 135.

using namespace std;

class SelfEnergy:public RotamerBuilder
{
public:
  IV1 bestrot;
  FV2 eTableSelf;
  IV2 conMap;
  FV2 radius,depth;
  IV2 atomIdx;

  ~SelfEnergy();
  void AssignConMap();

  void SetVdwPar();
  float VDWType(int a,int b,float rij,float dist);
  float VDWEnergyAtomAndAtom(float ddash,float eij);
  float RotamerPreferenceEnergy(int site,int rot);

  void EnergySidechainAndBackbone(int site,FV1 &ener);
  void EnergyRotamerSidechainAndFixedSidechain(int site,FV1 &ener);
  void CalcSelfEnergy();
  float HbondEnergyAtomAndAtom(FV1 &DBxyz,FV1 &Dxyz,FV1 &Axyz,FV1 &ABxyz,float Dangle,float Aangle);
  float SSbondEnergyAtomAndAtom(FV1 &CA1xyz,FV1 &CB1xyz,FV1 &SG1xyz,FV1 &SG2xyz,FV1 &CB2xyz,FV1 &CA2xyz);
  float EnergyPolarSidechainAndBackbone(int site1,int rot1,int site2);
  float EnergyPolarSidechainAndSidechain(int site1,int rot1,int site2,int rot2);
};

#endif
