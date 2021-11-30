function multiplyMatrixes(matrixA, matrixB) {
  let rowsA = matrixA.length,
      colsA = matrixA[0].length,
      colsB = matrixB[0].length,
      matrixC = new Array(rowsA)

  for (let i = 0; i < rowsA; i++) {
    matrixC[i] = new Array(colsB)
    for (let j = 0; j < colsB; j++) {
      matrixC[i][j] = 0;
      for (let k = 0; k < colsA; k++) {
        matrixC[i][j] += matrixA[i][k] * matrixB[k][j]
      }
    }
  }

  return matrixC
}

const matrixA = [[1, 2], [3, 4], [5, 6], [7, 8]],
      matrixB = [[1, 2, 3], [4, 5, 6]]

const matrixC = multiplyMatrixes(matrixA, matrixB)
console.log(matrixC)