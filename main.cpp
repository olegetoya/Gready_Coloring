#include <iostream>
#include "GC_Parser.h"
#include "GC_Solver.h"

int main() {
    std::string filename = "data.txt";

    try {
        GC_Parser parser(filename);
        int vertexCount = parser.getVertexCount();
        const auto& edges = parser.getEdges();

        std::vector<std::pair<int, int>> formattedEdges;
        for (const auto& edge : edges) {
            formattedEdges.push_back({edge.start, edge.end});
        }
        GC_Solver solver(vertexCount, formattedEdges);
        solver.colorGraph();
        //solver.printColors(); //to print in console
        solver.writeToFile();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

