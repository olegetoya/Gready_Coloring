#ifndef GC_SOLVER_H
#define GC_SOLVER_H

#include <vector>

class GC_Solver {
public:
    GC_Solver(int vertexCount, const std::vector<std::pair<int, int>>& edges);
    void colorGraph();
    void printColors() const;
    void writeToFile() const;

private:
    int vertexCount;
    std::vector<std::vector<int>> adjMatrix;
    std::vector<int> colors;
    std::vector<int> rateList;
    std::vector<bool> colored;

    void rateVertices();
    void colorVertex(int color);
    int countColors() const;
};

#endif
