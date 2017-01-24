
#include "hw1.hpp"

using namespace std;



int main(int argc, char* argv[])
{
	if (argc < 2){
		cout << "Enter a number to continue." << endl;
		exit(0);
	}


//	float n = atof(argv[1]);

	string num = argv[1];
	hw1 convert(num);

	cout << convert ;

    return 0;
}





