#include<iostream>
#include<vector>

using namespace std;

class Grafo {
    int V; // Número de vértices
    vector<int> *adj; // Ponteiro para um array contendo listas de adjacências

public:
    Grafo(int V); // Construtor

    void adicionarAresta(int v, int w); // função para adicionar uma aresta ao grafo

    void imprimirGrafo(); // função para imprimir o grafo
};

Grafo::Grafo(int V) {
    this->V = V;
    adj = new vector<int>[V];
}

void Grafo::adicionarAresta(int v, int w) {
    adj[v].push_back(w); // Adiciona w à lista de v
    adj[w].push_back(v); // Adiciona v à lista de w (o grafo é não direcionado)
}

void Grafo::imprimirGrafo() {
    for (int v = 0; v < V; ++v) {
        cout << "\n Lista de adjacência do vértice " << v << "\n cabeça ";
        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}

int main() {
    int V = 5;
    Grafo g(V);
    g.adicionarAresta(0, 1);
    g.adicionarAresta(0, 4);
    g.adicionarAresta(1, 2);
    g.adicionarAresta(1, 3);
    g.adicionarAresta(1, 4);
    g.adicionarAresta(2, 3);
    g.adicionarAresta(3, 4);

    g.imprimirGrafo();

    return 0;
}
