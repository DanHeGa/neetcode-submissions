class Solution {
public:
    void print(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                cout << matrix[i][j] << ", ";
            }
            cout << endl;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mid;
        if (n % 2 == 0) {
            mid = n / 2 - 1;
        } else {
            mid = n / 2;
        }

        //inverse input matrix
        for (int i = 0; i <= mid; i++){ 
            vector<int> aux = matrix[i];
            matrix[i] = matrix[n - i - 1];
            matrix[n - i - 1] = aux;
        }

        cout << "Initial inversion" << endl;
        print(matrix);

        //transpose inverted matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int aux = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = aux;
            }
        }

        cout << "Transposed matrix" << endl;
        print(matrix);
    }
};
