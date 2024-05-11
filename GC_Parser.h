#ifndef GC_PARSER_H
#define GC_PARSER_H

#include <vector>
#include <string>

class GC_Parser {
public:
    struct Edge {
        int start;
        int end;
    };

    GC_Parser(const std::string& filename);
    int getVertexCount() const;
    const std::vector<Edge>& getEdges() const;

private:
    int vertexCount;
    std::vector<Edge> edges;
};

#endif
