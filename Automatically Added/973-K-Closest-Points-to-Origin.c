/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
// Function to calculate the Euclidean distance from origin
int euclideanDistance(int* point) {
    return point[0] * point[0] + point[1] * point[1]; 
}
// Comparator function for qsort
int compare(const void* a, const void* b) {
    int distA = euclideanDistance(*(int**)a);
    int distB = euclideanDistance(*(int**)b);
    return distA - distB;  
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes) {
    *returnColumnSizes = (int*)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    if(pointsSize <= k ){
        *returnSize = pointsSize;
        return points;
    }

    qsort(points,pointsSize, sizeof(int*),compare);

    *returnSize = k;
    return points;
}