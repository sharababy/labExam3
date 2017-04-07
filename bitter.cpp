#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define ITERATIONS 10
#define SIZE 30
#define MAX_VAL 2
#define MAX_GEN_VAL 10000

int actual_random_value();
int generated_random_value(int _probability);
void get_actual_random_value();
void get_generated_random_value();
/*
	This Follows bernoulli distribution.
	We can calculate the value of RV using bernoulli
	and then compare it to the acutal value.

	if ((__aurng() - __aurng.min()) < __p.p() * (__aurng.max() - __aurng.min()))
       return true;
     return false;

*/

float avg_probability;
float probability;

int main(int argc, char const *argv[])
{
	srand(time(NULL));

	get_actual_random_value();
	get_generated_random_value();

	return 0;
}


int actual_random_value(){

	int array[SIZE];
	int random_value =0 ;

	for (int i = 0; i < SIZE; ++i)
	{
			array[i] = (rand() % MAX_VAL);
			random_value += array[i];
	}

	return random_value;

}

void get_actual_random_value(){
	
	int random_value =0;
	float average_of_random_value;
	int sum_of_random_value = 0;
	float sum_of_probability=0;

	for (int i = 0; i < ITERATIONS; ++i)
	{	
		random_value = actual_random_value();
		probability = (float)random_value/SIZE;
		sum_of_random_value += random_value;
		sum_of_probability += probability;

		cout<<"\nActual Random Variable :"<<random_value;
		cout<<" P: "<<probability;		

	}

	avg_probability = (float)sum_of_probability/ITERATIONS;
	average_of_random_value = (float)sum_of_random_value/ITERATIONS;

	cout<<"\n\nAverage Probability: "<<avg_probability;
	cout<<"\nAverage of all Random Variables: "<<average_of_random_value<<endl;


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

void get_generated_random_value(){
	
	int random_value =0;
	float average_of_random_value;
	int sum_of_random_value = 0;
	float sum_of_probability=0;

	for (int i = 0; i < ITERATIONS; ++i)
	{	
		random_value = generated_random_value(avg_probability);
		probability = (float)random_value/SIZE;
		sum_of_random_value += random_value;
		sum_of_probability += probability;

		cout<<"\nGenerated Random Variable :"<<random_value;
		cout<<" P: "<<probability;
	}

	float avg_g_probability = (float)sum_of_probability/ITERATIONS;
	average_of_random_value = (float)sum_of_random_value/ITERATIONS;


	cout<<"\n\nAverage Probability: "<<avg_g_probability;
	cout<<"\nAverage of all Random Variables: "<<average_of_random_value;



}