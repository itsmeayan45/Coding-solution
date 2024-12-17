if (n == 0) return 0;

    int maxProduct = arr[0];
    int minProduct = arr[0];
    int result = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0) {
            
            int temp = maxProduct;
            maxProduct = minProduct;
            minProduct = temp;
        }

        
        maxProduct = (arr[i] > maxProduct * arr[i]) ? arr[i] : maxProduct * arr[i];
        minProduct = (arr[i] < minProduct * arr[i]) ? arr[i] : minProduct * arr[i];

        
        if (maxProduct > result) {
            result = maxProduct;
        }
    }

    return result;