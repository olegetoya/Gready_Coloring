fid = fopen('data.txt', 'r');
if fid == -1
    error('Unable to open the file.');
end

numVertices = fscanf(fid, '%d', 1);
numEdges = fscanf(fid, '%d', 1);

adjMatrix = zeros(numVertices);


for i = 1:numEdges
    edge = fscanf(fid, '%d %d', [1, 2]);
    edge = edge + 1;
    adjMatrix(edge(1), edge(2)) = 1;
    adjMatrix(edge(2), edge(1)) = 1;
end

fclose(fid);

fid = fopen('output.txt', 'r');
if fid == -1
    error('Unable to open output file.');
end

numVerticesColor = fscanf(fid, '%d', 1);
numColors = fscanf(fid, '%d', 1);

vertexColors = zeros(numVerticesColor, 1);

for i = 1:numVerticesColor
    data = fscanf(fid, '%d %d', [1, 2]);
    vertexColors(data(1)+1) = data(2);
end

fclose(fid);

theta = linspace(0, 2*pi, numVertices+1);
x = cos(theta(1:end-1));
y = sin(theta(1:end-1));
coords = [x' y'];

figure;
gplot(adjMatrix, coords, 'k-o');
hold on;

scatter(coords(:,1), coords(:,2), 100, vertexColors, 'filled');
colormap(jet(numColors));
colorbar;

for i = 1:numVertices
    text(coords(i,1), coords(i,2), sprintf(' %d', i-1), 'FontSize', 12, 'Color', 'white');
end

title('Graph Visualization with Vertex Coloring');
xlabel('X-axis');
ylabel('Y-axis');
grid on;
hold off;

