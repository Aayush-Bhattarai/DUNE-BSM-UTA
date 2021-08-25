//NRHF Signal to Background

float boostFactor(float x) //X is Neutrino Energy
{
	return 0.018/(TMath::Sqrt(4*TMath::Sq(x)-TMath::Sq(0.14)));
}

void enhancement()
{

/*
	//Squared ratio of Near Detector to different target-Dipole (L_DM) distance
	Float_t D1 = 268.96; //When L_DM = 30m
	Float_t D2 = 108.92; //When L_DM = 50m
	Float_t D3 = 29.88;  //When L_DM = 100m
	Int_t D4 = 7;        //When L_DM = 220m
*/
        
	TCanvas *c = new TCanvas();

        TF1* f1 = new TF1("f1", "268.96 * TMath::Sqrt((1-TMath::Exp(-220*boostFactor(x)))/(1-TMath::Exp(-30*boostFactor(x))))", 0, 30);
        f1->SetLineColor(kRed);
	//f1->SetMaximum(150);
	f1->SetMinimum(0);
        c->SetGrid();
        f1->SetTitle("#NRHF S/#sqrt{B} ; E_{#nu} [Gev];  f(L=30m, 50m, 100m, 220m, E_{#nu})");
        f1->Draw();

	TF1* f2 = new TF1("f2", "108.92 * TMath::Sqrt((1-TMath::Exp(-220*boostFactor(x)))/(1-TMath::Exp(-50*boostFactor(x))))", 0, 30);
        f2->SetLineColor(kBlue);
	f2->Draw("SAME");

	TF1* f3 = new TF1("f3", "29.88 * TMath::Sqrt((1-TMath::Exp(-220*boostFactor(x)))/(1-TMath::Exp(-100*boostFactor(x))))", 0, 30);
        f3->SetLineColor(kBlack);
	f3->Draw("SAME");

	TF1* f4 = new TF1("f4", "7 * TMath::Sqrt((1-TMath::Exp(-220*boostFactor(x)))/(1-TMath::Exp(-220*boostFactor(x))))", 0, 30);
        f4->SetLineColor(kGreen+1);
	f4->Draw("SAME");

	auto legend = new TLegend(0.8,0.8,0.5,0.6);
   	legend->SetHeader("#pi^{#pm} Enhancement Factor","C"); // option "C" for centering legend title 
   	legend->AddEntry("f1","L=30m","l"); // l for line
   	legend->AddEntry("f2","L=50m","l");
	legend->AddEntry("f3","L=100m","l");
	legend->AddEntry("f4","L=220m","l");
   	legend->Draw();
}
