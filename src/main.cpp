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
	
	
	vector<int> leervector(const char archivo[255]){
		
		ifstream arch;
		string lectura;
		vector<int> array;
		
		arch.open(archivo, ios::in);
		if(arch.fail()){
	        cout<<"No se pudo abrir el archivo";
	        exit(1);
	    }
	    
		while(!arch.eof()){
	        getline(arch,lectura);
	        int aux;
	        istringstream(lectura) >> aux;
	        array.push_back(aux);
		}
		
		arch.close();
		
		return array;
			
	}
	
	// ----------------------Ordenamiento
	
	
	//intercambio (O(n2))
	vector<int> ordenaIntercambio(vector<int> array, int n){
		int aux;
		for(int i=0; i<n-1; i++){
			for(int j=i+1; j<n; j++){
				if(array[i] > array[j]){
					aux= array[i];
					array[i]= array[j];
					array[j]= aux;
				}		
			}
		}
		return array;
	}
	
	//Burbuja (O(n2))
	vector<int> ordenaBurbuja(vector<int> array, int n){
		int aux;
		for(int i=0; i<n-1; i++){
			for(int j=0; j<n-1; j++){
				if(array[j] > array[j+1]){
					aux= array[j];
					array[j]= array[j+1];
					array[j+1]= aux;
				}
			}
		}
		return array;
	}
	
	//Merge - Mezcla-  
	void Mezcla(vector<int>&array, int first_ind, int mid, int end_ind){
		int leftn = mid - first_ind+1;
		int rightn= end_ind - mid;
		vector<int> left(leftn);
		vector<int> right(rightn);
		
		for(int i=0; i < leftn; i++){
			left[i] = array[first_ind+i];
		}
		for(int j=0; j < (rightn); j++){
			right[j] = array[mid + j+1];
		}
		
		int i = 0;
		int j = 0;
		int k= first_ind;
		
		while(i < leftn && j < rightn){
			if(left[i] < right[j]){
				array[k] = left[i];
				i++;
				k++;
			}else{
				array[k] = right[j];
				j++;
				k++;
			}
		}
		
		while(j < rightn){
			array[k] = right[j];
			j++;
			k++;
		}
		
		while(i < leftn){
			array[k] = left[i];
			i++;
			k++;
		}
	}
	
	//Merge - Recursión
	void mezclarecursion(vector<int>&array, int first_ind, int end_ind){
		
		if(first_ind < end_ind){
			int mid = (end_ind+first_ind)/2;
			mezclarecursion(array, first_ind, mid);
			mezclarecursion(array, mid+1, end_ind);
			Mezcla(array, first_ind, mid, end_ind);	
		}
		
	}
	
	//Merge - retorno de vector  (O(nlogn)
	vector<int> ordenaMezcla(vector<int> array){
		vector<int> auxarray = array;
		mezclarecursion(auxarray, 0, array.size()-1);
		return auxarray;
	}
	
	
	// ----------------------BUSQUEDA
	
	
	//Secuencial (O(n)
	int busqSecuencial(vector<int> array, int clave){ 
		for(int i=0; i<= array.size()-1; i++){
			if(array[i] == clave){
				int aux= array[i];
				return i;
			}
		}
		return -1;
	}
	
	//Binaria (O(nlogn)
	int busqBinaria(vector<int> array, int clave){
		int start = 0;
		int end = array.size()-1;
		int mean;
		
		while(true){
			mean= (start + end)/2;
			if(array[mean] == clave){
				return mean;
			}else{
				if (array[mean]>clave){
					end = mean;
				}else{
					start = mean;
				}
			}
		}
		return -1;
	}
	
	
	
	//Funcion = ejecutar ordenamiento y devolver timepo de ejecuión y vector resultante
	pair< vector<int>, std::chrono::duration<double> > ejecutarFuncion(vector<int> array, string ordenamiento){
		
		using namespace std::chrono;
		vector<int> result;
		//double t_ejecucion;
		high_resolution_clock::time_point t1, t2;
	
		if(ordenamiento == "Intercambio"){
			t1 = high_resolution_clock::now();
			result= ordenaIntercambio(array, array.size());
			t2 = high_resolution_clock::now();
			//t_ejecucion = std::chrono::duration_cast<std::chrono::milliseconds>(done-started).count();
		}
		if(ordenamiento == "Burbuja"){
			t1 = high_resolution_clock::now();
			result= ordenaBurbuja(array, array.size());
			t2 = high_resolution_clock::now();
			//t_ejecucion = std::chrono::duration_cast<std::chrono::milliseconds>(done-started).count(); 
		}
		if(ordenamiento == "Merge"){
			t1 = high_resolution_clock::now();
			result= ordenaMezcla(array);
			t2 = high_resolution_clock::now();
			//t_ejecucion = std::chrono::duration_cast<std::chrono::milliseconds>(done-started).count(); 
			
		}
		duration<double> t_ejecucion = duration_cast<duration<double>>(t2 - t1);
		return make_pair(result, t_ejecucion);
	}
	
	//Funcion = comparar resultado de vectores
	vector<int> compararOrdenamientos(vector<int> array){
		
	    pair<vector<int>, std::chrono::duration<double>> ord_intercambio = ejecutarFuncion(array, "Intercambio");
	    pair<vector<int>, std::chrono::duration<double>> ord_burbujas    = ejecutarFuncion(array, "Burbuja");
	    pair<vector<int>, std::chrono::duration<double>> ord_Merge       = ejecutarFuncion(array, "Merge");
	    
	    if (ord_intercambio.first == ord_burbujas.first && ord_burbujas.first == ord_Merge.first){
	    	cout << "Los vectores resultantes a los tres algoritmos de ordenamiento son IGUALES : ========================================================" <<endl;
	    	cout << "Vector ordenado :                                                           \n" << endl;
	    	for(int i =0; i<= array.size()-1; i++){
	    		cout << ord_Merge.first.at(i) << " ";	
			}
			printf("\n\n\n");
		
			cout << "METODO           Tiempo(ms)  " << endl;
			cout << "================||=====================" << endl;
			cout << "Intercambio      " << fixed << ord_intercambio.second.count() << setprecision(15) << " ms" << endl;
			printf("\n"); 
			cout << "Burbujas         " << fixed << ord_burbujas.second.count() << setprecision(15) << " ms" << endl;
			printf("\n"); 
			cout << "Merge            " << fixed << ord_Merge.second.count() << setprecision(15) << " ms" << endl;
			printf("\n"); 
			printf("\n");
			
			return ord_intercambio.first;
		}else{
			vector<int> v;
			cout << "Los vectores resultantes a los tres algoritmos de ordenamiento NO son IGUALES : ========================================================" <<endl;
			return v;
		}
		
	}
	
	//Funcion = realizar busquedas
	pair< int, std::chrono::duration<double> > ejecutarBusqueda(vector<int> array, int clave, string busqueda){
		
		using namespace std::chrono;
		int result;
		//double t_ejecucion;
		high_resolution_clock::time_point t1, t2;
	
		if(busqueda == "Secuencial"){
			t1 = high_resolution_clock::now();
			result= busqSecuencial(array, clave);
			t2 = high_resolution_clock::now();
			//t_ejecucion = std::chrono::duration_cast<std::chrono::milliseconds>(done-started).count();
		}
		if(busqueda == "Binaria"){
			t1 = high_resolution_clock::now();
			result= busqBinaria(array, clave);
			t2 = high_resolution_clock::now();
			//t_ejecucion = std::chrono::duration_cast<std::chrono::milliseconds>(done-started).count(); 
		}
		duration<double> t_ejecucion = duration_cast<duration<double>>(t2 - t1);
		return make_pair(result, t_ejecucion);
	}
	
	//Funcion = comparar resultado de busquedas
	void compararBusquedas(vector<int> array, int clave, bool ordenado){
		
		if (ordenado == true){
			
			pair<int, std::chrono::duration<double>> busq_binaria    = ejecutarBusqueda(array, clave,  "Binaria");
		    pair<int, std::chrono::duration<double>> busq_secuencial = ejecutarBusqueda(array, clave, "Secuencial");
		    
		    if (busq_secuencial.first == busq_binaria.first ){
		    	cout << "El indice de la clave encontrada con ambos algoritmos es IGUAL : ========================================================" <<endl;
		    	cout << "Clave deseada : " << clave << endl;
		    	cout << "Indice        : " << busq_secuencial.first << endl;
		    	
				printf("\n\n");
			
				cout << "METODO           Tiempo(ms)  " << endl;
				cout << "================||=====================" << endl;
				cout << "Secuencial      " << fixed << busq_secuencial.second.count() << setprecision(15) << " ms" << endl;
				printf("\n"); 
				cout << "Binaria         " << fixed << busq_binaria.second.count() << setprecision(15) << " ms" << endl;
				printf("\n"); 
				printf("\n");
				
			}else{
				cout << "Los Indice de las clave encontrada NO es IGUAL : ========================================================" <<endl;
			}
			
		}else{
			
		    pair<int, std::chrono::duration<double>> busq_secuencial = ejecutarBusqueda(array, clave, "Secuencial");
		    
	    	cout << "Busqueda en arreglo NO ORDENADO : ========================================================" <<endl;
	    	cout << "Clave deseada : " << clave << endl;
	    	cout << "Indice        : " << busq_secuencial.first << endl;
	    	
			printf("\n\n");
		
			cout << "METODO           Tiempo(ms)  " << endl;
			cout << "================||=====================" << endl;
			cout << "Secuencial      " << fixed << busq_secuencial.second.count() << setprecision(15) << " ms" << endl;
			printf("\n"); 
			printf("\n");
																		
		}
	    
		
	}
	
	main(){
		
		cout << "====== Act 1.2 - Algoritmos de Busqueda y Ordenamiento ====== " << "\n";
		cout << "====== Miguel Angel Perez Avila A01369908              ====== " << "\n\n\n";
		clock_t cl = clock();
		
		//CASO1________________________________________________________________________________________________________________________________________________________
		
		//Lectura de arreglo original====
		const char archivo[255] = "datos_caso1.txt";
		vector<int> array1= leervector(archivo);
		cout << "======================================================== INICIO CASO 1 - Vector tamano: "<< array1.size() << " : ========================================================" << "\n";
		cout << "Arreglo original: " << "\n\n";
		for (int i=0; i< array1.size(); i++){		
			cout << array1.at(i) << " ";
		}
		printf("\n\n");
		
		bool ordenado;
		vector<int> array1_ordenado = compararOrdenamientos(array1);
		int largoarreglo1= array1.size()-1;
		int clave1 = array1[std::experimental::randint(0, largoarreglo1)];
		
		compararBusquedas(array1_ordenado, clave1, ordenado = true);
		compararBusquedas(array1, clave1 , ordenado = false);
		
		cout << "======================================================== FIN CASO 1 - Vector tamano: "<< array1.size() << "    : ========================================================" << "\n\n\n";
		
		
		//CASO2________________________________________________________________________________________________________________________________________________________
		
		//Lectura de arreglo original====
		const char archivo2[255] = "datos_caso2.txt";
		vector<int> array2= leervector(archivo2);
		cout << "======================================================== INICIO CASO 2 - Vector tamano: "<< array2.size() << " : ========================================================" << "\n";
		cout << "Arreglo original: " << "\n\n";
		for (int i=0; i< array2.size(); i++){		
			cout << array2.at(i) << " ";
		}
		printf("\n\n");
		
		bool ordenado2;
		vector<int> array2_ordenado = compararOrdenamientos(array2);
		int largoarreglo2= array2.size()-1;
		int clave2 = array2[std::experimental::randint(0, largoarreglo2 )];
		compararBusquedas(array2_ordenado, clave2, ordenado2 = true);
		compararBusquedas(array2, clave2, ordenado2 = false);
		
		cout << "======================================================== FIN CASO 2 - Vector tamano: "<< array2.size() << "    : ========================================================" << "\n\n\n";
		
		
		//CASO3________________________________________________________________________________________________________________________________________________________
		
		//Lectura de arreglo original====0
		const char archivo3[255] = "datos_caso3.txt";
		vector<int> array3= leervector(archivo3);
		cout << "======================================================== INICIO CASO 3 - Vector tamano: "<< array3.size() << " : ========================================================" << "\n";
		cout << "Arreglo original: " << "\n\n";
		for (int i=0; i< array3.size(); i++){		
			cout << array3.at(i) << " ";
		}
		printf("\n\n");
		
		bool ordenado3;
		vector<int> array3_ordenado = compararOrdenamientos(array3);
		int largoarreglo3= array3.size()-1;
		int clave3 = array3[std::experimental::randint(0, largoarreglo3 )];
		compararBusquedas(array3_ordenado, clave3, ordenado3 = true);
		compararBusquedas(array3, clave3, ordenado3 = false);
		
		cout << "======================================================== FIN CASO 3 - Vector tamano: "<< array3.size() << "    : ========================================================" << "\n\n\n";
		
		
		//CASO4________________________________________________________________________________________________________________________________________________________
		
		//Lectura de arreglo original====0
		const char archivo4[255] = "datos_caso4.txt";
		vector<int> array4= leervector(archivo4);
		cout << "======================================================== INICIO CASO 4 - Vector tamano: "<< array4.size() << " : ========================================================" << "\n";
		cout << "Arreglo original: " << "\n\n";
		for (int i=0; i< array4.size(); i++){		
			cout << array4.at(i) << " ";
		}
		
		printf("\n\n");
		
		bool ordenado4;
		vector<int> array4_ordenado = compararOrdenamientos(array4);
		int largoarreglo4= array4.size()-1;
		int clave4 = array4[std::experimental::randint(0, largoarreglo4 )];
		compararBusquedas(array4_ordenado, clave4, ordenado4 = true);
		compararBusquedas(array4, clave4, ordenado4 = false);
		
		cout << "======================================================== FIN CASO 4 - Vector tamano: "<< array4.size() << "    : ========================================================" << "\n\n\n";
		
		
		//_____________________________________________________________________________________________________________________________________________________________
		
		cout << "Tiempo total de ejecucion = " << (clock()-cl)*1000/CLOCKS_PER_SEC << "ms" << endl; //==========FINNNNN
		return 0;
	}
	
