//This program generates the line plots of the number of specific particle produced for the given radius.
//Comment out different group and draw the needed plot
{
    Int_t n = 6;
    Int_t radius[]  = {1, 2, 4, 10, 20, 40};
    Int_t nu_e[] = {814, 1733, 3703, 8946, 15125, 19617};
    Int_t nu_mu[] = {129, 375, 1082, 3528, 6509, 8661};
    Int_t anti_nu_e[] = {118, 259, 587, 1521, 2547, 3809};
    Int_t anti_nu_mu[] = {116, 337, 1035, 3404, 6372, 8600};
    Int_t gamma[] = {475323, 1056072, 2057666, 3302962, 4256411, 4926955};
    Int_t piplus[] = {10866, 14914, 19491, 25679, 30766, 32730};
    Int_t piminus[] = {10456, 14321,19070, 25272,30094, 32138};
    Int_t pizero[] = {12009, 15790, 19745, 25029, 28802, 30455};
    Int_t positron[] = {35123, 70225, 128975, 204012, 263743, 306741};
    Int_t electron[] = {840956, 2266407, 6203370, 20278080, 41112500, 57675015};
 

/************************************** For Neutrinos *****************************************/
   //TGraph Class
   TGraph *gr1 = new TGraph(n,radius, nu_e);
   gr1->SetLineColor(kGreen+1);
   gr1->SetLineWidth(2);
   gr1->SetMarkerStyle(kFullCircle);
   gr1->SetMarkerColor(kGreen+1);
   
   gr1->GetYaxis()->SetRangeUser(100, 23000); //Setting Y-axis limit

   gr1->SetTitle("#nu_{e}");
   gr1->GetXaxis()->SetTitle("Radius [cm]");
   gr1->GetYaxis()->SetTitle("# of entries");
 
   TGraph *gr2 = new TGraph(n,radius, nu_mu);
   gr2->SetTitle("#nu_{#mu}");
   gr2->SetLineColor(kBlue);
   gr2->SetLineWidth(2);
   gr2->SetMarkerStyle(21);
   gr2->SetMarkerColor(kBlue);

   TGraph *gr3 = new TGraph(n,radius, anti_nu_e);
   gr3->SetTitle("#bar{#nu}_{e}");
   gr3->SetLineColor(kBlack);
   gr3->SetLineWidth(2);
   gr3->SetMarkerStyle(22);
   gr3->SetMarkerColor(kBlack);

   TGraph *gr4 = new TGraph(n,radius, anti_nu_mu);
   gr4->SetTitle("#bar{#nu}_{#mu}");
   gr4->SetLineColor(kRed);
   gr4->SetLineWidth(2);
   gr4->SetMarkerStyle(23);
   gr4->SetMarkerColor(kRed);
   
   //Canvas Setting
   TCanvas *c1 = new TCanvas();
   gr1->Draw("ALP");
   gr2->Draw("PLSAME");
   gr3->Draw("PLSAME");
   gr4->Draw("PLSAME");
   c1->BuildLegend(); //Legend

   //Fitting function
   TF1* ftanh1 = new TF1("ftanh1", "[0]*TMath::TanH([1]*x)", 0, 50);
   TF1* ftanh2 = new TF1("ftanh2", "[0]*TMath::TanH([1]*x)", 0, 50);
   TF1* ftanh3 = new TF1("ftanh3", "[0]*TMath::TanH([1]*x)", 0, 50);
   TF1* ftanh4 = new TF1("ftanh4", "[0]*TMath::TanH([1]*x)", 0, 50);

   ftanh1->SetParLimits(0, 0, 30000);
   ftanh1->SetParLimits(1, 0, 0.1);
   ftanh2->SetParLimits(0, 0, 30000);
   ftanh2->SetParLimits(1, 0, 0.1);
   ftanh3->SetParLimits(0, 0, 30000);
   ftanh3->SetParLimits(1, 0, 0.1);
   ftanh4->SetParLimits(0, 0, 30000);
   ftanh4->SetParLimits(1, 0, 0.1);

   //Function color
   ftanh1->SetLineColor(kGreen+1);
   ftanh2->SetLineColor(kBlue);
   ftanh3->SetLineColor(kBlack);
   ftanh4->SetLineColor(kRed);

   gr1->Fit(ftanh1, "", "", 0, 50);
   gr2->Fit(ftanh2, "", "", 0, 50);
   gr3->Fit(ftanh3, "", "", 0, 50);
   gr4->Fit(ftanh4, "", "", 0, 50);


/************************************** For Photons *******************************************/    

   TGraph *gr5 = new TGraph(n,radius, gamma);
   gr5->SetTitle("#gamma");
   gr5->SetLineColor(kBlue+2);
   gr5->SetLineWidth(2);
   gr5->SetMarkerStyle(24);
   gr5->SetMarkerColor(kBlue);

   gr5->SetTitle("#gamma");
   gr5->GetXaxis()->SetTitle("Target Radius [cm]");
   gr5->GetYaxis()->SetTitle("# of Entries");

   TCanvas *c1 = new TCanvas();
   gr5->Draw("ALP");


/*************************************** For Pions **********************************************/

   TGraph *gr6 = new TGraph(n,radius, piplus);
   gr6->SetLineColor(kRed+1);
   gr6->SetLineWidth(2);
   gr6->SetMarkerStyle(26);
   gr6->SetMarkerColor(kRed+1);
   
   gr6->SetTitle("#pi^{+}");
   gr6->GetXaxis()->SetTitle("Radius [cm]");
   gr6->GetYaxis()->SetTitle("# of entries");
 
   TGraph *gr7 = new TGraph(n,radius, piminus);
   gr7->SetTitle("#pi^{-}");
   gr7->SetLineColor(kBlue);
   gr7->SetLineWidth(2);
   gr7->SetMarkerStyle(27);
   gr7->SetMarkerColor(kBlue);

   TGraph *gr8 = new TGraph(n,radius, pizero);
   gr8->SetTitle("#pi^{0}");
   gr8->SetLineColor(kBlack);
   gr8->SetLineWidth(2);
   gr8->SetMarkerStyle(27);
   gr8->SetMarkerColor(kBlack);
   
   TCanvas *c1 = new TCanvas();
   c1->BuildLegend();
   c1->SetGrid();
   c1->SetTicks()
  
   gr6->Draw("APL");
   gr7->Draw("PLSAME");
   gr8->Draw("PLSAME");
  
/********************************************* For Positron **********************************************/

   TGraph *gr9 = new TGraph(n,radius, positron);
   gr9->SetLineColor(kRed+1);
   gr9->SetLineWidth(2);
   gr9->SetMarkerStyle(20);
   gr9->SetMarkerColor(kRed+1);

   gr9->SetTitle("e^{+}");
   gr9->GetXaxis()->SetTitle("Radius [cm]");
   gr9->GetYaxis()->SetTitle("# of entries");
 
   TCanvas *c1 = new TCanvas();
   c1->SetGrid();
   c1->SetTicks();
  
   gr9->Draw("APL");

/********************************************* For Electron **************************************************/
   
   TGraph *gr10= new TGraph(n,radius, electron);
   gr10->SetTitle("e^{-}");
   gr10->SetLineColor(kOrange+7);
   gr10->SetLineWidth(2);
   gr10->SetMarkerStyle(30);
   gr10->SetMarkerColor(kOrange+7);
 
   gr10->SetTitle("e^{-}");
   gr10->GetXaxis()->SetTitle("Radius [cm]");
   gr10->GetYaxis()->SetTitle("# of entries");
 
   TCanvas *c1 = new TCanvas();
   c1->SetGrid();
   c1->SetTicks();
  
   gr10->Draw("APL");
}     
