//This program counts the number of specific particles generated in the simulation.

void EntriesCount() 
{
	const Int_t pTypes = 10; //Investigating ten particle types
	
	TFile* file = new TFile("TargetVStudy_40cm_POT1000.root", "READ"); //READ
	TTree* tree = (TTree*)file->Get("DUNETargetSim");

	Double_t KEnergy;
	Char_t pid[16];  //List of particles
	
	Int_t nu_e = 0;
	Int_t nu_mu = 0;
	Int_t anti_nu_e = 0;
	Int_t anti_nu_mu = 0;
	Int_t gamma = 0;
	Int_t piplus = 0;
	Int_t piminus = 0;
	Int_t pizero = 0;
	Int_t electron = 0;
	Int_t positron= 0;

	tree->SetBranchAddress("kineticEnergy", &KEnergy);
	tree->SetBranchAddress("pid", &pid);

	Int_t entries = tree->GetEntries("kineticEnergy");

	for(Int_t i = 0; i < entries; i++) 
	{
		tree->GetEntry(i);
		for(Int_t j=0; j < pTypes; j++)
		{
		switch(j) {
		case 0:	
			if (strcmp (pid, "nu_e") == 0) {nu_e++;}
			break;
		
		case 1:	
			if (strcmp (pid, "nu_mu") == 0) {nu_mu++;}
			break;
		
		case 2:	
			if (strcmp (pid, "anti_nu_e") == 0) {anti_nu_e++;}
			break;
		
		case 3:	
			if (strcmp (pid, "anti_nu_mu") == 0) {anti_nu_mu++;}
			break;
		
		case 4:	
			if (strcmp (pid, "gamma") == 0) {gamma++;}
			break;
		
		case 5:	
			if (strcmp (pid, "pi+") == 0) {piplus++;}
			break;
	
		case 6:	
			if (strcmp (pid, "pi-") == 0) {piminus++;}
			break;
	
		case 7:	
			if (strcmp (pid, "pi0") == 0) {pizero++;}
			break;
	
		case 8:	
			if (strcmp (pid, "e-") == 0) {electron++;}
			break;
		
		case 9:	
			if (strcmp (pid, "e+") == 0) {positron++;}
			break;
		default:
		cout << "Hey there!" << endl;
		}
		}
	}

	cout << "The number of electron neutrino:" << nu_e  << endl;
	cout << "The number of muon neutrino:" << nu_mu << endl;
	cout << "The number of anti-electron neutrino:" << anti_nu_e  << endl;
	cout << "The number of anti-muon neutrino:" << anti_nu_mu << endl;
	cout << "The number of gamma:" << gamma << endl;
	cout << "The number of positive pions:" << piplus << endl;
	cout << "The number of negative pions:" << piminus << endl;
	cout << "The number of neutral pions:" << pizero  << endl;
	cout << "The number of electron:" << electron  << endl;
	cout << "The number of positron:" << positron << endl;
	

}
