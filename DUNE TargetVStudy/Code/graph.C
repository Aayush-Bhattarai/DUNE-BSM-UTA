//This Program plots a graph two different graphs in same canvas
//Energy cut plot for electron neutrino

void graph()
{
	Int_t const i = 6; //six data points
	TCanvas* c1 = new TCanvas("c1", "#nu_{e}", 200, 10, 500, 300);
	
	Int_t rad[6] = {1, 2, 4, 10, 20, 40}; //radius in cm
        Int_t nue_loErgy[6] = {665, 1350, 2572, 5305, 8485, 10635}; //Energy > 0.001 GeV
	Int_t nue_hiErgy[6] = {149, 383, 1131, 3641, 6640, 8982}; //Energy <= 0.001

	//TGraph Class
	TGraph* gr1 = new TGraph(i, rad, nue_loErgy);
	gr1->SetTitle("#nu_{e} <= 0.001 GeV; Radius [cm]; Entries");
	gr1->SetMarkerStyle(20);
	gr1->SetMarkerColor(kRed);
	gr1->SetLineColor(kRed);

	gr1->GetYaxis()->SetRangeUser(100, 11000); //Y-axis limit

	TGraph* gr2 = new TGraph(i, rad, nue_hiErgy);
	gr2->SetTitle("#nu_{e} > 0.001 GeV");
	gr2->SetMarkerStyle(21);
	gr2->SetMarkerColor(kBlue);
	gr2->SetLineColor(kBlue);

	gr1->Draw("ALP");
	gr2->Draw("PLSAME");
	c1->BuildLegend();


}
