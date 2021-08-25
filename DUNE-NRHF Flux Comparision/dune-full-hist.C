//This program reads data from the txt file and generates a histogram.
//Muon Neutrino: Energy vs Flux Histogram

{
	//File Input
	ifstream input;
	input.open("histos_g4lbne_v3r5p4_QGSP_BERT_OptimizedEngineeredNov2017_neutrino_DUNEND_00.00mrad_globes_flux.txt"); //DUNE neutrino flux data

	//Histogram for all energy range
	TH1D* h = new TH1D("Flux_hist", "#nu_{mu} : Energy vs. Flux [DUNE]; Energy (GeV); Flux", 480, 0, 120);
	unsigned int i;
	float x; 	// energy
	float y;	// flux
	
	while( !input.eof() )
	{
		input >> x >> y;
		cout << x << ", " << y << endl;
		i = h->FindBin(x);
		h->SetBinContent(i, y);
	}

	//Setting Canvas
	TCanvas* c = new TCanvas();
	c->SetLogy();	
	c->SetTicks();
	h->Draw();
	h->Fit("gaus");
}
