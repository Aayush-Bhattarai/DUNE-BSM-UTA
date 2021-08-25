//This program converts DUNE Neutrino Flux into NRHF System Neutrino Flux 
//NRHF Flux = DUNE Neutrino Flux * Pions Decay Probablity as a function of Neutrino Energy 

//Calculation of Decay Probablity of Charged Pions 
float boostFactor(float nuE) 
{
	return 0.018/(TMath::Sqrt(4*TMath::Sq(nuE)-TMath::Sq(0.14)));
}

float decayformula(float nuE)
{
    	return (1-TMath::Exp(-50*boostFactor(nuE)));  //Distance from Neutrino target to 3D dipole is taken 50m
}

//Converting DUNE Flux into NRHF System Flux
void nrhfCal()
{
	//IO Stream
	ifstream fInput;
	ofstream fOutput;

	fInput.open("histos_g4lbne_v3r5p4_QGSP_BERT_OptimizedEngineeredNov2017_neutrino_DUNEND_00.00mrad_globes_flux.txt"); //DUNE Neutrino Energy-Flux data
	fOutput.open("nrhfflux.txt");

	Double_t nuE, flux; //nuE is Neutrino Energy

	while(!fInput.eof())
	{
		fInput >> nuE >> flux;
		fOutput << nuE << " " << decayformula(nuE) * flux << endl;
	}

	fInput.close();
	fOutput.close();
}
