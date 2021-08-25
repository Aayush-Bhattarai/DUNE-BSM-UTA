//This program plots a formula of decay probablity of mother charged pions for different distance between Neutrino target and 3D dipole.

float boostFactor(float x) //x is Neutrino Energy
{
	return 0.018/(TMath::Sqrt(4*TMath::Sq(x)-TMath::Sq(0.14))); 
}

void decayprob()
{
        TCanvas *c = new TCanvas();
	c->SetTicks();
	c->SetGrid();

        //1D Function Class
	TF1* f1 = new TF1("f1", "(1-TMath::Exp(-30*boostFactor(x)))", 0, 30); //For 30m distance
        f1->SetLineColor(kRed);
        f1->SetTitle("#pi^{#pm} Decay Probability (L=30m, 50m, 100m, 220m); E_{#nu} [Gev];  p(E_{#nu})");
        f1->Draw();

	TF1* f2 = new TF1("f2", "(1-TMath::Exp(-50*boostFactor(x)))", 0, 30); //For 50m distance
        f2->SetLineColor(kBlue);
	f2->Draw("SAME");

	TF1* f3 = new TF1("f3", "(1-TMath::Exp(-100*boostFactor(x)))", 0, 30); //For 100m distance
        f3->SetLineColor(kBlack);
	f3->Draw("SAME");
	
	TF1* f4 = new TF1("f4", "1-TMath::Exp(-220*boostFactor(x))", 0, 30); //For 220m distance
        f4->SetLineColor(kGreen);
	f4->Draw("SAME");

	//Setting Legend
	auto legend = new TLegend(0.8,0.8,0.5,0.6);
   	legend->SetHeader("#pi^{#pm} Decay Probability","C"); // option "C" for centering legend title
   	legend->AddEntry("f1","L=30m","l"); // l for line
   	legend->AddEntry("f2","L=50m","l");
	legend->AddEntry("f3","L=100m","l");
	legend->AddEntry("f4","L=220m","l");
   	legend->Draw();
}
