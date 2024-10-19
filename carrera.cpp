#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <cstdlib>  
#include <chrono>
#include <iomanip>

using namespace std;

mutex mtx;
int lugar_actual = 1;//variable para seguir el lugar del auto
vector<int> resultados; // Vector para almacenar el orden de los autos que terminan

void carreraAuto(int id_auto, int distancia_total) {
    int distancia_recorrida = 0;//Inicia en 0 la distancia recorrida por el auto

    while (distancia_recorrida < distancia_total) {
        int movimiento = rand() % 10 + 1;//se genera un movimiento aleatorio entre 1 y 10 metros
        distancia_recorrida += movimiento;//se incremneta la distancia recorrida por el auto
         //comprueba que la distancia recorrida no pase a la distancia total
        if (distancia_recorrida > distancia_total) {
            distancia_recorrida = distancia_total;
        }

        {
            lock_guard<mutex> lock(mtx);
           //imprime el progreso de la carrera de cada auto
            cout << "Auto " << id_auto << " avanza " << movimiento << " metros (total: " << distancia_recorrida << " metros)" << endl;
        }

        this_thread::sleep_for(chrono::milliseconds(100 + rand() % 200));
    }

    {
        lock_guard<mutex> lock(mtx);
        cout << "Auto " << id_auto << " termina la carrera en el lugar " << lugar_actual++ << "!" << endl;
        resultados.push_back(id_auto); // Guardar el ID del auto en el orden de llegada
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <distancia_total> <numero_autos>" << endl;
        return 1;
    }

    int distancia_total = stoi(argv[1]);
    int num_autos = stoi(argv[2]);

    srand(time(0));

    cout << "----------------------------------------" << endl;
    cout << "Distancia total carrera: " << distancia_total << " metros" << endl;
    cout << "----------------------------------------" << endl;

    vector<thread> autos;//vector para guardar los hilos de los autos
   //crea y lanza los hilos para cada uno de los autos
    for (int i = 0; i < num_autos; ++i) {
        autos.emplace_back(carreraAuto, i, distancia_total);
    }
    //espera a que todos los hilos terminen
    for (auto& auto_hilo : autos) {
        auto_hilo.join();
    }
    
    cout << "----------------------------------------" << endl;
    cout << "Lugar  Auto" << endl;

    // Imprimir el resultado en el orden en que los autos terminaron
    for (int i = 0; i < resultados.size(); ++i) {
        cout << (i + 1) << "      " << "Auto" << resultados[i] << endl;  // Usamos el vector resultados para mostrar el orden correcto
    }

    cout << "----------------------------------------" << endl;

    cout << "¡Carrera finalizada!" << endl;
    return 0;
}
