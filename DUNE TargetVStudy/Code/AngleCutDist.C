//This program gives us the angular distribution of neutrino after angle cut 

void angleDist()
{	
	const Double_t r = 1.5; //half of the height of Near Detector
	const Int_t d = 304; //distance from tip of the decay pipe to near detector

	TH1D* hist = new TH1D("hist", "#nu_{e}; Angle [Rad]; Entries", 100, 0, 0.1);

	TFile* fInput = new TFile("TargetVStudy_1cm_POT1000.root", "READ"); //READ
	TTree* tree = (TTree*)fInput->Get("DUNETargetSim");

	Char_t pid[32];
	Double_t px, py, pz; //momentum components
	
      	tree->SetBranchAddress("pid", &pid);
	tree->SetBranchAddress("px", &px);
	tree->SetBranchAddress("py", &py);
	tree->SetBranchAddress("pz", &pz);

	Int_t nEntries = tree->GetEntries("px");
//	cout << nEntries << endl; [1480905]
	
	for(Int_t i = 0; i < nEntries; i++){
		tree->GetEntry(i);
		
		if(strcmp(pid, "nu_mu") == 0) {
			Double_t theta = TMath::ACos(pz/(TMath::Sqrt(px*px+py*py+pz*pz)));
		       if(theta <= TMath::ATan(r/d)) { 
		      hist->Fill(theta); 
				
		}

	}
	}
	
	hist->Draw();
}
