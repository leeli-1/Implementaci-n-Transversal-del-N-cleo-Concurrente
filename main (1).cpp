#include <iostream>
 
#include <thread>
 
#include <mutex>
 
#include <map>
 
#include <chrono>
 
#include <vector>
 
#include <cstdlib>
 
#include <ctime>
 
#include <random>
struct Player {
 
    int id;
 
    int x;
 
    int y;
 
    int vida;
 
    int puntos;
 
    bool activo;
 
};
std::map<int, Player> gameState;
 
std::mutex gameStateMutex;
 
bool running = true;
void clientHandler(int clientId) {
 
    std::default_random_engine generator(std::random_device{}());
 
    std::uniform_int_distribution<int> attackDist(0, 4);
 
    while (running) {
 
        {
 
            std::lock_guard<std::mutex> lock(gameStateMutex);
 
            if (!gameState[clientId].activo) continue;
 
            gameState[clientId].x += 1;
 
            gameState[clientId].y += 1;
 
            int objetivo = attackDist(generator);
 
            if (objetivo != clientId && gameState.count(objetivo) && gameState[objetivo].activo) {
 
                gameState[objetivo].vida -= 10;
 
                gameState[clientId].puntos += 10;
 
                if (gameState[objetivo].vida <= 0) {
 
                    gameState[objetivo].activo = false;
 
                }
 
            }
 
        }
 
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
 
    }
 
}
void displayGameState() {
 
    while (running) {
 
        std::system("clear");
 
        {
 
            std::lock_guard<std::mutex> lock(gameStateMutex);
 
            std::cout << "=== Estado del Juego ===\n";
 
            for (auto &p : gameState) {
 
                std::cout << "Jugador " << p.first
<< (p.second.activo ? " [ACTIVO] " : " [ELIMINADO] ")
<< "Pos(" << p.second.x << "," << p.second.y << ") "
<< "Vida: " << p.second.vida
<< " | Puntos: " << p.second.puntos << "\n";
 
            }
 
        }
 
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
 
    }
 
}
int main() {
 
    int numClients = 5;
 
    std::vector<std::thread> clientThreads;
    for (int i = 0; i < numClients; i++) {
 
        {
 
            std::lock_guard<std::mutex> lock(gameStateMutex);
 
            gameState[i] = {i, 0, 0, 100, 0, true};
 
        }
 
        clientThreads.push_back(std::thread(clientHandler, i));
 
    }
    std::thread displayThread(displayGameState);
    std::this_thread::sleep_for(std::chrono::seconds(10));
 
    running = false;
    for (auto &t : clientThreads) {
 
        t.join();
 
    }
 
    displayThread.join();
    std::cout << "\n=== Resultados Finales ===\n";
 
    for (auto &p : gameState) {
 
        std::cout << "Jugador " << p.first
<< " -> Puntos: " << p.second.puntos
<< " | Estado: " << (p.second.activo ? "VIVO" : "ELIMINADO") << "\n";
 
    }
    return 0;
 
}