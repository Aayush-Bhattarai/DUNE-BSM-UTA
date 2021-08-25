//This program gives the stacked histogram of angle distrbution neutrino
//BEFORE angular cut

void StackedAngleDist() 
{
	Int_t d = 304; //distance from tip of the decay pipe to Near Detector
	Double_t r = 1.5; //half the height of Near Detector
	Int_t nBins = 1200; 
	Int_t x_lo = 0;
	Double_t x_hi = 0.05;

	THStack *histos = new THStack("histos", "#bar{#nu}_{e}; Angle [Radian]; Entries");
	TH1D* hist1 = new TH1D("#bar{#nu}_{e}_1cm", "Histogram Title", nBins, x_lo, x_hi);
	hist1->SetLineColor(kRed);

	TH1D* hist2 = new TH1D("#bar{#nu}_{e}_2cm", "Histogram Title", nBins, x_lo, x_hi);
	hist2->SetLineColor(kBlue);

	TH1D* hist3 = new TH1D("#bar{#nu}_{e}_4cm", "Histogram Title", nBins, x_lo, x_hi);
	hist3->SetLineColor(kBlack);

	TH1D* hist4 = new TH1D("#bar{#nu}_{e}_10cm", "Histogram Title", nBins, x_lo, x_hi);
	hist4->SetLineColor(kGreen);

	TH1D* hist5 = new TH1D("#bar{#nu}_{e}_20cm", "Histogram Title", nBins, x_lo, x_hi);
	hist5->SetLineColor(kCyan+1);

	TH1D* hist6 = new TH1D("#bar{#nu}_{e}_40cm", "Histogram Title", nBins, x_lo, x_hi);
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
	Double_t px1, py1, pz1;
	Double_t px2, py2, pz2;
	Double_t px3, py3, pz3;
	Double_t px4, py4, pz4;
	Double_t px5, py5, pz5;
	Double_t px6, py6, pz6;
	
	tree1->SetBranchAddress("pid", &pid);
	tree1->SetBranchAddress("px", &px1);
	tree1->SetBranchAddress("py", &py1);
	tree1->SetBranchAddress("pz", &pz1);

	tree2->SetBranchAddress("pid", &pid);
	tree2->SetBranchAddress("px", &px2);
	tree2->SetBranchAddress("py", &py2);
	tree2->SetBranchAddress("pz", &pz2);

	tree3->SetBranchAddress("pid", &pid);
	tree3->SetBranchAddress("px", &px3);
	tree3->SetBranchAddress("py", &py3);
	tree3->SetBranchAddress("pz", &pz3);
	
	tree4->SetBranchAddress("pid", &pid);
	tree4->SetBranchAddress("px", &px4);
	tree4->SetBranchAddress("py", &py4);
	tree4->SetBranchAddress("pz", &pz4);

	tree5->SetBranchAddress("pid", &pid);
	tree5->SetBranchAddress("px", &px5);
	tree5->SetBranchAddress("py", &py5);
	tree5->SetBranchAddress("pz", &pz5);

	tree6->SetBranchAddress("pid", &pid);
	tree6->SetBranchAddress("px", &px6);
	tree6->SetBranchAddress("py", &py6);
	tree6->SetBranchAddress("pz", &pz6);

	Int_t nEntries1 = tree1->GetEntries("px");

	for (Int_t i = 0; i < nEntries1; i++) {
		tree1->GetEntry(i);
		   if(strcmp(pid, "anti_nu_e") == 0) {
                        Double_t theta = TMath::ACos(pz1/(sqrt(px1*px1+py1*py1+pz1*pz1)));
                                hist1->Fill(theta);
				
                }
	}

	Int_t nEntries2 = tree2->GetEntries("px");

	for (Int_t i = 0; i < nEntries2; i++) {
		tree2->GetEntry(i);
		   if(strcmp(pid, "anti_nu_e") == 0) {
                        Double_t theta = TMath::ACos(pz2/(sqrt(px2*px2+py2*py2+pz2*pz2)));
                                hist2->Fill(theta);
                }

         }
	
	Int_t nEntries3 = tree3->GetEntries("px");

	for (Int_t i = 0; i < nEntries3; i++) {
		tree3->GetEntry(i);
	           if(strcmp(pid, "anti_nu_e") == 0) {
                        Double_t theta = TMath::ACos(pz3/(sqrt(px3*px3+py3*py3+pz3*pz3)));
                                hist3->Fill(theta);
                }

	}

	Int_t nEntries4 = tree4->GetEntries("px");

	for (Int_t i = 0; i < nEntries4; i++) {
		tree4->GetEntry(i);
                    if(strcmp(pid, "anti_nu_e") == 0) {
                        Double_t theta = TMath::ACos(pz4/(sqrt(px4*px4+py4*py4+pz4*pz4)));
                                hist4->Fill(theta);
                }

	}

	Int_t nEntries5 = tree5->GetEntries("px");

	for (Int_t i = 0; i < nEntries5; i++) {
		tree5->GetEntry(i);
                   if(strcmp(pid, "anti_nu_e") == 0) {
                        Double_t theta = TMath::ACos(pz5/(sqrt(px5*px5+py5*py5+pz5*pz5)));
                                hist5->Fill(theta);
                }

	}

	Int_t nEntries6 = tree6->GetEntries("px");

	for (Int_t i = 0; i < nEntries6; i++) {
		tree6->GetEntry(i);	
                    if(strcmp(pid, "anti_nu_e") == 0) {
                        Double_t theta = TMath::ACos(pz6/(sqrt(px6*px6+py6*py6+pz6*pz6)));
                                hist6->Fill(theta);
                }

	}


	TCanvas* cs = new TCanvas();
	cs->SetTicks();
	//cs->SetLogy();
	histos->Draw("nostack");

	//Drawing Legend
        TLegend *leg = new TLegend();
        leg->SetHeader("Target Radius", "C"); //C means center
        leg->AddEntry(hist1, "#bar{#nu}_{e} 1cm", "f"); //f gives a square box
        leg->AddEntry(hist2, "#bar{#nu}_{e} 2cm", "f");
	leg->AddEntry(hist3, "#bar{#nu}_{e} 4cm", "f");
        leg->AddEntry(hist4, "#bar{#nu}_{e} 10cm", "f");
        leg->AddEntry(hist5, "#bar{#nu}_{e} 20cm", "f");
        leg->AddEntry(hist6, "#bar{#nu}_{e} 40cm", "f");
	leg->Draw();
}
