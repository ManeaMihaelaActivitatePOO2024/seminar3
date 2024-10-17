#include <iostream>
using namespace std;

class Masina 
{
public:
	int nrRoti;
	string marca;
	float pret;
	static int TVA;
	const int anFabricatie;

	Masina():anFabricatie(2024), nrRoti(4) //constructor
	{
		this->marca = "Dacia";
		this->pret = 5000;
	}

	Masina(int _nrRoti, string marca, float pret, int an):anFabricatie(an)
	{
		this->nrRoti = _nrRoti;
		this->marca = marca;
		this->pret = pret;
	
	}

	void afisare()
	{
		cout << "Marca:" << this->marca << endl;
		cout << "Nr roti:" << this->nrRoti << endl;
		cout << "Pret:" << this->pret << endl;
		cout << "TVA:" << this->TVA << endl;
		cout << "An fabricatie:" << this->anFabricatie << endl;
	}

	float calculeazaPretTotal()
	{
		return this->pret + (this->pret * (Masina::TVA / 100.0f));//sau punem (float) in fata la Masina
	}

	static void modificaTVA( int noulTVA)
	{
		if (noulTVA > 0)
		{
			Masina::TVA = noulTVA;
		}
	}

	static float calculeazaPretTotalVector(int nrMasini, Masina* vector)
	{
		float pretTotal = 0;
		for (int i = 0; i < nrMasini; i++)
		{
			pretTotal += vector[i].calculeazaPretTotal();
		}
		return pretTotal;
		
	}
};

int Masina::TVA = 19; //initializare atribute statice

int main()
{

	Masina m1;
	m1.afisare();

	Masina m2(4, "Audi", 7000, 2020);
	m2.afisare();

	Masina::modificaTVA(21);

	Masina* pointer = new Masina(6, "Volvo", 20000, 2022);//initializare pointer
	pointer->afisare();//afisare pointer MEREU cu ->, pt adresa

	cout << "Pret total:" << pointer->calculeazaPretTotal() << endl;

	int nrMasini = 3;
	Masina* vector;
	vector = new Masina[nrMasini];

	for (int i = 0; i < nrMasini; i++)
	{
		vector[i].afisare(); 
	}

	cout << "Pret total flota:" << Masina::calculeazaPretTotalVector(nrMasini, vector) << endl;
	//-> - dereferentiere + accesare
	//[] - deplasare + dereferentiere
	//. - accesare


	return 1000;

}