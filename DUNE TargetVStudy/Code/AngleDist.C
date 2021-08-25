//This program creates stacked histogram by reading a data from a ROOT File
//Different Neutrino Species' Stacked Angle Distribution Histogram

void AngleDist() 
{
	Int_t nBins = 400; //Bin Size = 0.001 GeV 
	Int_t x_lo = 0;
	Double_t x_hi = 0.05;

	//Stacking Histogram with THStack	
	THStack *histos = new THStack("histos", "#nu; Angle [Radian]; Entries");
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
	TFile* fInput = new TFile("TargetVStudy_1cm_POT1000.root", "READ"); //READ
	TTree* tree = (TTree*)fInput->Get("DUNETargetSim");

	Char_t pid[32];  //Particle Identification  
	Double_t Energy; //Kinetic Energy
	Double_t px, py, pz; //Momentum Components

	tree->SetBranchAddress("pid", &pid);
	tree->SetBranchAddress("px", &px);
	tree->SetBranchAddress("py", &py);
	tree->SetBranchAddress("pz", &pz);

	//Looping over to get the data for specific particle and filling the selected histogram
	Int_t nEntries = tree->GetEntries("px");
	for (Int_t i = 0; i < nEntries; i++) 
	{
		tree->GetEntry(i);
		
		for (Int_t j = 0; j < 4; j++) 
		{
		switch(j) {
			case 0:	
				if(strcmp(pid, "nu_e") == 0) { 
					Double_t theta = TMath::ACos(pz/TMath::Sqrt(px*px+py*py+pz*pz)); 
					hist1->Fill(theta); } 
				break;
			case 1: 
				if(strcmp(pid, "nu_mu") == 0) {
					Double_t theta = TMath::ACos(pz/TMath::Sqrt(px*px+py*py+pz*pz));
				       	hist2->Fill(theta); } 
				break;
			case 2: 
				if(strcmp(pid, "anti_nu_e") == 0) { 
					Double_t theta = TMath::ACos(pz/TMath::Sqrt(px*px+py*py+pz*pz));
				       	hist3->Fill(theta); }
				break;
			case 3: 
				if(strcmp(pid, "anti_nu_mu") == 0) { 
					Double_t theta = TMath::ACos(pz/TMath::Sqrt(px*px+py*py+pz*pz));
				       	hist4->Fill(theta); } 
				break;
			default:
			//	cout << "Hey There!" << endl;
				;

			}
		}
	}

	TCanvas* c1 = new TCanvas();
	c1->SetTicks();
	histos->Draw("nostack");
	
	//Drawing Legend
	TLegend *leg = new TLegend();
	leg->SetHeader("#nu types", "C"); //C means center
	leg->AddEntry(hist1, "nu_e", "f"); //f gives a square box
	leg->AddEntry(hist2, "nu_mu", "f");
	leg->AddEntry(hist3, "anti_nu_e", "f");
	leg->AddEntry(hist4, "anti_nu_mu", "f");
	leg->Draw();
}
