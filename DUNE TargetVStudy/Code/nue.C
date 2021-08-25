//This Program gives the output file with data for selected particle from the ROOT File

void nue()
{
	TFile* fInput = new TFile("TargetVStudy_1cm_POT1000.root", "READ");
	TTree* tree = (TTree*)fInput->Get("DUNETargetSim");
	
	Double_t kEnergy;
	Char_t pid[32];
	
	tree->SetBranchAddress("kineticEnergy", &kEnergy);
	tree->SetBranchAddress("pid", &pid);

	TH1D* hist = new TH1D("nu_e_hist_1cm", "#nu_{e}; Energy [GeV]; Entries", 100, 0, 0.001);

	Int_t nEntries = tree->GetEntries("kineticEnergy");

	for (Int_t i = 0; i < nEntries; i++) {
		
		tree->GetEntry(i);

	if(strcmp(pid, "nu_e") == 0 && kEnergy <= 0.001) { hist->Fill(kEnergy); }
		
	}

	TCanvas* c1 = new TCanvas();
	c1->SetTicks();
	c1->SetLogy();

	hist->Draw();

}
