//This program creates stacked histogram by reading a data from a ROOT File
//Stacked histogram of energy distribution of four neutrino types for certain target radius

void histo() 
{
	Int_t nBins = 120000; //Bin Size = 0.001 GeV 
	Int_t x_lo = 0;
	Int_t x_hi = 120;

	//Stacking Histogram with THStack	
	THStack *histos = new THStack("histos", "Stacked Neutrino Histograms for Target Radius 4 cm; Energy [GeV]; Entries/0.001 GeV");
	TH1D* hist1 = new TH1D("nu_e_Hist", "Histogram Title", nBins, x_lo, x_hi);
	hist1->SetMarkerStyle(20);
	hist1->SetLineColor(kRed);

	TH1D* hist2 = new TH1D("nu_mu_Hist", "Histogram Title", nBins, x_lo, x_hi);
	hist2->SetMarkerStyle(21);
	hist2->SetLineColor(kBlue);

	TH1D* hist3 = new TH1D("anti_nu_e_Hist", "Histogram Title", nBins, x_lo, x_hi);
	hist3->SetMarkerStyle(22);
	hist3->SetLineColor(kGreen-3);

	TH1D* hist4 = new TH1D("anti_nu_mu_Hist", "Histogram Title", nBins, x_lo, x_hi);
	hist4->SetMarkerStyle(23);
	hist4->SetLineColor(kBlack);

	histos->Add(hist1);
	histos->Add(hist2);
	histos->Add(hist3);
	histos->Add(hist4);

	//Working with ROOT File
	TFile* fInput = new TFile("TargetVStudy_4cm_POT1000.root", "READ"); //READ
	TTree* tree = (TTree*)fInput->Get("DUNETargetSim");

	Char_t pid[32];  //Particle Identification  
	Double_t Energy; //Kinetic Energy
	
	tree->SetBranchAddress("pid", &pid);
	tree->SetBranchAddress("kineticEnergy", &Energy);

	//Looping over to get the data for specific particle and filling the selected histogram
	Int_t nEntries = tree->GetEntries("kineticEnergy");
	for (Int_t i = 0; i < nEntries; i++) 
	{
		tree->GetEntry(i);
		
		for (Int_t j = 0; j < 4; j++) 
		{
		switch(j) {
			case 0:	
				if(strcmp(pid, "nu_e") == 0) { hist1->Fill(Energy); } 
				break;
			case 1: 
				if(strcmp(pid, "nu_mu") == 0) { hist2->Fill(Energy); } 
				break;
			case 2: 
				if(strcmp(pid, "anti_nu_e") == 0) { hist3->Fill(Energy); }
				break;
			case 3: 
				if(strcmp(pid, "anti_nu_mu") == 0) { hist4->Fill(Energy); } 
				break;
			default:
			//	cout << "Hey There!" << endl;
				;

			}
		}
	}

	TCanvas* c1 = new TCanvas();
	c1->SetTicks();
//	c1->SetGrid();
	c1->SetLogy();
	histos->Draw("nostack");
	
	//Drawing Legend
	TLegend *legend = new TLegend();
	legend->SetHeader("#nu types", "C"); //C means center
	legend->AddEntry(hist1, "nu_e", "f"); //f gives a square box
	legend->AddEntry(hist2, "nu_mu", "f");
	legend->AddEntry(hist3, "anti_nu_e", "f");
	legend->AddEntry(hist4, "anti_nu_mu", "f");
	legend->Draw();
}
