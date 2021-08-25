//This Program gives the output file with data for selected particle from the ROOT File

void Root2Txt()
{
	TFile* fInput = new TFile("TargetVStudy_1cm_POT1000.root", "READ");
	TTree* tree = (TTree*)fInput->Get("DUNETargetSim");
	
	Double_t kEnergy;
	Char_t pid[32];
	
	tree->SetBranchAddress("kineticEnergy", &kEnergy);
	tree->SetBranchAddress("pid", &pid);

	ofstream output_file;
	output_file.open("nue_data.txt");

	Int_t nEntries = tree->GetEntries("kineticEnergy");

	for (Int_t i = 0; i < nEntries; i++) {
		
		tree->GetEntry(i);

	if(strcmp(pid, "nu_e") == 0) { output_file << kEnergy << endl; }
		
	}

	output_file.close();
}
