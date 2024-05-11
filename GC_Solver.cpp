#include "GC_Solver.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

GC_Solver::GC_Solver(int vertexCount, const std::vector<std::pair<int, int>>& edges)
        : vertexCount(vertexCount), adjMatrix(vertexCount, std::vector<int>(vertexCount, 0)),
          colors(vertexCount, -1), rateList(vertexCount, 0), colored(vertexCount, false) {
    for (const auto& edge : edges) {
        adjMatrix[edge.first][edge.second] = 1;
        adjMatrix[edge.second][edge.first] = 1;
    }
}

void GC_Solver::rateVertices() {
    for (int i = 0; i < vertexCount; ++i) {
        for (int j = 0; j < vertexCount; ++j) {
            if (adjMatrix[i][j]) {
                rateList[i]++;
            }
        }
    }
}

void GC_Solver::colorGraph() {
    rateVertices();
    int color = 0;

    while (std::any_of(colored.begin(), colored.end(), [](bool c) { return !c; })) {
        colorVertex(color++);
    }

    std::cout << "Graph fully colored" << std::endl;
}

void GC_Solver::colorVertex(int color) {
    int maxDegree = -1, maxVertex = -1;
    for (int i = 0; i < vertexCount; ++i) {
        if (!colored[i] && rateList[i] > maxDegree) {
            maxDegree = rateList[i];
            maxVertex = i;
        }
    }

    if (maxVertex == -1) return;

    colors[maxVertex] = color;
    colored[maxVertex] = true;

    for (int i = 0; i < vertexCount; ++i) {
        if (!adjMatrix[maxVertex][i] && maxVertex != i && !colored[i]) {
            bool conflict = false;
            for (int j = 0; j < vertexCount; ++j) {
                if (adjMatrix[i][j] && colors[j] == color) {
                    conflict = true;
                    break;
                }
            }
            if (!conflict) {
                colors[i] = color;
                colored[i] = true;
            }
        }
    }
}

void GC_Solver::printColors() const {
    for (int i = 0; i < vertexCount; ++i) {
        std::cout << "Vertex " << i << " : color " << colors[i] << std::endl;
    }
}

void GC_Solver::writeToFile() const {
    std::ofstream outFile("output.txt");
    int colorCount = countColors();
    outFile << vertexCount << " " << colorCount << std::endl;

    for (int i = 0; i < vertexCount; ++i) {
        outFile << i << " " << colors[i] << std::endl;
    }
    std::cout<<"The answer is in the output.txt"<<std::endl;
}

int GC_Solver::countColors() const {
    std::set<int> uniqueColors(colors.begin(), colors.end());
    return uniqueColors.size();
}
