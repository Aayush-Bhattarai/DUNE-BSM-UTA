//This Program selects the neutrino that will reach the near detector and plots the histogram.
//Mixed with WY's code

Bool_t IsNDTouched(Double_t x, double_t y, Double_t z, Double_t px, Double_t py, Double_t pz);

void angleCut()
{
	TH1D* hist = new TH1D("hist", "#nu angle cut", 200, 0, 120);

	TFile* fInput = new TFile("TargetVStudy_1cm_POT1000.root", "READ"); //READ
	TTree* tree = (TTree*)fInput->Get("DUNETargetSim");

	Char_t pid[32];
	Double_t kEnergy; //Kinetic Energy
	Double_t px, py, pz; //momentum components
	Double_t x, y, z; // vertex position where particle was generated
	
      	tree->SetBranchAddress("pid", &pid);
	tree->SetBranchAddress("kineticEnergy", &kEnergy);	
	tree->SetBranchAddress("px", &px);
	tree->SetBranchAddress("py", &py);
	tree->SetBranchAddress("pz", &pz);
	tree->SetBranchAddress("x", &x);
	tree->SetBranchAddress("y", &y);
	tree->SetBranchAddress("z", &z);

	Int_t nEntries = tree->GetEntries("px");
//	cout << nEntries << endl; [1480905]
	
	for(Int_t i = 0; i < nEntries; i++){
		tree->GetEntry(i);
		
		if(strcmp(pid, "anti_nu_e") == 0) {
			Double_t theta = TMath::ACos(pz/(sqrt(px*px+py*py+pz*pz))); 
                         
			// WY's version
			if( IsNDTouched(x, y, z, px, py, pz) == kTRUE )
			{
				hist->Fill(kEnergy);
			}
		}
	}
	hist->Draw();
}

Bool_t IsNDTouched(Double_t x, Double_t y, Double_t z, Double_t px, Double_t py, Double_t pz)
{
  // coordinate origin is the center of gravity of the target geometry.
  // target geometry has 1.7 cm diameter, 1.5 m long.

  Bool_t result = kFALSE; // 0 is failed, 1 is for a particle hitting the ND.

  const Double_t distance = 574; // distance between the target downstream endpoint to the ND front surface in meter.
  const Double_t target_length = 1.5; // length of target in meter.
  const Double_t nd_x = 4; // size of ND in x-axis (m) (wide)
  const Double_t nd_y = 3; // size of ND in y-axis (m) (tall)
  const Double_t nd_z = 5; // size of ND in z-axis (m) (deep)

  Double_t t = 0; // space line parameter.
  Double_t p = sqrt(px*px + py*py + pz*pz);

  // calculate t parameter at ND surface.
  t = ((distance + 0.5*target_length) - z)/(pz/p);

  // now project the line to the ND surface and find x- and y-coordinates at z = 574m + 0.5*target_length
  Double_t proj_x, proj_y;
  proj_x = t * px/p + x;
  proj_y = t * py/p + y;

  // determine the particle hit the ND or not.
  if( proj_x > -2 && proj_x < 2 && proj_y > -1.5 && proj_y < 1.5 )
  {
    cout << "the incident beam hits the detector" << endl;
    result = kTRUE;
  }
  else
    result = kFALSE;

  return result;
}
