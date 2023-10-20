var buildAdjanceyMatrix = function (graph) {
    var twoD = new Array(graph.length);
    for (var i = 0; i < twoD.length; i++) {
        twoD[i] = new Array(graph.length);
    }
    return twoD;
};
var floydWarShall = function (graph, nv) {
    var matrix = buildAdjanceyMatrix(graph);
    for (var k = 0; k < nv; k++) {
        for (var i = 0; i < nv; i++) {
            for (var j = 0; j < nv; j++) {
                if (k == 0) {
                    matrix[i][j] = graph[i][j];
                }
                else {
                    matrix[i][j] = Math.min(matrix[i][k] + matrix[k][j], matrix[i][j]);
                }
            }
        }
    }
    return matrix;
};
console.log(floydWarShall([
    [0, 5, Infinity, 10],
    [Infinity, 0, 3, Infinity],
    [Infinity, Infinity, 0, 1],
    [Infinity, Infinity, Infinity, 0],
], 4));
