//This program cast and make changes in the histogram and generate them in divided canvas

void show()
{
	//Reading generated ROOT File
	TFile* fInput = new TFile("stackedHist.root","read");
	
	//Casting saved histogram from ROOT File
	TH1D* h = (TH1D*)fInput->Get("NRHF_Hist");
	TH1D* h1 = (TH1D*)fInput->Get("DUNE_Hist");
	
	//Setting Canvas
        TCanvas* c1 = new TCanvas();
	c1->SetGrid();
	c1->SetTicks();	
	
	c1->Divide(2,1); //Dividing canvas into two columns and one row
	
	//First Column - NRHF Hist
	c1->cd(1);
	h->SetTitle("#nu_{#mu}: Energy vs Flux [NRHF]");
	h->GetYaxis()->SetRangeUser(0,0.0001); //Setting Y-axis limit
	h->Draw();
	h->Fit("gaus");
	h->GetFunction("gaus")->SetLineColor(3);
	
	//Second Column - DUNE Hist
	c1->cd(2);
	h1->SetTitle("#nu_{#mu}: Energy vs Flux [DUNE]");
	h1->Draw();
	h1->Fit("gaus");
	h1->GetFunction("gaus")->SetLineColor(4);
}
