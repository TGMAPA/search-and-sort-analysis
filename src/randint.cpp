#include <stdio.h>
#include <conio.h>
#include <experimental/random>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <String.h>
#include <string.h>

#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <ratio>
#include <time.h>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <bits/stdc++.h>
#include <algorithm>
#include <experimental/random>

using namespace std;


int main()
{
	int i=0;
	//open file for writing
	ofstream fw("datos_caso4.txt", std::ofstream::out);
	vector<int> numbers;
	while(i<48701){
		
		
		
		for(int i=0; i<= 50000-1; i++){
			
			int random_number = std::experimental::randint(0, 2000000);
			bool found = (std::find(numbers.begin(), numbers.end(), random_number) != numbers.end());
			if (found == false){
				numbers.push_back(random_number);
				
			}
			
		}
		
		for(int i=0; i<=numbers.size()-1; i++){
			cout << numbers.at(i) << endl;
		}
		
		cout << "Size= " << numbers.size() << endl;
		
		i= numbers.size();
		
	}
	
	for (int i = 0; i < numbers.size()-1; i++) {
    	fw << numbers.at(i) << "\n";
	}
	fw.close();
	
	return 0;
}
