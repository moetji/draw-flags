#include <iostream>
#include <fstream>
import flag;
using namespace std;

int main()
{
	flagIllustrator japflag(200, 300);
	japflag.illustrateFlag(flagtyp::japan);
	string ppmjapflag = japflag.toPPM();
	
	ofstream japfile ("japanflag.ppm");
	
	if(japfile.is_open()){
		japfile <<ppmjapflag;
		japfile.close();
		cout<<"japan flag drawn"<<endl;
	}
	else
	{
		cout<<"image not created"<<endl;
	}
	
	flagIllustrator austflag(200, 300);
	austflag.illustrateFlag(flagtyp::austria);
	string ppmaust = austflag.toPPM();
	
	ofstream austfile ("austriaflag.ppm");
	
	if(austfile.is_open()){
		austfile <<ppmaust;
		austfile.close();
		cout<<"austria flag drawn"<<endl;
	}
	else
	{
		cout<<"image not created"<<endl;
	}
	
	
	flagIllustrator nigeflag(200, 300);
	nigeflag.illustrateFlag(flagtyp::nigeria);
	string ppm = nigeflag.toPPM();
	
	ofstream nigeoutfile ("nigeriaflag.ppm");
	
	if(nigeoutfile.is_open()){
		nigeoutfile <<ppm;
		nigeoutfile.close();
		cout<<"nigeria flag drawn"<<endl;
	}
	else
	{
		cout<<"image not created"<<endl;
	}
	
	
		
	return 0;
}