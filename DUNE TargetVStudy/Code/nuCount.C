//This program counts the number of neutrino in the ROOT FIle
//Neutrino count for angle < 0.013 radian
void nuCount()
{
	TFile* fInput = new TFile("TargetVStudy_20cm_POT1000.root", "READ"); //READ
	TTree* tree = (TTree*)fInput->Get("DUNETargetSim");

	Char_t pid[32];
	Double_t kEnergy; //Kinetic Energy
	Double_t px, py, pz; //momentum components
	
      	tree->SetBranchAddress("pid", &pid);
	tree->SetBranchAddress("kineticEnergy", &kEnergy);	
	tree->SetBranchAddress("px", &px);
	tree->SetBranchAddress("py", &py);
	tree->SetBranchAddress("pz", &pz);
	
	Int_t nueCount = 0;
	Int_t numuCount = 0;
	Int_t antinueCount = 0;
	Int_t antinumuCount = 0;

	Int_t nEntries = tree->GetEntries("px");
//	cout << nEntries << endl; [1480905]
	
	for(Int_t i = 0; i < nEntries; i++){
		tree->GetEntry(i);
	//	cout << px << endl;
		
		if(strcmp(pid, "nu_e") == 0) {
			Double_t theta = TMath::ACos(pz/TMath::Sqrt(px*px+py*py+pz*pz)); 
                       
			if(theta < 0.013) { 
				nueCount++;
			}
		}

		if(strcmp(pid, "nu_mu") == 0) {
			Double_t theta = TMath::ACos(pz/TMath::Sqrt(px*px+py*py+pz*pz)); 
                       
			if(theta < 0.013) { 
				numuCount++;
			}
		}

		if(strcmp(pid, "anti_nu_e") == 0) {
			Double_t theta = TMath::ACos(pz/TMath::Sqrt(px*px+py*py+pz*pz)); 
                       
			if(theta < 0.013) { 
				antinueCount++;
			}
		}

		if(strcmp(pid, "anti_nu_mu") == 0) {
			Double_t theta = TMath::ACos(pz/TMath::Sqrt(px*px+py*py+pz*pz)); 
                       
			if(theta < 0.013) { 
				antinumuCount++;
			}

		}
	}

	cout << "The electron neutrino count is:" << nueCount << endl;
	cout << "The muon neutrino count is:" << numuCount << endl;
	cout << "The anti electron neutrino count is:" << antinueCount << endl;
	cout << "The anti muon neutrino count is:" << antinumuCount << endl;

}
