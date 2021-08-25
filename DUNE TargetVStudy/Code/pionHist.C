//This program reads a data from a TFile and generates 2D Histogram
//Charged Pions energy and angle distribution

void pionHist()
{
	//2D Histogram 
	TH2D* pionHist = new TH2D("pionHist", "#pi^{-}; Energy [GeV]; Angle [Radian]", 12000, 0, 120, 40, 0, 4);
	
	Char_t pid[32];
	Double_t kEnergy; //Kinetic Energy of Charged Pions
	Double_t px, py, pz; //Momentum components

	//Working with ROOT File for Data Extraction
	TFile* fInput = new TFile("TargetVStudy_40cm_POT1000.root", "READ"); //READ
	TTree* tree = (TTree*)fInput->Get("DUNETargetSim");
	tree->SetBranchAddress("pid", &pid);
	tree->SetBranchAddress("kineticEnergy", &kEnergy);
	tree->SetBranchAddress("px", &px);
	tree->SetBranchAddress("py", &py);
	tree->SetBranchAddress("pz", &pz);
	
	Int_t nentries = tree->GetEntries("kineticEnergy");
	
	for(Int_t i = 0; i < nentries; i++)
	{
		tree->GetEntry(i);
		if(strcmp(pid, "pi-") == 0) { //Selecting positive charged pions 
			Double_t theta = TMath::ACos(pz/TMath::Sqrt(px*px + py*py + pz*pz)); //angle calculation
			pionHist->Fill(kEnergy, theta); }
	}	
	
	TCanvas* c = new TCanvas();
	c->SetLogz();
	c->SetTicks();
	pionHist->Draw("COLZ");
}
