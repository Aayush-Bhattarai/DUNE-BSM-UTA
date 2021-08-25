//This program selects specific neutrino type and loops over data of different ROOT file and generates stacked energy distribution histogram
//Energy<=0.001

void CutStacked() 
{
	Int_t nBins = 100;  
	Int_t x_lo = 0.;
	Float_t x_hi = 0.001;

	THStack *histos = new THStack("histos", "#nu_{e}; Energy [GeV]; Entries");
	TH1D* hist1 = new TH1D("#nu_{e}_1cm", "Histogram Title", nBins, x_lo, x_hi);
	hist1->SetLineColor(kRed);

	TH1D* hist2 = new TH1D("#nu_{e}_2cm", "Histogram Title", nBins, x_lo, x_hi);
	hist2->SetLineColor(kBlue);

	TH1D* hist3 = new TH1D("#nu_{e}_4cm", "Histogram Title", nBins, x_lo, x_hi);
	hist3->SetLineColor(kBlack);

	TH1D* hist4 = new TH1D("#nu_{e}_10cm", "Histogram Title", nBins, x_lo, x_hi);
	hist4->SetLineColor(kGreen);

	TH1D* hist5 = new TH1D("#nu_{e}_20cm", "Histogram Title", nBins, x_lo, x_hi);
	hist5->SetLineColor(kCyan+1);

	TH1D* hist6 = new TH1D("#nu_{e}_40cm", "Histogram Title", nBins, x_lo, x_hi);
	hist6->SetLineColor(kMagenta);

	histos->Add(hist1);
	histos->Add(hist2);
	histos->Add(hist3);
	histos->Add(hist4);
	histos->Add(hist5);
	histos->Add(hist6);

	TFile* fInput1 = new TFile("TargetVStudy_1cm_POT1000.root", "READ");
	TTree* tree1 = (TTree*)fInput1->Get("DUNETargetSim");

	TFile* fInput2 = new TFile("TargetVStudy_2cm_POT1000.root", "READ");
	TTree* tree2 = (TTree*)fInput2->Get("DUNETargetSim");

	TFile* fInput3 = new TFile("TargetVStudy_4cm_POT1000.root", "READ");
	TTree* tree3 = (TTree*)fInput3->Get("DUNETargetSim");

	TFile* fInput4 = new TFile("TargetVStudy_10cm_POT1000.root", "READ");
	TTree* tree4 = (TTree*)fInput4->Get("DUNETargetSim");

	TFile* fInput5 = new TFile("TargetVStudy_20cm_POT1000.root", "READ");
	TTree* tree5 = (TTree*)fInput5->Get("DUNETargetSim");

	TFile* fInput6 = new TFile("TargetVStudy_40cm_POT1000.root", "READ");
	TTree* tree6 = (TTree*)fInput6->Get("DUNETargetSim");

	Char_t pid[32];
	Double_t Energy1;
	Double_t Energy2;
	Double_t Energy3;
	Double_t Energy4;
	Double_t Energy5;
	Double_t Energy6;
	
	tree1->SetBranchAddress("pid", &pid);
	tree1->SetBranchAddress("kineticEnergy", &Energy1);

	tree2->SetBranchAddress("pid", &pid);
	tree2->SetBranchAddress("kineticEnergy", &Energy2);

	tree3->SetBranchAddress("pid", &pid);
	tree3->SetBranchAddress("kineticEnergy", &Energy3);

	tree4->SetBranchAddress("pid", &pid);
	tree4->SetBranchAddress("kineticEnergy", &Energy4);

	tree5->SetBranchAddress("pid", &pid);
	tree5->SetBranchAddress("kineticEnergy", &Energy5);

	tree6->SetBranchAddress("pid", &pid);
	tree6->SetBranchAddress("kineticEnergy", &Energy6);

	Int_t nEntries1 = tree1->GetEntries("kineticEnergy");

	for (Int_t i = 0; i < nEntries1; i++) {
		tree1->GetEntry(i);
		if(strcmp(pid, "nu_e") == 0 && Energy1 <= 0.001) { hist1->Fill(Energy1); }
	}

	Int_t nEntries2 = tree2->GetEntries("kineticEnergy");

	for (Int_t i = 0; i < nEntries2; i++) {
		tree2->GetEntry(i);	
		if(strcmp(pid, "nu_e") == 0 && Energy2 <= 0.001) { hist2->Fill(Energy2); } 
	}

	Int_t nEntries3 = tree3->GetEntries("kineticEnergy");

	for (Int_t i = 0; i < nEntries3; i++) {
		tree3->GetEntry(i);
		if(strcmp(pid, "nu_e") == 0 && Energy3 <= 0.001) { hist3->Fill(Energy3); }
	}

	Int_t nEntries4 = tree4->GetEntries("kineticEnergy");

	for (Int_t i = 0; i < nEntries4; i++) {
		tree4->GetEntry(i);	
		if(strcmp(pid, "nu_e") == 0 && Energy4 <= 0.001) { hist4->Fill(Energy4); } 
	}

	Int_t nEntries5 = tree5->GetEntries("kineticEnergy");

	for (Int_t i = 0; i < nEntries5; i++) {
		tree5->GetEntry(i);
		if(strcmp(pid, "nu_e") == 0 && Energy5 <= 0.001) { hist5->Fill(Energy5); }
	}

	Int_t nEntries6 = tree6->GetEntries("kineticEnergy");

	for (Int_t i = 0; i < nEntries6; i++) {
		tree6->GetEntry(i);	
		if(strcmp(pid, "nu_e") == 0 && Energy6 <= 0.001) { hist6->Fill(Energy6); } 
	}


	TCanvas* cs = new TCanvas();
	cs->SetTicks();
	cs->SetLogy();
	histos->Draw("nostack");

	//Drawing Legend
        TLegend *leg = new TLegend();
        leg->SetHeader("Target Radius", "C"); //C means center
        leg->AddEntry(hist1, "#nu_{e} 1cm", "f"); //f gives a square box
        leg->AddEntry(hist2, "#nu_{e} 2cm", "f");
	leg->AddEntry(hist3, "#nu_{e} 4cm", "f");
        leg->AddEntry(hist4, "#nu_{e} 10cm", "f");
        leg->AddEntry(hist5, "#nu_{e} 20cm", "f");
        leg->AddEntry(hist6, "#nu_{e} 40cm", "f");
	leg->Draw();
}
