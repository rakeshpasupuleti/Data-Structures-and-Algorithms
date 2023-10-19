if (umap.find(key) != umap.end())
        return umap[key];

    // Recursively explore paths in four possible directions and memoize the result.
    long long path1 = count_paths(matrix, row1 + 1, col1, row2 - 1, col2) % mod;
    long long path2 = count_paths(matrix, row1 + 1, col1, row2, col2 - 1) % mod;
    long long path3 = count_paths(matrix, row1, col1 + 1, row2 - 1, col2) % mod;
    long long path4 = count_paths(matrix, row1, col1 + 1, row2, col2 - 1) % mod;
