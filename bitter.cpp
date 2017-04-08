#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

#define ITERATIONS 10
#define SIZE 100
#define MAX_VAL 2
#define MAX_GEN_VAL 10000

void find_binomial_dist(float _probability);
long long C(int n, int r);
int show_dots(float pmf);
void find_max_1_2_3(int no_of_occurence[]);

/*
	This Follows binomial distribution.
	
	PMF = nCr * p^r * (1-p)^(n-r)

*/

float avg_probability;
float probability;

int main(int argc, char const *argv[])
{
	srand(time(NULL));


	cout<<"Enter P(occurence of 1) :";

	cin>>probability;

	find_binomial_dist(probability);

	return 0;
}


int generated_random_value(float _probability){

	int array[SIZE];
	int random_value =0 ;


	for (int i = 0; i < SIZE; ++i)
	{
			array[i] = (rand() % MAX_GEN_VAL);
			random_value += (array[i] < (_probability*MAX_GEN_VAL)) ? 1 : 0;
	}
	
	return random_value;

}

void find_binomial_dist(float _probability){
	
	int random_value =0;
	float average_of_random_value;
	int sum_of_random_value = 0;
	float sum_of_probability=0;

	
	int n = 30;
	int r;
	float pmf;
	int no_of_occurence[SIZE];

	for (int i = 0; i < SIZE; ++i)
	{	
		/*
			find pmf for every K=r here:

			PMF = nCr * p^r * (1-p)^(n-r)
		*/

		pmf = C(n,i) * pow(_probability, i) * pow((1- _probability),(n-i));

		cout<<"PMF (X = "<<setw( 3 )<<i<<") = "<<setw( 11 )<<setprecision( 6 )<<pmf;

		no_of_occurence[i] = show_dots(pmf);

	}

	
	find_max_1_2_3(no_of_occurence);


}


long long C(int n, int r) {
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}


int show_dots(float pmf){


	int no_of_dots;

	no_of_dots = pmf * 250;

	/*for (int i = 0; i < no_of_dots; ++i)
	{
		cout<<"+";
	}*/
	
	cout<<endl;


	return no_of_dots;
}


void find_max_1_2_3(int no_of_occurence[]){
	int max = no_of_occurence[0];
	int index_of_max;

	cout<<"\nTop 10 Probable Random Variables: ";

	for (int i = 0; i < 10; ++i)
	{
		max = 0;
		for (int i = 0; i < SIZE; ++i)
		{
			if( no_of_occurence[i] > max){
				index_of_max = i;
				max = no_of_occurence[i];
			}
		}

		cout<<index_of_max<<"\t";

		no_of_occurence[index_of_max] = 0;
	}
	cout<<endl;
}