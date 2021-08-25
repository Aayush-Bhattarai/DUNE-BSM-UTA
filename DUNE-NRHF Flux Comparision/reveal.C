//This program cast and make changes in the histograms saved in the ROOT File and generates stacked histogram

void reveal()
{
	//Reading generated ROOT File
	TFile* fInput = new TFile("stackedHist.root","READ");

	//Casting saved histograms from ROOT File
	TH1D* h = (TH1D*)fInput->Get("NRHF_Hist");
	TH1D* h1 = (TH1D*)fInput->Get("DUNE_Hist");
	
	//Setting Canvas
	TCanvas* c = new TCanvas();
	c->SetGrid();
	c->SetTicks();
	
	//NRHF Hist
	h->SetLineColor(kGreen);
	h->GetYaxis()->SetRangeUser(0,0.0004); //Setting Y-axis limit	
	h->Draw();
	h->Fit("gaus");
	h->GetFunction("gaus")->SetLineColor(3);
	
	//DUNE Hist
	h1->SetLineColor(kBlue);
	h1->Draw("SAME");
	h1->Fit("gaus");
	h1->GetFunction("gaus")->SetLineColor(4);
	
	//Setting Legend
	auto legend = new TLegend(0.9, 0.58, 0.55, 0.76);
	legend->SetHeader("Data Set", "C");
	legend->AddEntry(h, "NRHF");
	legend->AddEntry(h1, "DUNE");
	legend->Draw();
}
