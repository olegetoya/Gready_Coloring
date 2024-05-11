#include "GC_Parser.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

GC_Parser::GC_Parser(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    std::string line;
    std::getline(file, line);
    std::stringstream ss(line);
    int edgeCount;

    ss >> vertexCount >> edgeCount;

    while (std::getline(file, line)) {
        int start, end;
        std::stringstream edgeStream(line);
        edgeStream >> start >> end;
        edges.push_back({start, end});
    }
}

int GC_Parser::getVertexCount() const {
    return vertexCount;
}

const std::vector<GC_Parser::Edge>& GC_Parser::getEdges() const {
    return edges;
}
