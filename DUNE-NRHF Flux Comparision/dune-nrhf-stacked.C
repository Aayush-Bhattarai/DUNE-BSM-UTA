//This program read two different txt files with two columns of data and generates stacked histogram
//NRHF-DUNE Muon Neutrino Flux Comparision
//Open with reveal.C to display stacked histogram
//Open with show.C to display histogram on divided canvas

{
	TFile *f = new TFile("stackedHist.root", "RECREATE"); //ROOT File to save histograms
	
	//For NRHF System
	ifstream input;
	input.open("nrhf-data.txt");

	TH1D* h = new TH1D("NRHF_Hist", "#nu_{mu} : Energy vs. Flux; Energy (GeV); Flux", 24, 0, 6);
	unsigned int i;
	float x; 	// energy
	float y;	// flux
	
	//Looping over the data and writing in the histogram
	while( !input.eof() ) 
	{
		input >> x >> y;
		cout << x << ", " << y << endl;
		i = h->FindBin(x);
		h->SetBinContent(i, y);
	}
	
	h->Write();

	//For DUNE
	ifstream input1;
        input1.open("histos_g4lbne_v3r5p4_QGSP_BERT_OptimizedEngineeredNov2017_neutrino_DUNEND_00.00mrad_globes_flux.txt");

        TH1D* h1 = new TH1D("DUNE_Hist", "#nu_{mu} : Energy vs. Flux; Energy (GeV); Flux", 24, 0, 6);
        unsigned int i_1;
        float x_1;        // energy
        float y_1;        // flux

        //Looping over the data and writing in the histogram
	while( !input1.eof() )
        {
                input1 >> x_1 >> y_1;
                cout << x_1 << ", " << y_1 << endl;
                i_1 = h1->FindBin(x_1);
                h1->SetBinContent(i_1, y_1);
        }

        h1->Write();
	f->Close();
}
